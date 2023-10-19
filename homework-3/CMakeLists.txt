cmake_minimum_required(VERSION 3.25)

set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)

set(CMAKE_PROJECT_NAME "print_ip")
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
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
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
find_package(Threads REQUIRED) # for pthread

## add dirictories
add_subdirectory(core)
add_subdirectory(tests)


set(executable "app")
set(lib1 "exampleLib")


install(TARGETS ${executable} RUNTIME DESTINATION bin/ COMPONENT ${executable})
set_target_properties( ${executable} PROPERTIES INSTALL_RPATH "/usr/local/lib/")
#set_target_properties( ${executable} PROPERTIES INSTALL_RPATH ${CPACK_INSTALL_PREFIX}/lib/${CMAKE_PROJECT_NAME} )
# not ok
install(TARGETS ${lib1} LIBRARY DESTINATION lib/
	COMPONENT ${lib1})
set_target_properties( ${lib1} PROPERTIES INSTALL_RPATH ${CPACK_INSTALL_PREFIX}/lib )


include(${ROOT_DIR_PRJ}/cmake.include/cpack.cmake)
