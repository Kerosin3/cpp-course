# Assign a name to the project
project(tests LANGUAGES CXX)
# specify library to link with
set(lib1_to_add "exampleZ")
# set executable output name
set(executable_name "tests")
# Load all the source file within the folder src
set( TARGET ${PROJECT_NAME} )
# add include and sources

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/src" )
set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include" )
file( GLOB_RECURSE HPPS "${INCLUDE_PATH}/*.hpp" )
file( GLOB_RECURSE CPPS "${SOURCE_PATH}/*.cpp" )
############################################
# Define the executable of the application !
add_executable( ${TARGET} ${CPPS} ${HPPS} )
#add_test(multiply_gtests multiply_test)
# include includes
target_include_directories( ${TARGET} PUBLIC ${INCLUDE_PATH} )
# set features
include(${CMAKE_SOURCE_DIR}/cmake.include/compile_features.cmake)
include(${CMAKE_SOURCE_DIR}/cmake.include/funcs.cmake)
include(${CMAKE_SOURCE_DIR}/cmake.include/colors.cmake)
include(GoogleTest)

gtest_discover_tests(${TARGET})

if (COMPILE_FEATURES)
	message("${Green} COMPILE DIRECTIVES ARE SET FOR PROJECT >[${PROJECT_NAME}]< ${ColourReset}")
endif()
set_release(${PROJECT_NAME})
#set executable name
set_property(TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME ${executable_name})
###########################

#include libraries
set_target_properties(${TARGET} PROPERTIES INSTALL_RPATH "$ORIGIN")
target_link_libraries(${PROJECT_NAME} 
	${lib1_to_add}
	spdlog::spdlog
	fmt::fmt
	gtest_main
	gmock_main
	Threads::Threads
	)
