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
  db_->setKey(key, val);
  response->set_code(0); // 0 means success
  response->set_message("Success");
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
  // TODO implement this
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