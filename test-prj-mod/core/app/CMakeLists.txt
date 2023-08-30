# Assign a name to the project
project(app LANGUAGES CXX)

cmake_minimum_required(VERSION 3.25)

if (CMAKE_VERSION VERSION_LESS "3.26")
    # 3.25
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "3c375311-a3c9-4396-a187-3227ef642046")
elseif (CMAKE_VERSION VERSION_LESS "3.27")
    # 3.26
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
else ()
    message(FATAL_ERROR "See `https://github.com/Kitware/CMake/blob/v${CMAKE_VERSION}/Help/dev/experimental.rst`.")
endif (CMAKE_VERSION VERSION_LESS "3.26")
# turn on the dynamic depends for ninja
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  include(gcc_modules.cmake)
endif()
# specify library to link with
set(lib1_to_add "exampleZ")
# set executable output name
set(executable_name "PROJECT1_EXEC")
# Load all the source file within the folder src
set( TARGET ${PROJECT_NAME} )
# add include and sources

#include(${ROOT_DIR_PRJ}/cmake.include/compile_features.cmake)
#include(${ROOT_DIR_PRJ}/cmake.include/funcs.cmake)
#include(${ROOT_DIR_PRJ}/cmake.include/colors.cmake)

if (COMPILE_FEATURES)
	message("${Green} COMPILE DIRECTIVES ARE SET FOR PROJECT >[${PROJECT_NAME}]< ${ColourReset}")
endif()
#set_release(${PROJECT_NAME})
#set executable name
#set_property(TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME ${executable_name})
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
#include libraries

set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/src" )
set( MODULES_PATH "${PROJECT_SOURCE_DIR}/modules" )

# MODULE SOURCE
target_sources(
	${TARGET}
        PRIVATE
        FILE_SET module_files TYPE CXX_MODULES BASE_DIRS "${SOURCE_PATH}" FILES ${MODULES_PATH}/mod.ixx
)

#set_target_properties(${TARGET} PROPERTIES INSTALL_RPATH "$ORIGIN")
#target_link_libraries(${PROJECT_NAME} 
#	${lib1_to_add}
#	)
