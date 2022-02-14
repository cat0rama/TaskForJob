cmake_minimum_required(VERSION 3.12)

project(Build_libs)

set(IMGUI_INCLUDES
	imgui/imgui.h
	imgui/backends/imgui_impl_glfw.h
	imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
	imgui/imgui.cpp
	imgui/backends/imgui_impl_glfw.cpp
	imgui/backends/imgui_impl_opengl3.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp
	imgui/imgui_demo.cpp
)

add_library(${PROJECT_NAME} STATIC
	${IMGUI_INCLUDES}
	${IMGUI_SOURCES}
)

add_subdirectory(glfw)

add_subdirectory(tinyxml2)

add_subdirectory(spdlog)

add_subdirectory(glad)

target_include_directories(${PROJECT_NAME} PUBLIC imgui)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad)