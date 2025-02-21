// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: dlsm.proto

#include "dlsm.pb.h"
#include "dlsm.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace dlsm {

static const char* dLSMService_method_names[] = {
  "/dlsm.dLSMService/SetKey",
  "/dlsm.dLSMService/WriteBatch",
  "/dlsm.dLSMService/GetKey",
};

std::unique_ptr< dLSMService::Stub> dLSMService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< dLSMService::Stub> stub(new dLSMService::Stub(channel, options));
  return stub;
}

dLSMService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SetKey_(dLSMService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_WriteBatch_(dLSMService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetKey_(dLSMService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status dLSMService::Stub::SetKey(::grpc::ClientContext* context, const ::dlsm::SetKeyRequest& request, ::dlsm::SetKeyResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::dlsm::SetKeyRequest, ::dlsm::SetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SetKey_, context, request, response);
}

void dLSMService::Stub::async::SetKey(::grpc::ClientContext* context, const ::dlsm::SetKeyRequest* request, ::dlsm::SetKeyResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::dlsm::SetKeyRequest, ::dlsm::SetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetKey_, context, request, response, std::move(f));
}

void dLSMService::Stub::async::SetKey(::grpc::ClientContext* context, const ::dlsm::SetKeyRequest* request, ::dlsm::SetKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetKey_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::dlsm::SetKeyResponse>* dLSMService::Stub::PrepareAsyncSetKeyRaw(::grpc::ClientContext* context, const ::dlsm::SetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::dlsm::SetKeyResponse, ::dlsm::SetKeyRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SetKey_, context, request);
}

::grpc::ClientAsyncResponseReader< ::dlsm::SetKeyResponse>* dLSMService::Stub::AsyncSetKeyRaw(::grpc::ClientContext* context, const ::dlsm::SetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSetKeyRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status dLSMService::Stub::WriteBatch(::grpc::ClientContext* context, const ::dlsm::WriteBatchRequest& request, ::dlsm::WriteBatchResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::dlsm::WriteBatchRequest, ::dlsm::WriteBatchResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_WriteBatch_, context, request, response);
}

void dLSMService::Stub::async::WriteBatch(::grpc::ClientContext* context, const ::dlsm::WriteBatchRequest* request, ::dlsm::WriteBatchResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::dlsm::WriteBatchRequest, ::dlsm::WriteBatchResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_WriteBatch_, context, request, response, std::move(f));
}

void dLSMService::Stub::async::WriteBatch(::grpc::ClientContext* context, const ::dlsm::WriteBatchRequest* request, ::dlsm::WriteBatchResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_WriteBatch_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::dlsm::WriteBatchResponse>* dLSMService::Stub::PrepareAsyncWriteBatchRaw(::grpc::ClientContext* context, const ::dlsm::WriteBatchRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::dlsm::WriteBatchResponse, ::dlsm::WriteBatchRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_WriteBatch_, context, request);
}

::grpc::ClientAsyncResponseReader< ::dlsm::WriteBatchResponse>* dLSMService::Stub::AsyncWriteBatchRaw(::grpc::ClientContext* context, const ::dlsm::WriteBatchRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncWriteBatchRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status dLSMService::Stub::GetKey(::grpc::ClientContext* context, const ::dlsm::GetKeyRequest& request, ::dlsm::GetKeyResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::dlsm::GetKeyRequest, ::dlsm::GetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetKey_, context, request, response);
}

void dLSMService::Stub::async::GetKey(::grpc::ClientContext* context, const ::dlsm::GetKeyRequest* request, ::dlsm::GetKeyResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::dlsm::GetKeyRequest, ::dlsm::GetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetKey_, context, request, response, std::move(f));
}

void dLSMService::Stub::async::GetKey(::grpc::ClientContext* context, const ::dlsm::GetKeyRequest* request, ::dlsm::GetKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetKey_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::dlsm::GetKeyResponse>* dLSMService::Stub::PrepareAsyncGetKeyRaw(::grpc::ClientContext* context, const ::dlsm::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::dlsm::GetKeyResponse, ::dlsm::GetKeyRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetKey_, context, request);
}

::grpc::ClientAsyncResponseReader< ::dlsm::GetKeyResponse>* dLSMService::Stub::AsyncGetKeyRaw(::grpc::ClientContext* context, const ::dlsm::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetKeyRaw(context, request, cq);
  result->StartCall();
  return result;
}

dLSMService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      dLSMService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< dLSMService::Service, ::dlsm::SetKeyRequest, ::dlsm::SetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](dLSMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::dlsm::SetKeyRequest* req,
             ::dlsm::SetKeyResponse* resp) {
               return service->SetKey(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      dLSMService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< dLSMService::Service, ::dlsm::WriteBatchRequest, ::dlsm::WriteBatchResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](dLSMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::dlsm::WriteBatchRequest* req,
             ::dlsm::WriteBatchResponse* resp) {
               return service->WriteBatch(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      dLSMService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< dLSMService::Service, ::dlsm::GetKeyRequest, ::dlsm::GetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](dLSMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::dlsm::GetKeyRequest* req,
             ::dlsm::GetKeyResponse* resp) {
               return service->GetKey(ctx, req, resp);
             }, this)));
}

dLSMService::Service::~Service() {
}

::grpc::Status dLSMService::Service::SetKey(::grpc::ServerContext* context, const ::dlsm::SetKeyRequest* request, ::dlsm::SetKeyResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status dLSMService::Service::WriteBatch(::grpc::ServerContext* context, const ::dlsm::WriteBatchRequest* request, ::dlsm::WriteBatchResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status dLSMService::Service::GetKey(::grpc::ServerContext* context, const ::dlsm::GetKeyRequest* request, ::dlsm::GetKeyResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace dlsm

