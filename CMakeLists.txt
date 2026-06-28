cmake_minimum_required(VERSION 4.0)
project(db_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(db_project main.cpp
        staff_ui.cpp
        menu.h
        staff_ui.h
        menu.cpp
        patient_ui.cpp
        patient_ui.h
        data.cpp
        data.h
)
