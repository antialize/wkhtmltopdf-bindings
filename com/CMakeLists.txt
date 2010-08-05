cmake_minimum_required(VERSION 2.6)

include_directories(../include)
add_library(wkhtmltoxcom SHARED wkhtmltoxcom.def wkhtmltoxcom.h com.c)
target_link_libraries(wkhtmltoxcom rpcrt4 ../libwkhtmltox0)

add_executable(test test.c)



