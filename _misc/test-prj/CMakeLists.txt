
# CMake build : global project (kind of solution)

cmake_minimum_required(VERSION 3.25)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)

include(FetchContent)
# Assign a name to the global project
project(cmake_cpp_template VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE) 
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#assign current dir
get_filename_component(ROOT_DIR_PRJ
	"${CMAKE_CURRENT_LIST_DIR}"
	ABSOLUTE)

include(${ROOT_DIR_PRJ}/cmake.include/colors.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/cpack.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#enable tests
enable_testing()

# Include external dependencies, located in the folder lib (imported as a git submodule)
set(FETCHCONTENT_BASE_DIR ${ROOT_DIR_PRJ}/contrib)

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

## add dirictories
add_subdirectory(core)
add_subdirectory(tests)
#add_executable(${executable_name} app/src/main.cpp)
#add_executable(${PROJECT1} ALIAS prj1_exe)
#set_property(TARGET ${executable_name} PROPERTY OUTPUT_NAME prj1)
