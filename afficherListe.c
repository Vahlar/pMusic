#include "afficherListe.h"

void afficherListe(struct liste *head){

    struct liste *pListe = head;

    do{
        printf("%s\n%s\n%s\n%s\n%s\n", pListe->ID, pListe->titre, pListe->album, pListe->titre, pListe->path);
        pListe = pListe->next;
    }while(pListe != NULL);
    printf("\n");
}
