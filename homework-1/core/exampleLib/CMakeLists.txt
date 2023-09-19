cmake_minimum_required(VERSION 3.25)
#set version
#set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(MINOR_VERSION "0" CACHE INTERNAL "Minor version")
set(MAJOR_VERSION "1" CACHE INTERNAL "Major version")

set(PROJECT_VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

set(libname "exampleLib")

project(${libname} VERSION ${PROJECT_VERSION})

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
#enable versioning
add_definitions(-D_VERSIONING=1)

configure_file(version.h.in version.h)

# Load all the source file within the folder src
set( TARGET ${PROJECT_NAME} )

set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/src" )
set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include" )

include(${ROOT_DIR_PRJ}/cmake.include/sharedlib.cmake)
set_sharedlib(${PROJECT_NAME} ${INCLUDE_PATH} ${SOURCE_PATH} )
# set features
include(${ROOT_DIR_PRJ}/cmake.include/compile_features.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/funcs.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/colors.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/platforms.cmake)

set_defines_lin(${PROJECT_NAME})

print_build_type(${PROJECT_NAME})

