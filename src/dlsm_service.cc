#include "dlsm_service.h"
#include "dlsm.pb.h"
#include <cstdlib>
#include <grpcpp/grpcpp.h>
#include <memory>
#include <string>

using dlsm::DeleteKeyRequest;
using dlsm::DeleteKeyResponse;
using dlsm::dLSMService;
using dlsm::GetKeyRequest;
using dlsm::GetKeyResponse;
using dlsm::SetKeyRequest;
using dlsm::SetKeyResponse;
using dlsm::WriteBatchRequest;
using dlsm::WriteBatchResponse;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

Status dLSMServiceImpl::SetKey(ServerContext *context,
                               const SetKeyRequest *request,
                               SetKeyResponse *response) {
  const std::string &key = request->key();
  const std::string &val = request->value();
  int code = db_->setKey(key, val);
  if (code == 0) {
    response->set_code(0); // 0 means success
    response->set_message("Success");
  } else {
    response->set_code(1); // 1 means error
    response->set_message("Set failed");
  }
  return Status::OK;
}

Status dLSMServiceImpl::GetKey(ServerContext *context,
                               const GetKeyRequest *request,
                               GetKeyResponse *response) {
  const std::string &key = request->key();
  std::string res;
  int code = db_->getKey(key, res);
  if (code == 0) {
    response->set_value(res);
    response->set_code(0); // 0 means success
    response->set_message("Success");
  } else {
    response->set_code(1); // 1 means error
    response->set_message("Key not found");
  }
  return Status::OK;
}

Status dLSMServiceImpl::WriteBatch(ServerContext *context,
                                   const WriteBatchRequest *request,
                                   WriteBatchResponse *response) {
  auto kvpairs = request->kvpairs();
  std::string key_storage;
  std::string value_storage;

  TimberSaw::Slice key_list(key_storage);
  TimberSaw::Slice value_list(value_storage);
  for (auto &item : kvpairs) {
    // 提取键和值
    const std::string &key = item.key();
    const std::string &value = item.value();

    // 将键拼接到 key_storage
    key_storage.append(key);

    // 将值拼接到 value_storage
    value_storage.append(value);

    // 更新 Slices 的引用
    key_list.Reset(key_storage.data(), key_storage.size());
    value_list.Reset(value_storage.data(), value_storage.size());
  }
  // printf("keys: %s", key_list.ToString().c_str());
  // printf("vals: %s", value_list.ToString().c_str());
  // return Status::OK;
  int code = db_->writeBatch(key_list, value_list);
  if (code == 0) {
    response->set_code(0); // 0 means success
    response->set_message("Success");
  } else {
    response->set_code(1); // 1 means error
    response->set_message("WriteBatch failed");
  }
  return Status::OK;
}

void RunServer(dlsmdb::db *db) {
  std::string server_address("unix:/var/tmp/socket"); // unix domain socket
  dLSMServiceImpl service(db);

  ServerBuilder builder;
  builder.AddListeningPort(server_address,
                           grpc::experimental::LocalServerCredentials(UDS));
  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());
  printf("Server listening on %s", server_address.c_str());
  server->Wait();
}