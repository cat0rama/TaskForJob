cmake_minimum_required(VERSION 3.12)

project(Univer)

add_subdirectory(vendor)

add_subdirectory(src)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Application) #start project