#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>



int main(int argc, char *argv[])
{   //V�rification si l'initialisation s'est mal pass�
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        //Afficher les erreurs arriv�s
        SDL_Log("Unbale to initialize SDL: %s", SDL_GetError());
        //D�truire toute les donn�es relatives � la SDL
        SDL_Quit();
        //Sortir du programme
        return 1;
    }
    return 0;
}
