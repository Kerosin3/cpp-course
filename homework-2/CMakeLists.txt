cmake_minimum_required(VERSION 3.25)

set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)

set(CMAKE_PROJECT_NAME "HOMEWORK-2")
#set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(MINOR_VERSION "0" CACHE INTERNAL "Minor version")
set(MAJOR_VERSION "1" CACHE INTERNAL "Major version")

if(PATCH_VERSION STREQUAL "")
	set(PATCH_VERSION "0" CACHE INTERNAL "Patch version" FORCE)
endif()

set(PROJECT_VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

project(HOMEWORK_1 VERSION ${PROJECT_VERSION})

include(FetchContent)
#assign current dir
get_filename_component(ROOT_DIR_PRJ
	"${CMAKE_CURRENT_LIST_DIR}"
	ABSOLUTE)

include(${ROOT_DIR_PRJ}/cmake.include/colors.cmake)

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
find_package(Threads REQUIRED) # for pthread

## add dirictories
add_subdirectory(core)
#add_subdirectory(tests)

include(${ROOT_DIR_PRJ}/cmake.include/cpack.cmake)

set(executable "app")
set(lib1 "exampleLib")

install(TARGETS ${executable} DESTINATION bin/)
set_target_properties( ${executable} PROPERTIES INSTALL_RPATH ${CPACK_INSTALL_PREFIX}/lib/${CMAKE_PROJECT_NAME} )

install(TARGETS ${lib1} DESTINATION lib/${CMAKE_PROJECT_NAME})
set_target_properties( ${lib1} PROPERTIES INSTALL_RPATH ${CPACK_INSTALL_PREFIX}/lib/${CMAKE_PROJECT_NAME} )


