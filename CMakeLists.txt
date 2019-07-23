cmake_minimum_required(VERSION 3.6)
project(LibSys)

set(CMAKE_CXX_STANDARD 14)

add_library(LibSys library.cpp library.h src/cpp/Book.cpp src/h/Book.h src/h/BorrowRecord.h src/cpp/BorrowRecord.cpp src/h/DB.h src/cpp/DB.cpp src/h/Manager.h src/cpp/Manager.cpp src/h/User.h src/cpp/User.cpp src/h/TimeUtil.h src/cpp/TimeUtil.cpp src/cpp/Student.cpp src/h/Student.h src/main.cpp)