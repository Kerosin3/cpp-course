cmake_minimum_required(VERSION 3.25)
#set version
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(MINOR_VERSION "1" CACHE INTERNAL "Minor version")
set(MAJOR_VERSION "1" CACHE INTERNAL "Major version")

set(PROJECT_VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

set(libname "exampleZ")

project(${libname} VERSION ${PROJECT_VERSION})

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
#hardcode rpath
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
#enable versioning
add_definitions(-D_VERSIONING=1)

configure_file(version.h.in version.h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE) 
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Load all the source file within the folder src
set( TARGET ${PROJECT_NAME} )

set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/src" )
set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include" )
#set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include/${libname}" )

file( GLOB_RECURSE HPPS "${INCLUDE_PATH}/*.hpp" )
file( GLOB_RECURSE CPPS "${SOURCE_PATH}/*.cpp" )

# Define library
add_library( ${TARGET} SHARED ${CPPS} ${HPPS} )
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

target_include_directories( ${TARGET} PUBLIC ${INCLUDE_PATH} ${CMAKE_CURRENT_BINARY_DIR})

# set features
include(${ROOT_DIR_PRJ}/cmake.include/compile_features.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/funcs.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/colors.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/platforms.cmake)

set_defines_lin(${PROJECT_NAME})

if (COMPILE_FEATURES)
	message("${Green} COMPILE DIRECTIVES ARE SET FOR PROJECT >[${PROJECT_NAME}]< ${ColourReset}")
endif()
set_release(${PROJECT_NAME})

#set_property(TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME ${libname})
