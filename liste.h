#ifndef LISTE_H
#define LISTE_H

#include "common.h"

struct liste{

    char* ID;
    char* artiste;
    char* album;
    char* titre;
    char* path;
    struct liste *next;
    struct liste *pred;

};

struct liste *allouerMusique(char* ID, char* artiste, char* album, char* titre, char* path, struct liste *next, struct liste *pred);
struct liste *ajoutMusique(struct liste *head, char* ID, char* artiste, char* album, char* titre, char* path);
struct liste *importListe();
#endif
