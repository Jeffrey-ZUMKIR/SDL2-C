#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

SDL_Window *pWindow=NULL;

int main(int argc, char *argv[])
{   //Vérification si l'initialisation s'est mal passé
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        //Afficher les erreurs arrivés
        SDL_Log("Unbale to initialize SDL: %s", SDL_GetError());
        //Détruire toute les données relatives à la SDL
        SDL_Quit();
        //Sortir du programme
        return 1;
    }else{
        //Création d'une fenêtre
        pWindow=SDL_CreateWindow("An SDL2 window",200,100,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
    }
    //Permet de voir le rendu de la page
    SDL_Delay(1000);

    //Vérification si il y a bien une fenêtre
    if(pWindow){
        //Détruire la fenêtre
        SDL_DestroyWindow(pWindow);
    }
    return 0;
}
