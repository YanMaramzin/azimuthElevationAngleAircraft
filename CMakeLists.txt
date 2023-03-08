cmake_minimum_required(VERSION 3.5)

project(azimuthElevationAngleAircraft LANGUAGES CXX)



if(UNITTEST)
	add_subdirectory(googletests/)
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
add_executable(${PROJECT_NAME} main.cpp)



