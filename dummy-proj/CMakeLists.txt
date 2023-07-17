cmake_minimum_required(VERSION 3.22)
project(dummy_proj)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(bookshop
    main.cpp
    book.h
    book.cpp
    order.h
    order.cpp
    store.h
    store.cpp
)

# Python bindings
find_package(pybind11 CONFIG REQUIRED)
pybind11_add_module(
    dummy-py MODULE
    python_bindings.cpp
    book.h
    book.cpp
    order.h
    order.cpp
    store.h
    store.cpp
)
