cmake_minimum_required(VERSION 3.25)
#set version

#set(PATCH_VERSION "6" CACHE INTERNAL "Patch version")
set(MINOR_VERSION "0" CACHE INTERNAL "Minor version")
set(MAJOR_VERSION "1" CACHE INTERNAL "Major version")

set(PROJECT_VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

project(app VERSION ${PROJECT_VERSION})
set( TARGET ${PROJECT_NAME} )

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)

#enable versioning
add_definitions(-D_VERSIONING=1)

configure_file(version.h.in version.h)
#configure_file(version.h.in {PROJECT_SOURCE_DIR}/include/version.h)

# specify library to link with
set(lib1_to_add "exampleLib")
# set executable output name
set(executable_name "HOMEWORK1_EXEC")
# Load all the source file within the folder src
# add include and sources
set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/src" )
set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include" )
############################################

include(${ROOT_DIR_PRJ}/cmake.include/executable.cmake)
set_executable(${PROJECT_NAME} ${INCLUDE_PATH} ${SOURCE_PATH} ${executable_name})
# set features
include(${ROOT_DIR_PRJ}/cmake.include/compile_features.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/funcs.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/colors.cmake)
include(${ROOT_DIR_PRJ}/cmake.include/platforms.cmake)
#set platform defines
set_defines_lin(${PROJECT_NAME})
if (COMPILE_FEATURES)
	message("${Green} COMPILE DIRECTIVES ARE SET FOR PROJECT >[${PROJECT_NAME}]< ${ColourReset}")
endif()
#set executable
include(${ROOT_DIR_PRJ}/cmake.include/executable.cmake)
#set release
set_release(${PROJECT_NAME})
#setup executalbe

###########################
IF (BUILD_DOCS)
message("${CYAN} BUILDING DOCS FOR >[${PROJECT_NAME}]< ${ColourReset}")
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
ENDIF()



target_link_libraries(${PROJECT_NAME} 
	${lib1_to_add}
	spdlog::spdlog
	fmt::fmt
	gtest_main
	Threads::Threads
	)
