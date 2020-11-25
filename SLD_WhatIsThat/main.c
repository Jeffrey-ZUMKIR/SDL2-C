#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

SDL_Window *pWindow=NULL;

int main(int argc, char *argv[])
{   //V�rification si l'initialisation s'est mal pass�
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        //Afficher les erreurs arriv�s
        SDL_Log("Unbale to initialize SDL: %s", SDL_GetError());
        //D�truire toute les donn�es relatives � la SDL
        SDL_Quit();
        //Sortir du programme
        return 1;
    }else{
        //Cr�ation d'une fen�tre
        pWindow=SDL_CreateWindow("An SDL2 window",200,100,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
    }
    //Permet de voir le rendu de la page
    SDL_Delay(1000);

    //V�rification si il y a bien une fen�tre
    if(pWindow){
        //D�truire la fen�tre
        SDL_DestroyWindow(pWindow);
    }
    return 0;
}
