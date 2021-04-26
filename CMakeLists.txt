cmake_minimum_required(VERSION 3.17)
project(PSS_HW_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(PSS_HW_4 main.cpp PassengerGateway.cpp PassengerGateway.h DriverGateway.cpp DriverGateway.h MainGateway.cpp MainGateway.h Admin.cpp Admin.h Car.cpp Car.h)