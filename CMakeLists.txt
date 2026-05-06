cmake_minimum_required(VERSION 3.29)
project(Evidencia_Hier C)

set(CMAKE_C_STANDARD 11)

add_executable(Evidencia_Hier main.c
        Hra.c
        Hra.h
        Evidencia.c
        Evidencia.h
        Osoby.c
        Osoby.h)
