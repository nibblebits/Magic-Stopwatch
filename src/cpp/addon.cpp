#include <nan.h>

void Increment(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  // Validate the number of arguments.
  if (info.Length() < 1) {
    Nan::ThrowTypeError("Arity mismatch");
    return;
  }

  // Validate the type of the first argument.
  if (!info[0]->IsNumber()) {
    Nan::ThrowTypeError("Argument must be a number");
    return;
  }

  // Get the number value of the first argument. A JavaScript `number` will be a `double` in C++.

  // Allocate a new local variable of type "number" in the JavaScript VM for our return value.
  v8::Local<v8::Number> num = Nan::New(38373);

  // Set the return value.
  info.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::FunctionTemplate> incrementFunc = Nan::New<v8::FunctionTemplate>(Increment);
  Nan::Set(exports, Nan::New("increment").ToLocalChecked(),
               Nan::GetFunction(incrementFunc).ToLocalChecked());
}

NODE_MODULE(addon, Init)
