CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# set the project name
PROJECT(rtos LANGUAGES C VERSION 0.0.1 DESCRIPTION "A demo C project with CMake")
# PROJECT(rtos C)
message("Project name is: ${PROJECT_NAME}")

# grab all c files in src folder
file(GLOB SRC_FILES src/*.c)
message("Found sources: ${SRC_FILES}")

# define a variable that contains all C files
set(SOURCES main.c ${SRC_FILES})

# Optional, add flags to the C compiler
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")

# add the executable
add_executable(${PROJECT_NAME}.out ${SOURCES})

# add directories for header files
target_include_directories(${PROJECT_NAME}.out PRIVATE ${PROJECT_SOURCE_DIR}/src)
