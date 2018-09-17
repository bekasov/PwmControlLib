cmake_minimum_required(VERSION 3.7)
project(Pwm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pwm
        main.cpp
        SysClassPwmConfigProvider.cpp)