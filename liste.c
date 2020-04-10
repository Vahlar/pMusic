#include "liste.h"

struct liste *allouerMusique(char* ID, char* artiste, char* album, char* titre, char* path, struct liste *next, struct liste *pred){

    struct liste *p = NULL;

    p = malloc(sizeof(struct liste));

    p->ID = ID;
    p->artiste = artiste;
    p->album = album;
    p->titre = titre;
    p->path = path;
    p->next = next;
    p->pred = pred;

    return p;
}

struct liste *ajoutMusique(struct liste *head, char* ID, char* artiste, char* album, char* titre, char *path){

    struct liste *p = head;
    struct liste *pNew = NULL;
    struct liste *pPred = NULL;

    if(p == NULL){

        pNew = allouerMusique(ID, artiste, album, titre, path, NULL, NULL);
        return pNew;
    }
    else{
        do{
            pPred = p;
            p = p->next;
        }while(p != NULL);

        pNew = allouerMusique(ID, artiste, album, titre, path, NULL, pPred);
        pPred->next = pNew;
        return head;
    }
}

struct liste *importListe(){

    struct liste *p = NULL;

    size_t size = (sizeof (char))*100;
    const char* marqueur = ";";

    char* ligne = (char *)malloc(size);
    char* ID = NULL;
    char* artiste = NULL;
    char* album = NULL;
    char* titre = NULL;
    char* path = NULL;

    FILE* liste;
    liste = fopen("musiques.txt", "r");
    if(liste == NULL){
        printf("erreur fichier txt\n");
        exit(1);
    }
    while(fgets(ligne, size, liste) != NULL){

        ID = strtok(ligne, marqueur);
        artiste = strtok(NULL, marqueur);
        album = strtok(NULL, marqueur);
        titre = strtok(NULL, marqueur);
        path = strtok(NULL, marqueur);

        printf("%s \n %s \n %s \n %s \n %s \n", ID, artiste, album, titre, path);
        p = ajoutMusique(p, ID, artiste, album, titre, path);
    }
    free(ligne);
    return p;
}
