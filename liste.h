#ifndef LISTE_H
#define LISTE_H

#include "common.h"

struct liste *allouerMusique(char* pID, char* pArtiste, char* pAlbum, char* pTitre, char* pPath, struct liste *next, struct liste *pred);
struct liste *ajoutMusique(struct liste *head, char* ID, char* artiste, char* album, char* titre, char* path);
struct liste *importListe();

#endif
