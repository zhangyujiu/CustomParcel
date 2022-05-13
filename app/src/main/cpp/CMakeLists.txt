
cmake_minimum_required(VERSION 3.18.1)

project("parcel")

file(GLOB allCPP *.c *.h *.cpp)

add_library(
        parcel

        SHARED

        ${allCPP})

find_library(
        log-lib

        log)


target_link_libraries(
        parcel

        ${log-lib})