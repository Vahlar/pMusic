#include "afficherListe.h"

void afficherListe(struct liste *head){

    struct liste *pListe = head;

    while(pListe != NULL){
        printf("%s\n", pListe->ID);
        printf("%s\n", pListe->artiste);
        printf("%s\n", pListe->album);
        printf("%s\n", pListe->titre);
        printf("%s\n", pListe->path);

        pListe = pListe->next;
    }
    printf("\n");
}
