#include <string>
using namespace std;

#include "napi.h"

Napi::Value foo(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "Wrong type of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    string ret = info[0].As<Napi::String>().Utf8Value() + "from napi-mingw64!";

    return Napi::String::New(env, ret);
}


Napi::Object napiInit(Napi::Env env, Napi::Object exports) {
    exports.Set("foo", Napi::Function::New(env, foo));
    return exports;
}

NODE_API_MODULE(NAPI_TEST, napiInit)
