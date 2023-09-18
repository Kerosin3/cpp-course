# Assign a name to the project

set(libname "exampleZ")

#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
project(${libname} LANGUAGES CXX)

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

target_include_directories( ${TARGET} PUBLIC ${INCLUDE_PATH} )

# set features
include(${ROOT_DIR_PRJ}/cmake.include/compile_features.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/funcs.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/colors.cmake)

if (COMPILE_FEATURES)
	message("${Green} COMPILE DIRECTIVES ARE SET FOR PROJECT >[${PROJECT_NAME}]< ${ColourReset}")
endif()
set_release(${PROJECT_NAME})

#set_property(TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME ${libname})
