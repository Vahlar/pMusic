#ifndef COMMON_H
#define COMMON_H

#include <FMOD/fmod.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct liste{

    char* ID;
    char* artiste;
    char* album;
    char* titre;
    char* path;
    struct liste *next;
    struct liste *pred;

};

#endif

