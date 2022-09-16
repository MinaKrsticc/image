################################################################################
####################### Do not modify this file. ###############################
################################################################################

project(initial_matrix)
cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/src)

# create library " imageLib "
add_library (imageLib src/igg_image/image.cpp)
# add executable main
add_executable (main src/igg_image/main.cpp)


find_library (SOME_LIB
 NAMES libio_tools.so
 PATHS "/home/syrmia/modern c++/domaci/igg_image/lib")
target_link_libraries (imageLib ${SOME_LIB})

target_link_libraries (main imageLib)

add_subdirectory(src)
#enable_testing()
#add_subdirectory(tests)

################################################################################
####################### Do not modify this file. ###############################
################################################################################
