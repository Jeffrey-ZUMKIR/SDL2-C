#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>



int main(int argc, char *argv[])
{   //Vérification si l'initialisation s'est mal passé
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        //Afficher les erreurs arrivés
        SDL_Log("Unbale to initialize SDL: %s", SDL_GetError());
        //Détruire toute les données relatives à la SDL
        SDL_Quit();
        //Sortir du programme
        return 1;
    }
    return 0;
}
