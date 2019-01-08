cmake_minimum_required(VERSION 3.12)
project(projeto C)

set(CMAKE_C_STANDARD 99)

add_executable(projeto main.c functions.c functions.h stringsort.c stringsort.h functionsPhase2.c functionsPhase2.h)
