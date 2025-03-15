cmake_minimum_required(VERSION 3.13)
project(napi-mingw64)

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

set(pwd ${CMAKE_CURRENT_LIST_DIR})

add_library(${CMAKE_PROJECT_NAME} MODULE main.cpp)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES SUFFIX ".node" PREFIX "")
target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC NODE_ADDON_API_DISABLE_DEPRECATED)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${pwd}/include")
target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC NODE_ADDON_API_DISABLE_DEPRECATED)

if(WIN32)
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC "-fno-keep-inline-dllexport" "-fexceptions" "-mthreads")
    target_link_options(${CMAKE_PROJECT_NAME} PUBLIC "-Wl,--exclude-all-symbols")
    target_link_libraries(lib-napi INTERFACE "-L${pwd}/napi/lib" "-lnode")
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE lib-napi)
endif()

add_custom_target(copy-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${pwd}/test.js" "${CMAKE_CURRENT_BINARY_DIR}"
)

add_custom_target(other-files SOURCES
    "${pwd}/test.js"
    "${pwd}/README.md"
)


