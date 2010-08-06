cmake_minimum_required(VERSION 2.6)

add_custom_command(
	OUTPUT wkhtmltoxcom.h wkhtmltoxcom_i.c wkhtmltoxcom_p.c dlldata.c wkhtmltoxcom.tbl
	COMMAND midl wkhtmltoxcom.idl
	MAIN_DEPENDENCY wkhtmltoxcom.idl)

include_directories(../include)
add_library(wkhtmltoxcom SHARED wkhtmltoxcom.def wkhtmltoxcom.h wkhtmltoxcom_i.c com.cpp factory.cpp pdf.cpp image.cpp)
target_link_libraries(wkhtmltoxcom rpcrt4 ../libwkhtmltox0)

add_executable(test test.c wkhtmltoxcom_i.c wkhtmltoxcom.h)
