cmake_minimum_required(VERSION 3.24)
project(PhoneNumberManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(PhoneNumberManager cmake-build-debug/BaseList.cpp cmake-build-debug/BaseList.h cmake-build-debug/study.cpp cmake-build-debug/study.h cmake-build-debug/MainClass.cpp cmake-build-debug/tools.cpp cmake-build-debug/tools.h cmake-build-debug/MainClass.h cmake-build-debug/main.cpp)
