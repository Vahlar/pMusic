#include "common.h"

int main(int argc, char* argv[]){

    char menu = 0;
    char* recherche = NULL;
    char* audioFile = NULL;
    char* audioName = NULL;

    importListe();

    //menu
    printf("--- AUDIO PLAYER ---\n\n");
    printf("1. Rechercher un fichier.\n");
    printf("2. Se connecter en admin.\n");
    printf("3. Lire un fichier.\n");

    //j'utilise un char au cas ou une lettre est entrée
    scanf("%s", &menu);
    while(menu<'1' || menu>'3'){
        printf("votre choix n'est pas disponible, veuillez reessayer:\n");
        scanf("%s", &menu);
    }
    switch (menu) {
    case '1':
        printf("Recherche: \n");
        scanf("%s", recherche);
        break;

    case '2':
        printf("entrez votre mot de passe: \n");
        break;

    case '3':
        printf("nom de fichier :\n");
        scanf("%s", audioName);
        audioFile = rechercheAudio(audioName);
        lireAudio(audioFile);
        break;
    }
    return 0;
}

