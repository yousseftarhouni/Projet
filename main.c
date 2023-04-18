#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_events.h>
#include  "h.h"
int main(int argc,char **argv[]){
ennemi e;
heart h;
back b;
SDL_Rect posp;
int boucle=1,collision;
SDL_Surface *screen;
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
    printf("Error initializing SDL: %s\n", SDL_GetError());
    return 1;}
screen=SDL_SetVideoMode(2000,2000,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Event event;
initbackground(&b);
initEnnemi(&e);
initheart(&h);
while(boucle)
{
	afficherbackground(&b,screen);
	afficherheart(&h,screen);
	afficherEnnemi(&e,screen); 
	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
			boucle=0;
			break;
			case SDL_MOUSEBUTTONDOWN:
			posp.x = event.button.x;
                    	posp.y = event.button.y;
                    	break;
		}	
	}
	deplacement(&e);
	animerheart(&h,collision);
	animerenemi(&e);
	collision=collisionbb(posp,e);
	iQf(collision==1 && e.direction==0){
		e.direction=1;}
	else if(collision==1 && e.direction==1){
		e.direction=0;}
	SDL_Flip(screen);
	}
libererenemi(&e); 
libererheart(&h);
SDL_FreeSurface(b.img);
