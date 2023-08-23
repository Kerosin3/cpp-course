
# CMake build : global project (kind of solution)

# At LEAST 3.9 but newer is better
cmake_minimum_required(VERSION 3.20)
set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
include(FetchContent)
# Assign a name to the global project
project(cmake_cpp_template)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE) 
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include(${CMAKE_SOURCE_DIR}/cmake.include/colors.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Include external dependencies, located in the folder lib (imported as a git submodule)
#enable tests
enable_testing()

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/contrib)

##-------------
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_PROGRESS TRUE
  GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571 #v 1.14

)
FetchContent_MakeAvailable(googletest)
##-------------
##-------------
FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_PROGRESS TRUE
  GIT_TAG a0b8a92e3d1532361c2f7feb63babc5c18d00ef2 #v 10.0.0
)
FetchContent_MakeAvailable(fmt)
##-------------
##-------------
FetchContent_Declare(spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog
  GIT_PROGRESS TRUE
  GIT_TAG 7e635fca68d014934b4af8a1cf874f63989352b7 #v1.12.0
)

set(SPDLOG_FMT_EXTERNAL ON)# external fmtlib
FetchContent_MakeAvailable(spdlog)
##-------------
find_package(Threads REQUIRED) # for pthread

add_subdirectory(core)
add_subdirectory(tests)
#add_executable(${executable_name} app/src/main.cpp)
#add_executable(${PROJECT1} ALIAS prj1_exe)
#set_property(TARGET ${executable_name} PROPERTY OUTPUT_NAME prj1)
