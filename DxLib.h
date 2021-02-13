// This file is a reverse engineered "DxLib.h" to the extent that
// Syobon Action uses it. Minor functions are just replaced with SDL
// counterparts.
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <time.h>

#include "joyconfig.h"

#define TRUE 1
#define FALSE 0
#define byte unsigned char

// UNIMPLEMENTED - macro substitution
#define SetFontThickness(f) ;
#define StopSoundMem(s) ;
#define ChangeVolumeSoundMem(s, v) ;

// Sound
#define DX_PLAYTYPE_LOOP -1
#define DX_PLAYTYPE_BACK 0
void PlaySoundMem(Mix_Chunk *s, int l);
Mix_Chunk *LoadSoundMem(const char *f);
Mix_Music *LoadMusicMem(const char *f);

void deinit();
int DxLib_Init();

// Main screen
extern SDL_Surface *screen;

// Fonts
#define FONT_MAX 64
extern TTF_Font *font[FONT_MAX];

// Strings & fonts
#define DX_FONTTYPE_NORMAL 0
#define DX_FONTTYPE_EDGE 1
void SetFontSize(byte size);
void ChangeFontType(byte type);
void DrawString(int a, int b, const char *x, Uint32 c);
void DrawFormatString(int a, int b, Uint32 color, const char *str, ...);

// Key Aliases
#define KEY_INPUT_ESCAPE SDLK_ESCAPE
#define KEY_INPUT_LEFT SDLK_LEFT
#define KEY_INPUT_RIGHT SDLK_RIGHT
#define KEY_INPUT_DOWN SDLK_DOWN
#define KEY_INPUT_UP SDLK_UP
#define KEY_INPUT_F1 SDLK_F1
#define KEY_INPUT_O SDLK_o
#define KEY_INPUT_Z SDLK_z
#define KEY_INPUT_RETURN SDLK_RETURN
#define KEY_INPUT_SPACE SDLK_SPACE
#define KEY_INPUT_1 SDLK_1
#define KEY_INPUT_2 SDLK_2
#define KEY_INPUT_3 SDLK_3
#define KEY_INPUT_4 SDLK_4
#define KEY_INPUT_5 SDLK_5
#define KEY_INPUT_6 SDLK_6
#define KEY_INPUT_7 SDLK_7
#define KEY_INPUT_8 SDLK_8
#define KEY_INPUT_9 SDLK_9
#define KEY_INPUT_0 SDLK_0

extern SDL_Joystick *joystick;

void UpdateKeys();
byte ProcessMessage();
byte CheckHitKey(int key);
byte WaitKey();

//#define GetColor(r, g, b) SDL_MapRGB(screen->format, r, g, b)

// Uint32 GetColor(byte r, byte g, byte b);

void DrawGraph(int a, int b, SDL_Surface *mx);

void DrawTurnGraph(int a, int b, SDL_Surface *mx);

void DrawVertTurnGraph(int a, int b, SDL_Surface *mx);

SDL_Surface *loadimageCut(SDL_Surface *a, int x, int y, int r, int z);
SDL_Surface *loadimageCut(int srcx, int srcy, int width, int height, SDL_Surface *src);

// Noticably different than the original
SDL_Surface *loadimage(const char *filename);
SDL_Surface *loadimage(std::string filename);
