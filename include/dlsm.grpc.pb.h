// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: dlsm.proto
#ifndef GRPC_dlsm_2eproto__INCLUDED
#define GRPC_dlsm_2eproto__INCLUDED

#include "dlsm.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace store {

class dLSMService final {
 public:
  static constexpr char const* service_full_name() {
    return "store.dLSMService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status SetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::store::SetKeyResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::SetKeyResponse>> AsyncSetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::SetKeyResponse>>(AsyncSetKeyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::SetKeyResponse>> PrepareAsyncSetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::SetKeyResponse>>(PrepareAsyncSetKeyRaw(context, request, cq));
    }
    virtual ::grpc::Status GetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::store::GetKeyResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::GetKeyResponse>> AsyncGetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::GetKeyResponse>>(AsyncGetKeyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::GetKeyResponse>> PrepareAsyncGetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::GetKeyResponse>>(PrepareAsyncGetKeyRaw(context, request, cq));
    }
    virtual ::grpc::Status DeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::store::DeleteKeyResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::DeleteKeyResponse>> AsyncDeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::DeleteKeyResponse>>(AsyncDeleteKeyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::DeleteKeyResponse>> PrepareAsyncDeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::store::DeleteKeyResponse>>(PrepareAsyncDeleteKeyRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void SetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::SetKeyResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::SetKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void GetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::GetKeyResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void GetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::GetKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void DeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest* request, ::store::DeleteKeyResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void DeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest* request, ::store::DeleteKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::store::SetKeyResponse>* AsyncSetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::store::SetKeyResponse>* PrepareAsyncSetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::store::GetKeyResponse>* AsyncGetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::store::GetKeyResponse>* PrepareAsyncGetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::store::DeleteKeyResponse>* AsyncDeleteKeyRaw(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::store::DeleteKeyResponse>* PrepareAsyncDeleteKeyRaw(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status SetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::store::SetKeyResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::SetKeyResponse>> AsyncSetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::SetKeyResponse>>(AsyncSetKeyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::SetKeyResponse>> PrepareAsyncSetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::SetKeyResponse>>(PrepareAsyncSetKeyRaw(context, request, cq));
    }
    ::grpc::Status GetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::store::GetKeyResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::GetKeyResponse>> AsyncGetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::GetKeyResponse>>(AsyncGetKeyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::GetKeyResponse>> PrepareAsyncGetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::GetKeyResponse>>(PrepareAsyncGetKeyRaw(context, request, cq));
    }
    ::grpc::Status DeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::store::DeleteKeyResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::DeleteKeyResponse>> AsyncDeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::DeleteKeyResponse>>(AsyncDeleteKeyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::DeleteKeyResponse>> PrepareAsyncDeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::store::DeleteKeyResponse>>(PrepareAsyncDeleteKeyRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void SetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::SetKeyResponse* response, std::function<void(::grpc::Status)>) override;
      void SetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::SetKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void GetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::GetKeyResponse* response, std::function<void(::grpc::Status)>) override;
      void GetKey(::grpc::ClientContext* context, const ::store::GetKeyRequest* request, ::store::GetKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void DeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest* request, ::store::DeleteKeyResponse* response, std::function<void(::grpc::Status)>) override;
      void DeleteKey(::grpc::ClientContext* context, const ::store::DeleteKeyRequest* request, ::store::DeleteKeyResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::store::SetKeyResponse>* AsyncSetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::store::SetKeyResponse>* PrepareAsyncSetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::store::GetKeyResponse>* AsyncGetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::store::GetKeyResponse>* PrepareAsyncGetKeyRaw(::grpc::ClientContext* context, const ::store::GetKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::store::DeleteKeyResponse>* AsyncDeleteKeyRaw(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::store::DeleteKeyResponse>* PrepareAsyncDeleteKeyRaw(::grpc::ClientContext* context, const ::store::DeleteKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SetKey_;
    const ::grpc::internal::RpcMethod rpcmethod_GetKey_;
    const ::grpc::internal::RpcMethod rpcmethod_DeleteKey_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status SetKey(::grpc::ServerContext* context, const ::store::GetKeyRequest* request, ::store::SetKeyResponse* response);
    virtual ::grpc::Status GetKey(::grpc::ServerContext* context, const ::store::GetKeyRequest* request, ::store::GetKeyResponse* response);
    virtual ::grpc::Status DeleteKey(::grpc::ServerContext* context, const ::store::DeleteKeyRequest* request, ::store::DeleteKeyResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_SetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SetKey() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::SetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSetKey(::grpc::ServerContext* context, ::store::GetKeyRequest* request, ::grpc::ServerAsyncResponseWriter< ::store::SetKeyResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetKey() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_GetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::GetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetKey(::grpc::ServerContext* context, ::store::GetKeyRequest* request, ::grpc::ServerAsyncResponseWriter< ::store::GetKeyResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_DeleteKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_DeleteKey() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_DeleteKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeleteKey(::grpc::ServerContext* /*context*/, const ::store::DeleteKeyRequest* /*request*/, ::store::DeleteKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDeleteKey(::grpc::ServerContext* context, ::store::DeleteKeyRequest* request, ::grpc::ServerAsyncResponseWriter< ::store::DeleteKeyResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SetKey<WithAsyncMethod_GetKey<WithAsyncMethod_DeleteKey<Service > > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_SetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_SetKey() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::store::GetKeyRequest, ::store::SetKeyResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::store::GetKeyRequest* request, ::store::SetKeyResponse* response) { return this->SetKey(context, request, response); }));}
    void SetMessageAllocatorFor_SetKey(
        ::grpc::MessageAllocator< ::store::GetKeyRequest, ::store::SetKeyResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::store::GetKeyRequest, ::store::SetKeyResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_SetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::SetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SetKey(
      ::grpc::CallbackServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::SetKeyResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_GetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GetKey() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::store::GetKeyRequest, ::store::GetKeyResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::store::GetKeyRequest* request, ::store::GetKeyResponse* response) { return this->GetKey(context, request, response); }));}
    void SetMessageAllocatorFor_GetKey(
        ::grpc::MessageAllocator< ::store::GetKeyRequest, ::store::GetKeyResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::store::GetKeyRequest, ::store::GetKeyResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_GetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::GetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetKey(
      ::grpc::CallbackServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::GetKeyResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_DeleteKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_DeleteKey() {
      ::grpc::Service::MarkMethodCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::store::DeleteKeyRequest, ::store::DeleteKeyResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::store::DeleteKeyRequest* request, ::store::DeleteKeyResponse* response) { return this->DeleteKey(context, request, response); }));}
    void SetMessageAllocatorFor_DeleteKey(
        ::grpc::MessageAllocator< ::store::DeleteKeyRequest, ::store::DeleteKeyResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(2);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::store::DeleteKeyRequest, ::store::DeleteKeyResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_DeleteKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeleteKey(::grpc::ServerContext* /*context*/, const ::store::DeleteKeyRequest* /*request*/, ::store::DeleteKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* DeleteKey(
      ::grpc::CallbackServerContext* /*context*/, const ::store::DeleteKeyRequest* /*request*/, ::store::DeleteKeyResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_SetKey<WithCallbackMethod_GetKey<WithCallbackMethod_DeleteKey<Service > > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_SetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SetKey() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::SetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetKey() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_GetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::GetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_DeleteKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_DeleteKey() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_DeleteKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeleteKey(::grpc::ServerContext* /*context*/, const ::store::DeleteKeyRequest* /*request*/, ::store::DeleteKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_SetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SetKey() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_SetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::SetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSetKey(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetKey() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_GetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::GetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetKey(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_DeleteKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_DeleteKey() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_DeleteKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeleteKey(::grpc::ServerContext* /*context*/, const ::store::DeleteKeyRequest* /*request*/, ::store::DeleteKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDeleteKey(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_SetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_SetKey() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SetKey(context, request, response); }));
    }
    ~WithRawCallbackMethod_SetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::SetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SetKey(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GetKey() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->GetKey(context, request, response); }));
    }
    ~WithRawCallbackMethod_GetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::GetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetKey(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_DeleteKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_DeleteKey() {
      ::grpc::Service::MarkMethodRawCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->DeleteKey(context, request, response); }));
    }
    ~WithRawCallbackMethod_DeleteKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeleteKey(::grpc::ServerContext* /*context*/, const ::store::DeleteKeyRequest* /*request*/, ::store::DeleteKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* DeleteKey(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SetKey() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::store::GetKeyRequest, ::store::SetKeyResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::store::GetKeyRequest, ::store::SetKeyResponse>* streamer) {
                       return this->StreamedSetKey(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::SetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSetKey(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::store::GetKeyRequest,::store::SetKeyResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_GetKey() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::store::GetKeyRequest, ::store::GetKeyResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::store::GetKeyRequest, ::store::GetKeyResponse>* streamer) {
                       return this->StreamedGetKey(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_GetKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetKey(::grpc::ServerContext* /*context*/, const ::store::GetKeyRequest* /*request*/, ::store::GetKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetKey(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::store::GetKeyRequest,::store::GetKeyResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_DeleteKey : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_DeleteKey() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler<
          ::store::DeleteKeyRequest, ::store::DeleteKeyResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::store::DeleteKeyRequest, ::store::DeleteKeyResponse>* streamer) {
                       return this->StreamedDeleteKey(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_DeleteKey() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status DeleteKey(::grpc::ServerContext* /*context*/, const ::store::DeleteKeyRequest* /*request*/, ::store::DeleteKeyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedDeleteKey(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::store::DeleteKeyRequest,::store::DeleteKeyResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SetKey<WithStreamedUnaryMethod_GetKey<WithStreamedUnaryMethod_DeleteKey<Service > > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_SetKey<WithStreamedUnaryMethod_GetKey<WithStreamedUnaryMethod_DeleteKey<Service > > > StreamedService;
};

}  // namespace store


#endif  // GRPC_dlsm_2eproto__INCLUDED
