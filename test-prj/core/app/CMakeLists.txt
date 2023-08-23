# Assign a name to the project
project(app LANGUAGES CXX)
# specify library to link with
set(lib1_to_add "exampleZ")
# set executable output name
set(executable_name "PROJECT1_EXEC")
# Load all the source file within the folder src
set( TARGET ${PROJECT_NAME} )
# add include and sources
set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/src" )
set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include" )
file( GLOB_RECURSE HPPS "${INCLUDE_PATH}/*.hpp" )
file( GLOB_RECURSE CPPS "${SOURCE_PATH}/*.cpp" )
############################################
# Define the executable of the application !
SET(CMAKE_INSTALL_RPATH "${LIBBAR_PATH}/lib")
add_executable( ${TARGET} ${CPPS} ${HPPS} )
# include includes
target_include_directories( ${TARGET} PUBLIC ${INCLUDE_PATH} )
# set features

include(${ROOT_DIR_PRJ}/cmake.include/compile_features.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/funcs.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/colors.cmake)

if (COMPILE_FEATURES)
	message("${Green} COMPILE DIRECTIVES ARE SET FOR PROJECT >[${PROJECT_NAME}]< ${ColourReset}")
endif()
set_release(${PROJECT_NAME})
#set executable name
set_property(TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME ${executable_name})
###########################

find_package(Doxygen 
	     REQUIRED dot 
	     OPTIONAL_COMPONENTS mscgen dia)
if (DOXYGEN_FOUND)
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doxy_setup/Doxyfile)
	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
	message("starting doxygen guild")

	add_custom_target(doc_doxygen_${PROJECT_NAME} ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Test Project 1"
		VERBATIM
	)
else (DOXYGEN_FOUND)
	message("doxygen not found")
endif(DOXYGEN_FOUND)
#include libraries
set_target_properties(${TARGET} PROPERTIES INSTALL_RPATH "$ORIGIN")
target_link_libraries(${PROJECT_NAME} 
	${lib1_to_add}
	spdlog::spdlog
	fmt::fmt
	gtest_main
	Threads::Threads
	)
