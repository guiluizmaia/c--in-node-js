// addon.cc
#include <node.h>

namespace demo {

using v8::Context;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;


void CreateObject(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();

  Local<Object> inputObj = args[0]->ToObject(context).ToLocalChecked();


  Local<Object> obj = Object::New(isolate);
  obj->Set(context, String::NewFromUtf8(isolate, "Name").ToLocalChecked(), 
    inputObj->Get(context, String::NewFromUtf8(isolate, "name").ToLocalChecked()).ToLocalChecked()).FromJust();

  obj->Set(context, String::NewFromUtf8(isolate, "CompleteName").ToLocalChecked(), 
    inputObj->Get(context, String::NewFromUtf8(isolate, "completeName").ToLocalChecked()).ToLocalChecked()).FromJust();

  obj->Set(context, String::NewFromUtf8(isolate, "Age").ToLocalChecked(), 
    inputObj->Get(context, String::NewFromUtf8(isolate, "age").ToLocalChecked()).ToLocalChecked()).FromJust();

  args.GetReturnValue().Set(obj);
}

void Init(Local<Object> exports, Local<Object> module) {
  NODE_SET_METHOD(module, "exports", CreateObject);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  