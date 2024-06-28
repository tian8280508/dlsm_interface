#ifndef DLSM_SERVICE_H
#define DLSM_SERVICE_H
#include "db_op.h"
#include "dlsm.grpc.pb.h"
#include "dlsm.pb.h"
#include <grpcpp/grpcpp.h>

class dLSMServiceImpl final : public dlsm::dLSMService::Service {
public:
  explicit dLSMServiceImpl(dlsmdb::db *db) : db_(db){};
  grpc::Status SetKey(grpc::ServerContext *context,
                      const dlsm::SetKeyRequest *request,
                      dlsm::SetKeyResponse *response);

  grpc::Status GetKey(grpc::ServerContext *context,
                      const dlsm::GetKeyRequest *request,
                      dlsm::GetKeyResponse *response) override;

private:
  dlsmdb::db *db_;
};

void RunServer(dlsmdb::db *db);
#endif