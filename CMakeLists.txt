# CMake settings
cmake_minimum_required(VERSION 2.8)

# Root project settings
set(ROOT_PROJECT_NAME Jamgine)
project(${ROOT_PROJECT_NAME})

# Find external libraries
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")

find_package(DIRECTX11 REQUIRED)


set(EXTERNAL_INCLUDE_DIRS 
	${DIRECTX11_INCLUDE_DIRS}
)
	
set(EXTERNAL_LIBRARIES
	${DIRECTX11_LIBRARY}
)

message("${EXTERNAL_LIBRARIES}")


# Set global compiler options
#add_definitions(-D_VARIADIC_MAX=10)
add_definitions(-DUNICODE -D_UNICODE)
#add_definitions(-DWIN32_LEAN_AND_MEAN)
#add_definitions(-D_SCL_SECURE_NO_WARNINGS)
# add_definitions(/wd4005)    # Disable macro redefinition warning

# Add sub projects and dependencies.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(${EXTERNAL_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

# Add subdirectories
add_subdirectory(Jamgine)
add_subdirectory(TestGame)

# Copy the runtime dependencies to the output directory when dependency target is built
# TODO: This is hardcoded to the Debug folder. We cannot use a Release build...



add_custom_target(_Dependencies ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/External/Bin/x86 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/External/Bin/x64 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug
)