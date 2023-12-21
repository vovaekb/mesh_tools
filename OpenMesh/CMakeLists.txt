project (AsteroGen CXX C)
cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

list (APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../.././cmake)

FIND_PACKAGE(OpenMesh REQUIRED)
link_directories(${OPENMESH_LIBRARY_DIR})
include_directories(${OPENMESH_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/vendor)

add_executable(test_app test_app.cpp)
target_link_libraries(test_app ${OPENMESH_LIBRARIES} glfw) 
