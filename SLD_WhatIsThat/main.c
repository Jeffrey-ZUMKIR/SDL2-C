#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

SDL_Window *pWindow=NULL;
SDL_Renderer *pRenderer=NULL;

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
        /*pWindow=SDL_CreateWindow("An SDL2 window",600,100,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
        //C'éation d'un renderer
        if(pWindow){
            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }*/
        //Création d'une fenêtre et d'un renderer
        if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN,&pWindow,&pRenderer)){
            SDL_DestroyRenderer(pRenderer);
            SDL_DestroyWindow(pWindow);
            return 1;
        }

    }

    //Paramètre d'une fenêtre
    //title
    /*if(pWindow){
        const char *thetitle=SDL_GetWindowTitle(pWindow);
        printf("%s\n", thetitle);
        SDL_SetWindowTitle(pWindow,"new title");
        SDL_Delay(1000);
        //position
        int w=0;
        int h=0;
        SDL_GetWindowPosition(pWindow,&w,&h);
        printf("width : %d\n", w);
        printf("height : %d\n", h);
        SDL_SetWindowPosition(pWindow,800,100);
        SDL_Delay(1000);
        //size
        int x=0;
        int y=0;
        SDL_GetWindowSize(pWindow,&x,&y);
        printf("x : %d\n", x);
        printf("y : %d\n", y);
        SDL_SetWindowSize(pWindow,512,390);
        SDL_Delay(1000);
        //flags
        Uint32 retour = SDL_GetWindowFlags(pWindow);
        if(retour && SDL_WINDOW_RESIZABLE){
            printf("La fenetre est redimensionnable");
        }else{
            printf("La fenetre n'est pas redimensionnable");
        }
        SDL_MaximizeWindow(pWindow);
        SDL_Delay(1000);
        SDL_RestoreWindow(pWindow);
        SDL_Delay(1000);
        SDL_MinimizeWindow(pWindow);
        SDL_Delay(1000);
        SDL_RestoreWindow(pWindow);
        SDL_Delay(1000);
        SDL_HideWindow(pWindow);
        SDL_Delay(1000);
        SDL_ShowWindow(pWindow);
        SDL_Delay(1000);
        SDL_RaiseWindow(pWindow);
        //Chercher comment fonctionne le SDL_SetWindowFullscreen
    }*/

    //Point et rect
    //Créer un point
    SDL_Point point1={0,0};
    //Créer un rect
    SDL_Rect rect;
    rect.h=50;
    rect.w=100;
    rect.x=20;
    rect.y=20;

    if(pRenderer){

    }





    //Permet de garder le rendu de la page pendant x temps
    SDL_Delay(1000);//1 sec
    //Vérification si il y a bien une fenêtre
    if(pRenderer){
        SDL_DestroyRenderer(pRenderer);
    }
    if(pWindow){
        //Détruire la fenêtre
        SDL_DestroyWindow(pWindow);
    }

    return 0;
}
