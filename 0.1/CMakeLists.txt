cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(SampleGroup_Project)

find_package(GDAL)

aux_source_directory(. DIR_SRCS)

include_directories(${GDAL_INCLUDE_DIRS})
link_directories(${GDAL_LIBRARY_DIRS})
add_definitions(${GDAL_DEFINITIONS})

add_executable (SampleGroup ${DIR_SRCS})
target_link_libraries (SampleGroup ${GDAL_LIBRARIES})