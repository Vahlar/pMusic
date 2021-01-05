/*
Le programme PolyMusic doit permettre de gérer une bibliothèque de chansons au format mp3 et de pouvoir les lire.
Pour obtenir la liste des mp3 disponibles, PolyMusic accède à une base de données.
Cette base de données est un fichier qui contient les informations et le chemin des mp3.
PolyMusic dispose de 2 modes :
• Un mode utilisateur qui permet de chercher et de lire des musiques
• Un mode administrateur qui permet de modifier la liste des mp3
*/

#include "common.h"
#include "audio.h"
#include "recherche.h"
#include "liste.h"
#include "afficherListe.h"

int main(int argc, char* argv[]){

    //declaration des variables
    char menu = 0;
    char* recherche = NULL;
    char* audioFile = NULL;
    char* audioName = NULL;

    //declaration d'un structure
    struct liste *p = NULL;

    //appel de la fonction importListe() puis affichage de la liste
    p = importListe();
    afficherListe(p);

    //menu
    printf("--- AUDIO PLAYER ---\n\n");
    printf("1. Rechercher un fichier.\n");
    printf("2. Se connecter en admin.\n");
    printf("3. Lire un fichier.\n");

    //demande à l'utilisateur de choisir une catégorie
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

        //dans cette partie la fonction de recherche doit être lancée
        //pour que l'utilisateur puisse naviger parmis les muiques disponible

        break;

    case '2':
        printf("entrez votre mot de passe: \n");

        //dans cette partie un mdp est necessaire pour accéder à la partie admin

        break;

    case '3':

        //dans cette partie, l'utilisateur doit entrer le nom de la musique
        //elle est alors recherché puis lu si disponible
        printf("nom de fichier :\n");
        scanf("%s", audioName);
        audioFile = rechercheAudio(audioName);
        lireAudio(audioFile);
        break;
    }
    return 0;
}


