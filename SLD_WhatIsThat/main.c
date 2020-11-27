#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

void DrawRectLine(SDL_Rect rect);
void DrawRect(SDL_Rect rect);
void DrawRectFilled(SDL_Rect rect);
void DrawCircle(int cx, int cy, int rayon);
void DrawCircleFilled(int cx, int cy, int rayon);

SDL_Window *pWindow=NULL;
SDL_Renderer *pRenderer=NULL;
SDL_Surface *pSurface = NULL;

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
        /*pWindow=SDL_CreateWindow("An SDL2 window",600,100,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
        //C'�ation d'un renderer
        if(pWindow){
            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }*/
        //Cr�ation d'une fen�tre et d'un renderer
        if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN,&pWindow,&pRenderer)){
            SDL_DestroyRenderer(pRenderer);
            SDL_DestroyWindow(pWindow);
            return 1;
        }

    }

    //Param�tre d'une fen�tre
    //title
   /* if(pWindow){
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
    //Cr�er un point
    SDL_Point point1={0,0};
    //Cr�er un rect
    SDL_Rect rect;
    rect.h=100;
    rect.w=100;
    rect.x=20;
    rect.y=20;

    SDL_Color red={255,0,0,255};
    if(pRenderer){
        SDL_SetRenderDrawColor(pRenderer, red.r, red.g, red.b, red.a);//Donner la couleur
        SDL_RenderClear(pRenderer);//Effacer enti�rement le renderer
        SDL_RenderPresent(pRenderer);//mettre � jour le renderer
    }

    //Draw rect
    //Draw avec des lignes
    //DrawRectLine(rect);
    //Draw avec la fonction SDL_RenderDrawRect()
    //DrawRect(rect);
    //Draw avec la fonction SDL_RenderFillRect
    //DrawRectFilled(rect);
    //Draw circle
    //Point par point
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    //DrawCircle(100,100,50);
    DrawCircleFilled(100,100,50);
    SDL_RenderPresent(pRenderer);







    //Les surfaces
    /*pSurface = SDL_CreateRGBSurface(0, 300, 200, 32, 0, 0, 0, 0);
    if(NULL == pSurface)
    {
        fprintf(stderr, "Erreur SDL_CreateRGBSurface : %s", SDL_GetError());
        return 1;
    }
    //Ne fonctionne pas
    SDL_Rect rect2={50,50,300,300};
    SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 0, 0, 0));*/





    //Permet de garder le rendu de la page pendant x temps
    SDL_Delay(10000);//1 sec
    //V�rification si il y a bien une fen�tre
    if(pSurface){
        SDL_FreeSurface(pSurface);
    }
    if(pRenderer){
        SDL_DestroyRenderer(pRenderer);
    }
    if(pWindow){
        //D�truire la fen�tre
        SDL_DestroyWindow(pWindow);
    }

    return 0;
}

void DrawRectLine(SDL_Rect rect){
    SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
    SDL_RenderDrawLine(pRenderer,rect.x,rect.y,rect.x+rect.w,rect.y);
    SDL_RenderDrawLine(pRenderer,rect.x+rect.w,rect.y,rect.x+rect.w,rect.y+rect.h);
    SDL_RenderDrawLine(pRenderer,rect.x+rect.w,rect.y+rect.h,rect.x,rect.y+rect.h);
    SDL_RenderDrawLine(pRenderer,rect.x,rect.y+rect.h,rect.x,rect.y);
    SDL_RenderPresent(pRenderer);

}
void DrawRect(SDL_Rect rect){
    SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
    SDL_RenderDrawRect(pRenderer,&rect);
    SDL_RenderPresent(pRenderer);
}

void DrawRectFilled(SDL_Rect rect){
    SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
    SDL_RenderFillRect(pRenderer,&rect);
    SDL_RenderPresent(pRenderer);
}

void DrawCircle(int cx, int cy, int rayon){
    int d, y, x;

    d=3-(2*rayon);
    x=0;
    y=rayon;

    while(y>=x){
        SDL_RenderDrawPoint(pRenderer,cx + x,cy + y);
        SDL_RenderDrawPoint(pRenderer,cx + y,cy + x);
        SDL_RenderDrawPoint(pRenderer,cx - x,cy + y);
        SDL_RenderDrawPoint(pRenderer,cx - y,cy + x);
        SDL_RenderDrawPoint(pRenderer,cx + x,cy - y);
        SDL_RenderDrawPoint(pRenderer,cx + y,cy - x);
        SDL_RenderDrawPoint(pRenderer,cx - x,cy - y);
        SDL_RenderDrawPoint(pRenderer,cx - y,cy - x);

        if(d<0){
            d=d+(4*x)+6;
        }else{
            d=d+4*(x-y)+10;
            y--;
        }
        x++;
    }
}

void DrawCircleFilled(int cx, int cy, int rayon){
    int d, y, x;

    d=3-(2*rayon);
    x=0;
    y=rayon;

    while(y>=x){
        SDL_RenderDrawLine(pRenderer,cx,cy,cx + x,cy + y);
        //SDL_RenderDrawLine(pRenderer,cx,cy,cx + y,cy + x);
        //SDL_RenderDrawLine(pRenderer,cx,cy,cx - x,cy + y);
        //SDL_RenderDrawLine(pRenderer,cx,cy,cx - y,cy + x);
        //SDL_RenderDrawLine(pRenderer,cx,cy,cx + x,cy - y);
        //SDL_RenderDrawLine(pRenderer,cx,cy,cx + y,cy - x);
        //SDL_RenderDrawLine(pRenderer,cx,cy,cx - x,cy - y);
        //SDL_RenderDrawLine(pRenderer,cx,cy,cx - y,cy - x);

        if(d<0){
            d=d+(4*x)+6;
        }else{
            d=d+4*(x-y)+10;
            y--;
        }
        x++;
    }
}
