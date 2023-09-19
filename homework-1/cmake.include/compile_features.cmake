# https://github.com/mapbox/cpp/issues/37
set(COMPILE_FEATURES true)
target_compile_options( ${TARGET} PRIVATE -Wall -Werror=exceptions -Wextra -Wshadow -Wconversion -Wsign-conversion -Wunused-parameter -Wno-long-long -pedantic -Wunused-result -Wconversion -Wunreachable-code -Wuninitialized -pedantic-errors -Wold-style-cast -Wno-error=unused-variable -Wshadow -Wfloat-equal -Weffc++)
target_compile_features( ${TARGET} PRIVATE cxx_std_20 )

message("${Magenta} COMPILE DIRECTIVES ARE SET FOR PROJECT >[${PROJECT_NAME}]< ${ColourReset}")
