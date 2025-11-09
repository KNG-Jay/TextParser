cmake_minimum_required(VERSION 3.14)

# Set some basic project attributes
project (TextParser
	VERSION 0.1
	DESCRIPTION "A Program That Parses Chosen Files For Keywords")
	
# Establish C++ Standard Number
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# Set the CMake toolchain file path for vcpkg
set(CMAKE_TOOLCHAIN_FILE "$ENV{HOME}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
	osl
	GIT_REPOSITORY https://github.com/Blake-Madden/OleanderStemmingLibrary.git
	GIT_TAG master
)

FetchContent_MakeAvailable(osl)

enable_testing()

# Find vcpkg ports for the project
find_package(GTest CONFIG REQUIRED)

# This project will output an executable file
add_executable(${PROJECT_NAME} src/main.cpp)
add_executable(runUnitTests test/TPTests.cpp src/TextParser.cpp)

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
target_include_directories(${PROJECT_NAME}
	PUBLIC
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_BINARY_DIR}/_deps/osl-src/src"
	"${CMAKE_SOURCE_DIR}/include"
)

target_include_directories(runUnitTests
	PUBLIC
		"${PROJECT_BINARY_DIR}/_deps/osl-src/src"
)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
target_link_libraries(runUnitTests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

#add_test(AllTestsInMain ${PROJECT_NAME})
include(GoogleTest)
gtest_discover_tests(runUnitTests)