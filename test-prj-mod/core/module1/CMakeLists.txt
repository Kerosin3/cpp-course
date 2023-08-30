set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

project(clang-tidy-issue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_CXX_SCAN_FOR_MODULES YES)

# First find clang-tidy, this also allows users to provide hints

# https://clang.llvm.org/docs/StandardCPlusPlusModules.html#how-to-build-projects-using-modules
# clang++ -std=c++20 -x c++-module greeting.cppm --precompile -o build/greeting.pcm
# clang++ -std=c++20 hello.cpp -fprebuilt-module-path=build build/greeting.pcm -o build/hello
#
# see https://gitlab.kitware.com/cmake/cmake/-/blob/v3.26.3/Help/dev/experimental.rst?ref_type=tags#c-20-module-apis
# and https://gitlab.kitware.com/cmake/cmake/-/blob/v3.26.3/.gitlab/ci/cxx_modules_rules_gcc.cmake?ref_type=tags
#     https://gitlab.kitware.com/cmake/cmake/-/blob/v3.26.3/.gitlab/ci/cxx_modules_rules_clang.cmake?ref_type=tags

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API aa1f7df0-828a-4fcd-9afc-2dc80491aca7)
#set(CMake_TEST_CXXModules_UUID "a246741c-d067-4019-a8fb-3d16b0c9d1d3")
# Workaround for C++Modules: Missing module map flags in exported compile commands
# see https://gitlab.kitware.com/cmake/cmake/-/issues/24618
set(CMAKE_CXX_COMPILE_OBJECT "${CMAKE_CXX_COMPILE_OBJECT} @<OBJECT>.modmap")

set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
  string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
                "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -E -x c++ <SOURCE>"
                " -MT <DYNDEP_FILE> -MD -MF <DEP_FILE>"
                " -fmodules-ts -fdep-file=<DYNDEP_FILE> -fdep-output=<OBJECT> -fdep-format=trtbd"
                " -o <PREPROCESSED_SOURCE>"
  )
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "gcc")
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG "-fmodules-ts -fmodule-mapper=<MODULE_MAP_FILE> -fdep-format=trtbd -x c++")

  set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY};-checks=*,-llvmlibc-*,-fuchsia-*,-cppcoreguidelines-init-variables")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "clang")
  set(CMAKE_EXE_LINKER_FLAGS -lstdc++)
endif()

add_library(foo)

target_sources(
  foo
  PUBLIC FILE_SET
         cxx_modules
         TYPE
         CXX_MODULES
         FILES
	 ${PROJECT_SOURCE_DIR}/src/foo.cppm
)
add_executable(hello ${PROJECT_SOURCE_DIR}/src/hello.cpp)
target_link_libraries(hello foo)
