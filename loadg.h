#include "DxLib.h"

#define PLAYER 0
#define BLOCKS 1
#define ITEMS 2
#define ENEMIES 3
#define BACKGD 4
#define BLOCKS2 5
#define BONUS 6
#define BONUS2 7
#define TITLE 30

// extern SDL_Surface *grap[161][8];
extern Mix_Music *otom[6];
extern Mix_Chunk *oto[19];
extern int anx[160], any[160];
extern int ne[40], nf[40];
extern bool sound;

SDL_Surface ***loadg(void);
void parseArgs(int, char *[]);
