#include "liste.h"

struct liste *allouerMusique(char* pID, char* pArtiste, char* pAlbum, char* pTitre, char* pPath, struct liste *next, struct liste *pred){

    struct liste *p = NULL;

    int size = (strlen(pID)+1)+(strlen(pArtiste)+1)+(strlen(pAlbum)+1)+(strlen(pTitre)+1)+(strlen(pPath)+1);

    printf("size: %d\n", size);
    p = malloc(sizeof(char)*size);

//    p->ID = malloc((sizeof(char))*(strlen(pID)+1));
//    p->artiste = malloc((sizeof(char))*(strlen(pArtiste)+1));
//    p->album = malloc((sizeof(char))*(strlen(pAlbum)+1));
//    p->titre = malloc((sizeof(char))*(strlen(pTitre)+1));
//    p->path = malloc((sizeof(char))*(strlen(pPath)+1));

    p->ID = pID;
    p->artiste = pArtiste;
    p->album = pAlbum;
    p->titre = pTitre;
    p->path = pPath;
    p->next = next;
    p->pred = pred;

    printf("%s\n%s\n%s\n%s\n%s\n", p->ID, p->artiste, p->album, p->titre, p->path);

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

        p = allouerMusique(ID, artiste, album, titre, path, NULL, pPred);
        pPred->next = p;
        return head;
    }
}

struct liste *importListe(){

    struct liste *p = NULL;

    size_t size = (sizeof (char))*100;
    const char* marqueur = "|";

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

        //printf("%s\n%s\n%s\n%s\n%s\n", ID, artiste, album, titre, path);
        p = ajoutMusique(p, ID, artiste, album, titre, path);
    }
    free(ligne);
    fclose(liste);

    return p;
}
