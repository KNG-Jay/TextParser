cmake_minimum_required(VERSION 3.14)

# Set some basic project attributes
project (TextParser
	VERSION 0.1
	DESCRIPTION "A Program That Parses Chosen Files For Keywords")
	
# Establish C++ Standard Number
set(CMAKE_CXX_STANDARD 23)

# Set the CMake toolchain file path for vcpkg
set(CMAKE_TOOLCHAIN_FILE "~/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

enable_testing()

# Find vcpkg ports for the project
find_package(GTest CONFIG REQUIRED)

# This project will output an executable file
add_executable(${PROJECT_NAME} src/main.cpp)
add_executable(runUnitTests test/TPTests.cpp src/TextParser.cpp)

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
target_link_libraries(runUnitTests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

#add_test(AllTestsInMain ${PROJECT_NAME})
include(GoogleTest)
gtest_discover_tests(runUnitTests)