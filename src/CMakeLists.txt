cmake_minimum_required(VERSION 3.12)

project(Application LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(APPLICATION_INCLUDES
	Application/include/Gui.hpp
	Application/include/Launcher.hpp
	Application/include/Window.hpp
	Application/include/XMLParse.hpp
	Application/include/Log.hpp
	Application/include/Callback.hpp
)

set(APPLICATION_SOURCES
	Application/src/Gui.cpp
	Application/src/Launcher.cpp
	Application/src/Window.cpp
	Application/src/XMLParse.cpp
	Application/src/Callback.cpp
)

add_executable(${PROJECT_NAME}
	${APPLICATION_INCLUDES}
	${APPLICATION_SOURCES}
	Application/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE Application/include)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

target_link_libraries(${PROJECT_NAME} PRIVATE glad)

target_link_libraries(${PROJECT_NAME} PRIVATE tinyxml2)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog)

target_link_libraries(${PROJECT_NAME} PRIVATE Build_libs)