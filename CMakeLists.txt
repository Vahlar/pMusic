cmake_minimum_required(VERSION 2.8)

project(ProjetTechProg)

add_executable(${PROJECT_NAME}
    "main.c"
    "common.h"
    "audio.c"
    "audio.h"
    "recherche.c"
    "recherche.h"
    "liste.c"
    "liste.h"
    )

target_link_libraries(${PROJECT_NAME}
    fmod
    )
