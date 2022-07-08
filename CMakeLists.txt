cmake_minimum_required(VERSION 3.16)
project(EclassSystemProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(EclassSystemProject main.cpp classFiles/Course.cpp classHeaders/Course.h classFiles/Person.cpp classHeaders/Person.h classFiles/Student.cpp classHeaders/Student.h classFiles/Professor.cpp classHeaders/Professor.h classFiles/EClass.cpp classHeaders/EClass.h classFiles/User.cpp classHeaders/User.h)
