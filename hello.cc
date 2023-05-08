// addon.cc
#include <node.h>

namespace demo {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;
using std::begin;
using std::end;

void Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Wrong number of arguments(minimum 2)").ToLocalChecked()));
    return;
  }

  double value = 0;

  for (int i = 0; i < args.Length(); i++) {
    if(!args[i]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate,
                                "All arguments should be a number").ToLocalChecked()));
        return;
    }

    value += args[i].As<Number>()->Value();

  }

  Local<Number> num = Number::New(isolate, value);

  args.GetReturnValue().Set(num);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "add", Add);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

} 