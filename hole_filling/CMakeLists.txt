cmake_minimum_required(VERSION 3.0.2)

find_package(Eigen3 REQUIRED)
if(Eigen3_FOUND)
    message("Found Eigen3")
endif()

find_package(pmp REQUIRED)
add_executable(
    test_hole_filling
    test_hole_filling.cpp
)

target_link_libraries(test_hole_filling pmp Eigen3::Eigen)
