cmake_minimum_required(VERSION 3.12)
project(Pwm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pwm
        main.cpp
        SysClassPwmConfigProvider.cpp)