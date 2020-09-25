node-napi-mingw64
=================

template of creating node.js napi add-on using GCC/mingw-w64

this repository can be used as you project git submodule, it will updated regularly

following header files from [node](https://github.com/nodejs/node)
- `js_native_api.h`
- `js_native_api_types.h`
- `node_api.h`
- `node_api_types.h`

following header files from from [node-addon-api](https://github.com/nodejs/node-addon-api)
- `napi.h`
- `napi-inl.h`

how to use
==========

1. build using cmake and it will generate `napi-mingw64.node` file
2. in build folder run `<node_path>/node.exe test.js`
