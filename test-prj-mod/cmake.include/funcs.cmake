macro(set_release prj_name)
	if(NOT CMAKE_BUILD_TYPE)
		set(CMAKE_BUILD_TYPE DEBUG)
	  message("${Yellow} RELEASE BUILD TYPE FOR >[${prj_name}]< ${ColourReset}")
	endif()
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
