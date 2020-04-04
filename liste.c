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

void importListe(){

    struct liste *p = NULL;

    char* ligne = NULL;
    char* ID = NULL;
    char* artiste = NULL;
    char* album = NULL;
    char* titre = NULL;
    char* path = NULL;
    char* infos = NULL;

    FILE* liste;
    liste = fopen("musiques.txt", "r");

    //do{
        fgets(ligne, (sizeof (char))*100, liste);

        for(int i = 0; i<5; i++){

            infos = strtok(ligne, " ");

            switch (i) {

            case 0 :
                ID = infos;
                break;
            case 1 :
                artiste = infos;
                break;
            case 2 :
                album = infos;
                break;
            case 3 :
                titre = infos;
                break;
            case 4 :
                path = infos;
                break;
            }
        }
        printf("%s \n %s \n %s \n %s \n %s \n", ID, artiste, album, titre, path);
        ajoutMusique(p, ID, artiste, album, titre, path);
    //}while();
}
