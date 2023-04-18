#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#define SCREEN_H 
#define SCREEN_W 
typedef struct{
SDL_Surface *enemie[2][2];
SDL_Rect pos;
int direction;
int num;
}ennemi;

typedef struct{
SDL_Surface *heart[4];
SDL_Rect position;
int etat;
}heart;

typedef struct{
SDL_Surface *img;
SDL_Rect pos;
}back;

void initEnnemi(ennemi *e);

void afficherEnnemi(ennemi *e, SDL_Surface *screen);

void animerenemi(ennemi *e);

void libererenemi(ennemi *e);

void deplacement(ennemi *e);

int collisionbb(SDL_Rect posp,ennemi e);


void initheart(heart *h);

void afficherheart(heart *h, SDL_Surface *screen);

void animerheart(heart *h,int collision);

void libererheart(heart *h);


void initbackground(back *b);

void afficherbackground(back *b,SDL_Surface *screen);
#endif

