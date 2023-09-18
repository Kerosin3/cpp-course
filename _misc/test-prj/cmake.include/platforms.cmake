macro(set_defines_win prj_name)
if (WIN32)
	message("${Yellow} set defines for windows >[${prj_name}]< ${ColourReset}")
	target_compile_definitions(${prj_name} PRIVATE WINDOWS_PRJ=1 LINUX_PRJ=0 APPLE_PRJ=0)
else()
	message("${red} this is not win32 ${ColourReset}")
endif()

endmacro()



macro(set_defines_lin prj_name)
if(UNIX AND NOT APPLE)
	message("${Yellow} set defines for linux and unix >[${prj_name}]< ${ColourReset}")
	target_compile_definitions(${prj_name} PRIVATE WINDOWS_PRJ=0 LINUX_PRJ=1 APPLE_PRJ=0)
else()
	message("${red} this is not linux\unix ${ColourReset}")
endif()

endmacro()

macro(set_defines_apple prj_name)
if(APPLE)
	message("${Yellow} set defines for apple >[${prj_name}]< ${ColourReset}")
	target_compile_definitions(${prj_name} PRIVATE WINDOWS_PRJ=0 LINUX_PRJ=0 APPLE_PRJ=1)
else()
	message("${red} this is not apple ${ColourReset}")
endif()

endmacro()

