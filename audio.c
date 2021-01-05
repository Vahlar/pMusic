#include "audio.h"

void lireAudio(){ //(char* audioFile)

    FMOD_SYSTEM *system;
    FMOD_SOUND *musique;
    FMOD_RESULT resultat;
    int continuer = 1;

    FMOD_System_Create(&system);
    FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);

    // ouverture du fichier
    resultat = FMOD_System_CreateSound(system, "test.wav", FMOD_2D | FMOD_CREATESTREAM, 0, &musique);

    //verification du succes de l'ouverture
    if (resultat != FMOD_OK){
        fprintf(stderr, "Impossible de lire le fichier.\n");
        exit(EXIT_FAILURE);
    }
    //activation de repeat infini
    FMOD_Sound_SetLoopCount(musique, -1);

    //lire fichier
    FMOD_System_PlaySound(system, musique, NULL, 0, NULL);

    while (continuer){
    }
    //liberation mémoire
    FMOD_Sound_Release(musique);
    FMOD_System_Close(system);
    FMOD_System_Release(system);
}
