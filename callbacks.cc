#include <node.h>

namespace demo
{

  using v8::Context;
  using v8::Function;
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Null;
  using v8::Number;
  using v8::Object;
  using v8::Value;

  void Callback(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();
    Local<Function> cb = Local<Function>::Cast(args[0]);

    const unsigned argsCont = 2;
    Local<Value> argsValue[argsCont]{
        Number::New(isolate, 10),
        Number::New(isolate, 20),
    };

    cb->Call(context, Null(isolate), argsCont, argsValue).ToLocalChecked();
  }

  void Init(Local<Object> exports)
  {
    NODE_SET_METHOD(exports, "callback", Callback);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}