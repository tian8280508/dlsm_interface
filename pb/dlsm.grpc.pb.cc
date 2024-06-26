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
namespace store {

static const char* dLSMService_method_names[] = {
  "/store.dLSMService/SetKey",
  "/store.dLSMService/GetKey",
  "/store.dLSMService/DeleteKey",
};

std::unique_ptr< dLSMService::Stub> dLSMService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< dLSMService::Stub> stub(new dLSMService::Stub(channel, options));
  return stub;
}

dLSMService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SetKey_(dLSMService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetKey_(dLSMService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DeleteKey_(dLSMService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status dLSMService::Stub::SetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::store::SetKeyResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::store::GetKeyRequest, ::store::SetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SetKey_, context, request, response);
}

void dLSMService::Stub::async::SetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::SetKeyResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::store::GetKeyRequest, ::store::SetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetKey_, context, request, response, std::move(f));
}

void dLSMService::Stub::async::SetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::SetKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetKey_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::store::SetKeyResponse>* dLSMService::Stub::PrepareAsyncSetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::store::SetKeyResponse, ::store::GetKeyRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SetKey_, context, request);
}

::grpc::ClientAsyncResponseReader< ::store::SetKeyResponse>* dLSMService::Stub::AsyncSetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSetKeyRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status dLSMService::Stub::GetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::store::GetKeyResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::store::GetKeyRequest, ::store::GetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetKey_, context, request, response);
}

void dLSMService::Stub::async::GetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::GetKeyResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::store::GetKeyRequest, ::store::GetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetKey_, context, request, response, std::move(f));
}

void dLSMService::Stub::async::GetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::GetKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetKey_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::store::GetKeyResponse>* dLSMService::Stub::PrepareAsyncGetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::store::GetKeyResponse, ::store::GetKeyRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetKey_, context, request);
}

::grpc::ClientAsyncResponseReader< ::store::GetKeyResponse>* dLSMService::Stub::AsyncGetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetKeyRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status dLSMService::Stub::DeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::store::DeleteKeyResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::store::DeleteKeyRequest, ::store::DeleteKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_DeleteKey_, context, request, response);
}

void dLSMService::Stub::async::DeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest* request, ::store::DeleteKeyResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::store::DeleteKeyRequest, ::store::DeleteKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeleteKey_, context, request, response, std::move(f));
}

void dLSMService::Stub::async::DeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest* request, ::store::DeleteKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeleteKey_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::store::DeleteKeyResponse>* dLSMService::Stub::PrepareAsyncDeleteKeyRaw(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::store::DeleteKeyResponse, ::store::DeleteKeyRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_DeleteKey_, context, request);
}

::grpc::ClientAsyncResponseReader< ::store::DeleteKeyResponse>* dLSMService::Stub::AsyncDeleteKeyRaw(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeleteKeyRaw(context, request, cq);
  result->StartCall();
  return result;
}

dLSMService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      dLSMService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< dLSMService::Service, ::store::GetKeyRequest, ::store::SetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](dLSMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::store::GetKeyRequest* req,
             ::store::SetKeyResponse* resp) {
               return service->SetKey(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      dLSMService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< dLSMService::Service, ::store::GetKeyRequest, ::store::GetKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](dLSMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::store::GetKeyRequest* req,
             ::store::GetKeyResponse* resp) {
               return service->GetKey(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      dLSMService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< dLSMService::Service, ::store::DeleteKeyRequest, ::store::DeleteKeyResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](dLSMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::store::DeleteKeyRequest* req,
             ::store::DeleteKeyResponse* resp) {
               return service->DeleteKey(ctx, req, resp);
             }, this)));
}

dLSMService::Service::~Service() {
}

::grpc::Status dLSMService::Service::SetKey(::grpc::ServerContext* context, const ::store::GetKeyRequest* request, ::store::SetKeyResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status dLSMService::Service::GetKey(::grpc::ServerContext* context, const ::store::GetKeyRequest* request, ::store::GetKeyResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status dLSMService::Service::DeleteKey(::grpc::ServerContext* context, const ::store::DeleteKeyRequest* request, ::store::DeleteKeyResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace store

