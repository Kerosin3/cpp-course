macro(print_build_type prj_name)
	message("${Yellow} BUILD TYPE FOR >[${prj_name}]< IS ${CMAKE_BUILD_TYPE} ${ColourReset}")
endmacro()

macro(add_boost prj_name)
set(BOOST_REQUIRED_COMPONENTS
    filesystem
    optional
)
set(BOOST_MIN_VERSION 1.79.0) # or whatever you need!
# set(BOOST_ROOT "/Volumes/Code/boost_1_79_0")
find_package(
    Boost ${BOOST_MIN_VERSION} REQUIRED
    COMPONENTS ${BOOST_REQUIRED_COMPONENTS}
)
target_link_libraries(${EXECUTABLE} PUBLIC  
    Boost::filesystem
    Boost::optional
)
target_include_directories(${EXECUTABLE} PRIVATE include)
message("${Yellow} RELEASE BUILD TYPE FOR >[${prj_name}]< ${ColourReset}")
endmacro()
