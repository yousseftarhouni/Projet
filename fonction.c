#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "h.h"
void initEnnemi(ennemi *e)
{
e->num=0;
e->direction=0;

e->pos.x=1500;
e->pos.y=0;

e->enemie[0][0] = IMG_Load("7.png");
e->enemie[0][1] = IMG_Load("8.png");

e->enemie[1][0] = IMG_Load("1.png");
e->enemie[1][1] = IMG_Load("2.png");

}

void animerenemi(ennemi *e){

 if(e->num<1){
		e->num++;
	}
	else{
		e->num=0;
	}

}
void afficherEnnemi(ennemi *e,SDL_Surface *screen)
{
SDL_BlitSurface(e->enemie[e->direction][e->num],NULL,screen,&e->pos);
}   


void libererenemi(ennemi *e){

 int i,j;
 for(i=0;i<2;i++){
 	for(j=0;j<2;j++){
	 SDL_FreeSurface(e->enemie[i][j]);
	}}
}
void deplacement(ennemi *e){
	if(e->direction==0){
		if(e->pos.x > 100 ){
			e->pos.x-=12;
		}
		else{
			e->pos.x=100;
          		e->direction=1;	
		}
	}
	else{
		if(e->pos.x < 1500 ){
           		e->pos.x+=12;
		}
		else{
          		e->pos.x=1500;
          		e->direction=0;
		}

	}
	
}

int collisionbb(SDL_Rect posp,ennemi e){
	int collision;
 if( posp.x+posp.w<e.pos.x || posp.x>e.pos.x+e.pos.w || posp.y+posp.h<e.pos.y || posp.y>e.pos.y+e.pos.h){
        	collision=0;}              
 else{
 collision=1;}
return collision;
}


void initheart(heart *h){
h->etat=0;
h->position.x=700;
h->position.y=700;
h->heart[0] = IMG_Load("full.png");
h->heart[1] = IMG_Load("medium.png");
h->heart[2] = IMG_Load("low.png");
h->heart[3] = IMG_Load("dead.png");
}

void afficherheart(heart *h, SDL_Surface *screen){
SDL_BlitSurface(h->heart[h->etat],NULL,screen,&h->position);
}

void animerheart(heart *h,int collision){
	if(collision==1 && h->etat<4){
	h->etat++;}
	if(collision==1 && h->etat==4){
		h->etat=0;}
}

void libererheart(heart *h){
 int i;
 for(i=0;i<4;i++){
	 SDL_FreeSurface(h->heart[i]);
	}}

void initbackground(back *b){
b->pos.x=0;
b->pos.y=0;
b->img=IMG_Load("background.jpg");
}

void afficherbackground(back *b,SDL_Surface *screen)
{
SDL_BlitSurface(b->img,NULL,screen,&b->pos);
}   

