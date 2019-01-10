cmake_minimum_required(VERSION 3.13)
project(projetolp1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(projetolp1
        functions.c
        functions.h
        functionsPhase2.c
        functionsPhase2.h
        main.c
        mergeSortLinkedList.c
        mergeSortLinkedList.h
        stringsort.c
        stringsort.h)
