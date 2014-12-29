
cmake_minimum_required (VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
  
find_package(OpenCV REQUIRED)

add_executable(obj_detection obj_detection.cpp)

target_link_libraries(obj_detection ${OpenCV_LIBS})

install(TARGETS obj_detection DESTINATION bin)
