macro(set_executable PROJECT_NAME INCLUDE_PATH SOURCE_PATH executable_name)

file( GLOB_RECURSE HPPS "${INCLUDE_PATH}/*.hpp" )
file( GLOB_RECURSE CPPS "${SOURCE_PATH}/*.cpp" )
add_executable( ${PROJECT_NAME} ${CPPS} ${HPPS} )
# include includes + version
target_include_directories( ${PROJECT_NAME} PUBLIC ${INCLUDE_PATH} ${CMAKE_CURRENT_BINARY_DIR} )
set(${executable_name} "HOMEWORK1_EXEC")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${executable_name})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

if(NOT DEFINED PROJECT_COMPILE_FEATURES)
    set(PROJECT_COMPILE_FEATURES cxx_std_20)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if(WIN32 AND MINGW)
    target_link_options(${PROJECT_NAME} PUBLIC "-municode" )
    target_compile_definitions(${PROJECT_NAME} PRIVATE ${PROJECT_COMPILE_DEFINES} UNICODE _UNICODE __USE_MINGW_ANSI_STDIO=0)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBRARIES} "-static-libgcc -Wl,-static,-lpthread")
endif()

if(UNIX)
    target_link_options(${PROJECT_NAME} PUBLIC "$<$<CONFIG:Release>:-s>") # удаляем отладочную информацию
    set(CMAKE_SKIP_RPATH on) # отключим установку путей поиска Shared Library's
    target_link_options(${PROJECT_NAME} PUBLIC "-Wl,-rpath=.") # выставим путь поиска '.'
    set(CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE) 
endif()


target_compile_features(${PROJECT_NAME} PUBLIC ${PROJECT_COMPILE_FEATURES})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${PROJECT_COMPILE_DEFINES})
target_compile_options(${PROJECT_NAME} PUBLIC ${PROJECT_COMPILE_OPTIONS})

endmacro()

