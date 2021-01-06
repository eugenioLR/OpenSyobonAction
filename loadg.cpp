#include "loadg.h"

// pointer to array of arrays
void loadg(struct gameInfo *gameState) {
    int i, j;
    for (i = 0; i < 51; i++)
        gameState->spriteSheets[i] = 0;

    for (i = 0; i < 161; i++)
        for (j = 0; j < 8; j++)
            gameState->graphics[i][j] = NULL;

    //画像読み込み

    // 透過色を変更
    // SetTransColor( 9*16+9 , 255 , 255 ) ;

    //プレイヤー
    gameState->spriteSheets[PLAYER] = LoadGraph("res/player.PNG");
    //ブロック
    gameState->spriteSheets[BLOCKS] = LoadGraph("res/brock.PNG");
    //アイテム
    gameState->spriteSheets[ITEMS] = LoadGraph("res/item.PNG");
    //敵
    gameState->spriteSheets[ENEMIES] = LoadGraph("res/teki.PNG");
    //背景
    gameState->spriteSheets[BACKGD] = LoadGraph("res/haikei.PNG");
    //ブロック2
    gameState->spriteSheets[BLOCKS2] = LoadGraph("res/brock2.PNG");
    //おまけ
    gameState->spriteSheets[BONUS] = LoadGraph("res/omake.PNG");
    //おまけ2
    gameState->spriteSheets[BONUS2] = LoadGraph("res/omake2.PNG");
    //タイトル
    gameState->graphics[0][TITLE] = LoadGraph("res/syobon3.PNG");

    //プレイヤー読み込み
    gameState->graphics[40][PLAYER] = DerivationGraph(0, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[0][PLAYER] = DerivationGraph(31 * 4, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[1][PLAYER] = DerivationGraph(31 * 1, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[2][PLAYER] = DerivationGraph(31 * 2, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[3][PLAYER] = DerivationGraph(31 * 3, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[41][PLAYER] = DerivationGraph(50, 0, 51, 73, gameState->spriteSheets[BONUS]);
    /* TODO, modify main.cpp
    gameState->graphics[PLAYER][0] = DerivationGraph(0, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[PLAYER][1] = DerivationGraph(31 * 4, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[PLAYER][2] = DerivationGraph(31 * 1, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[PLAYER][3] = DerivationGraph(31 * 2, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[PLAYER][4] = DerivationGraph(31 * 3, 0, 30, 36, gameState->spriteSheets[PLAYER]);
    gameState->graphics[PLAYER][5] = DerivationGraph(50, 0, 51, 73, gameState->spriteSheets[BONUS]);
    */

    //ブロック読み込み
    for (i = 0; i < 7; i++) {
        gameState->graphics[i][BLOCKS] = DerivationGraph(33 * i, 0, 30, 30, gameState->spriteSheets[BLOCKS]);
        gameState->graphics[i + 30][BLOCKS] = DerivationGraph(33 * i, 33, 30, 30, gameState->spriteSheets[BLOCKS]);
        gameState->graphics[i + 60][BLOCKS] = DerivationGraph(33 * i, 66, 30, 30, gameState->spriteSheets[BLOCKS]);
        gameState->graphics[i + 90][BLOCKS] = DerivationGraph(33 * i, 99, 30, 30, gameState->spriteSheets[BLOCKS]);
    }
    gameState->graphics[8][BLOCKS] = DerivationGraph(33 * 7, 0, 30, 30, gameState->spriteSheets[BLOCKS]);
    gameState->graphics[16][BLOCKS] = DerivationGraph(33 * 6, 0, 24, 27, gameState->spriteSheets[ITEMS]);
    gameState->graphics[10][BLOCKS] = DerivationGraph(33 * 9, 0, 30, 30, gameState->spriteSheets[BLOCKS]);
    gameState->graphics[40][BLOCKS] = DerivationGraph(33 * 9, 33, 30, 30, gameState->spriteSheets[BLOCKS]);
    gameState->graphics[70][BLOCKS] = DerivationGraph(33 * 9, 66, 30, 30, gameState->spriteSheets[BLOCKS]);
    gameState->graphics[100][BLOCKS] = DerivationGraph(33 * 9, 99, 30, 30, gameState->spriteSheets[BLOCKS]);

    /* TODO modify main.cpp
    for(i = 0; i < 7; i++){
        gameState->graphics[BLOCKS][1] = DerivationGraph(33, 0, 30, 30, gameState->spriteSheets[BLOCKS]);
        gameState->graphics[BLOCKS][i + 30] = DerivationGraph(33 * i, 33, 30, 30, gameState->spriteSheets[BLOCKS]);
        gameState->graphics[BLOCKS][i + 60] = DerivationGraph(33 * i, 66, 30, 30, gameState->spriteSheets[BLOCKS]);
        gameState->graphics[BLOCKS][i + 90] = DerivationGraph(33 * i, 99, 30, 30, gameState->spriteSheets[BLOCKS]);
    }
    gameState->graphics[BLOCKS][8] = DerivationGraph(33 * 7, 0, 30, 30, gameState->spriteSheets[BLOCKS]);
    gameState->graphics[BLOCKS][16] = DerivationGraph(33 * 6, 0, 24, 27, gameState->spriteSheets[2]);
    gameState->graphics[BLOCKS][10] = DerivationGraph(33 * 9, 0, 30, 30, gameState->spriteSheets[BLOCKS]);
    gameState->graphics[BLOCKS][40] = DerivationGraph(33 * 9, 33, 30, 30, gameState->spriteSheets[BLOCKS]);
    gameState->graphics[BLOCKS][70] = DerivationGraph(33 * 9, 66, 30, 30, gameState->spriteSheets[BLOCKS]);
    gameState->graphics[BLOCKS][100] = DerivationGraph(33 * 9, 99, 30, 30, gameState->spriteSheets[BLOCKS]);
    */

    //ブロック読み込み2
    for (i = 0; i <= 6; i++) {
        gameState->graphics[i][BLOCKS2] = DerivationGraph(33 * i, 0, 30, 30, gameState->spriteSheets[BLOCKS2]);
    }
    gameState->graphics[10][BLOCKS2] = DerivationGraph(33 * 1, 33, 30, 30, gameState->spriteSheets[BLOCKS2]);
    gameState->graphics[11][BLOCKS2] = DerivationGraph(33 * 2, 33, 30, 30, gameState->spriteSheets[BLOCKS2]);
    gameState->graphics[12][BLOCKS2] = DerivationGraph(33 * 0, 66, 30, 30, gameState->spriteSheets[BLOCKS2]);
    gameState->graphics[13][BLOCKS2] = DerivationGraph(33 * 1, 66, 30, 30, gameState->spriteSheets[BLOCKS2]);
    gameState->graphics[14][BLOCKS2] = DerivationGraph(33 * 2, 66, 30, 30, gameState->spriteSheets[BLOCKS2]);

    //アイテム読み込み
    for (i = 0; i <= 5; i++) {
        gameState->graphics[i][ITEMS] = DerivationGraph(33 * i, 0, 30, 30, gameState->spriteSheets[ITEMS]);
    }

    //敵キャラ読み込み
    gameState->graphics[0][ENEMIES] = DerivationGraph(33 * 0, 0, 30, 30, gameState->spriteSheets[ENEMIES]);
    gameState->graphics[1][ENEMIES] = DerivationGraph(33 * 1, 0, 30, 43, gameState->spriteSheets[ENEMIES]);
    gameState->graphics[2][ENEMIES] = DerivationGraph(33 * 2, 0, 30, 30, gameState->spriteSheets[ENEMIES]);
    gameState->graphics[3][ENEMIES] = DerivationGraph(33 * 3, 0, 30, 44, gameState->spriteSheets[ENEMIES]);
    gameState->graphics[4][ENEMIES] = DerivationGraph(33 * 4, 0, 33, 35, gameState->spriteSheets[ENEMIES]);
    gameState->graphics[5][ENEMIES] = DerivationGraph(0, 0, 37, 55, gameState->spriteSheets[BONUS2]);
    gameState->graphics[6][ENEMIES] = DerivationGraph(38 * 2, 0, 36, 50, gameState->spriteSheets[BONUS2]);
    gameState->graphics[150][ENEMIES] = DerivationGraph(38 * 2 + 37 * 2, 0, 36, 50, gameState->spriteSheets[BONUS2]);
    gameState->graphics[7][ENEMIES] = DerivationGraph(33 * 6 + 1, 0, 32, 32, gameState->spriteSheets[ENEMIES]);
    gameState->graphics[8][ENEMIES] = DerivationGraph(38 * 2 + 37 * 3, 0, 37, 47, gameState->spriteSheets[BONUS2]);
    gameState->graphics[151][ENEMIES] = DerivationGraph(38 * 3 + 37 * 3, 0, 37, 47, gameState->spriteSheets[BONUS2]);
    gameState->graphics[9][ENEMIES] = DerivationGraph(33 * 7 + 1, 0, 26, 30, gameState->spriteSheets[ENEMIES]);
    gameState->graphics[10][ENEMIES] = DerivationGraph(214, 0, 46, 16, gameState->spriteSheets[BONUS]);

    //モララー
    gameState->graphics[30][ENEMIES] = DerivationGraph(0, 56, 30, 36, gameState->spriteSheets[BONUS2]);
    gameState->graphics[155][ENEMIES] = DerivationGraph(31 * 3, 56, 30, 36, gameState->spriteSheets[BONUS2]);
    gameState->graphics[31][ENEMIES] = DerivationGraph(50, 74, 49, 79, gameState->spriteSheets[BONUS]);

    gameState->graphics[80][ENEMIES] = DerivationGraph(151, 31, 70, 40, gameState->spriteSheets[BACKGD]);
    gameState->graphics[81][ENEMIES] = DerivationGraph(151, 72, 70, 40, gameState->spriteSheets[BACKGD]);
    gameState->graphics[130][ENEMIES] = DerivationGraph(151 + 71, 72, 70, 40, gameState->spriteSheets[BACKGD]);
    gameState->graphics[82][ENEMIES] = DerivationGraph(33 * 1, 0, 30, 30, gameState->spriteSheets[BLOCKS2]);
    gameState->graphics[83][ENEMIES] = DerivationGraph(0, 0, 49, 48, gameState->spriteSheets[BONUS]);
    gameState->graphics[84][ENEMIES] = DerivationGraph(33 * 5 + 1, 0, 30, 30, gameState->spriteSheets[ENEMIES]);
    gameState->graphics[86][ENEMIES] = DerivationGraph(102, 66, 49, 59, gameState->spriteSheets[BONUS]);
    gameState->graphics[87][ENEMIES] = DerivationGraph(33 * 8 - 5, 0, 16, 16, gameState->spriteSheets[ENEMIES]); // fireball segment
    gameState->graphics[152][ENEMIES] = DerivationGraph(152, 66, 49, 59, gameState->spriteSheets[BONUS]);

    gameState->graphics[90][ENEMIES] = DerivationGraph(102, 0, 64, 63, gameState->spriteSheets[BONUS]);

    gameState->graphics[100][ENEMIES] = DerivationGraph(33 * 1, 0, 30, 30, gameState->spriteSheets[ITEMS]);
    gameState->graphics[101][ENEMIES] = DerivationGraph(33 * 7, 0, 30, 30, gameState->spriteSheets[ITEMS]);
    gameState->graphics[102][ENEMIES] = DerivationGraph(33 * 3, 0, 30, 30, gameState->spriteSheets[ITEMS]);

    // gameState->graphics[104][ENEMIES] = DerivationGraph( 33*2, 0, 30, 30, gameState->spriteSheets[BLOCKS2]) ;
    gameState->graphics[105][ENEMIES] = DerivationGraph(33 * 5, 0, 30, 30, gameState->spriteSheets[ITEMS]);
    gameState->graphics[110][ENEMIES] = DerivationGraph(33 * 4, 0, 30, 30, gameState->spriteSheets[ITEMS]);

    //背景読み込み
    gameState->graphics[0][BACKGD] = DerivationGraph(0, 0, 150, 90, gameState->spriteSheets[BACKGD]);
    gameState->graphics[1][BACKGD] = DerivationGraph(151, 0, 65, 29, gameState->spriteSheets[BACKGD]);
    gameState->graphics[2][BACKGD] = DerivationGraph(151, 31, 70, 40, gameState->spriteSheets[BACKGD]);
    gameState->graphics[3][BACKGD] = DerivationGraph(0, 91, 100, 90, gameState->spriteSheets[BACKGD]);
    gameState->graphics[4][BACKGD] = DerivationGraph(151, 113, 51, 29, gameState->spriteSheets[BACKGD]);
    gameState->graphics[5][BACKGD] = DerivationGraph(222, 0, 28, 60, gameState->spriteSheets[BACKGD]);
    gameState->graphics[6][BACKGD] = DerivationGraph(151, 143, 90, 40, gameState->spriteSheets[BACKGD]);
    gameState->graphics[7][BACKGD] = DerivationGraph(151, 184, 60, 30, gameState->spriteSheets[BACKGD]); // pipe top
    gameState->graphics[8][BACKGD] = DerivationGraph(151, 217, 50, 29, gameState->spriteSheets[BACKGD]); // pipe bottom
    gameState->graphics[30][BACKGD] = DerivationGraph(293, 0, 149, 90, gameState->spriteSheets[BACKGD]);
    gameState->graphics[31][BACKGD] = DerivationGraph(293, 92, 64, 29, gameState->spriteSheets[BACKGD]);

    //中間フラグ
    gameState->graphics[20][BACKGD] = DerivationGraph(40, 182, 40, 60, gameState->spriteSheets[BACKGD]);

    //グラ
    gameState->graphics[0][BLOCKS2] = DerivationGraph(167, 0, 45, 45, gameState->spriteSheets[BONUS]);

    //敵サイズ収得
    // int GrHandle=0;
    for (i = 0; i <= 140; i++) {
        if (gameState->graphics[i][ENEMIES]) {
            anx[i] = gameState->graphics[i][ENEMIES]->w;
            any[i] = gameState->graphics[i][ENEMIES]->h;
            // GetGraphSize(gameState->graphics[i][x1] ,&anx[i] ,&any[i]);
            anx[i] *= 100;
            any[i] *= 100;
        } else {
            anx[i] = 0;
            any[i] = 0;
        }
    }
    anx[79] = 120 * 100;
    any[79] = 15 * 100;
    anx[85] = 25 * 100;
    any[85] = 30 * 10 * 100;

    //背景サイズ収得
    for (i = 0; i < 40; i++) {
        if (gameState->graphics[i][BACKGD]) {
            ne[i] = gameState->graphics[i][BACKGD]->w;
            nf[i] = gameState->graphics[i][BACKGD]->h;
            // GetGraphSize(gameState->graphics[i][x1] ,&ne[i] ,&nf[i]);
            // ne[i]*=100;nf[i]*=100;
        } else {
            ne[i] = 0;
            nf[i] = 0;
        }
    }

    // ogg読み込み ;
    gameState->music[1] = LoadMusicMem("BGM/field.ogg");   // 50
    gameState->music[2] = LoadMusicMem("BGM/dungeon.ogg"); // 40
    gameState->music[3] = LoadMusicMem("BGM/star4.ogg");   // 50
    gameState->music[4] = LoadMusicMem("BGM/castle.ogg");  // 50
    gameState->music[5] = LoadMusicMem("BGM/puyo.ogg");    // 50
    // ChangeVolumeSoundMem(50, gameState->music[6]);

    gameState->sounds[1] = LoadSoundMem("SE/jump.ogg");
    gameState->sounds[2] = LoadSoundMem("SE/brockcoin.ogg");
    gameState->sounds[3] = LoadSoundMem("SE/brockbreak.ogg");
    gameState->sounds[4] = LoadSoundMem("SE/coin.ogg");
    gameState->sounds[5] = LoadSoundMem("SE/humi.ogg");
    gameState->sounds[6] = LoadSoundMem("SE/koura.ogg");
    gameState->sounds[7] = LoadSoundMem("SE/dokan.ogg");
    gameState->sounds[8] = LoadSoundMem("SE/brockkinoko.ogg");
    gameState->sounds[9] = LoadSoundMem("SE/powerup.ogg");
    gameState->sounds[10] = LoadSoundMem("SE/kirra.ogg");
    gameState->sounds[11] = LoadSoundMem("SE/goal.ogg");
    gameState->sounds[12] = LoadSoundMem("SE/death.ogg");
    gameState->sounds[13] = LoadSoundMem("SE/Pswitch.ogg");
    gameState->sounds[14] = LoadSoundMem("SE/jumpBlock.ogg");
    gameState->sounds[15] = LoadSoundMem("SE/hintBlock.ogg");
    gameState->sounds[16] = LoadSoundMem("SE/4-clear.ogg");
    gameState->sounds[17] = LoadSoundMem("SE/allclear.ogg");
    gameState->sounds[18] = LoadSoundMem("SE/tekifire.ogg");

    //ループ設定-20000-20秒
    // SetLoopPosSoundMem( 1,gameState->sounds[104]) ;
    // SetLoopSamplePosSoundMem(44100,gameState->sounds[104]);
    // SetLoopSamplePosSoundMem(22050,gameState->sounds[104]);
}

//終了
void deinit() {
    int i, j;
    SDL_FillRect(screen, 0, 0x000000); // black
    DrawString(200, 200, "EXITING...", SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_Flip(screen);

    // SURFACES
    for (i = 0; i < 51; i++)
        SDL_FreeSurface(gameState->spriteSheets[i]);

    for (i = 0; i < 161; i++)
        for (j = 0; j < 8; j++)
            SDL_FreeSurface(gameState->graphics[i][j]);
    //--

    // SOUNDS
    for (i = 1; i < 6; i++)
        Mix_FreeMusic(gameState->music[i]);
    for (i = 1; i < 19; i++)
        Mix_FreeChunk(gameState->sounds[i]);
    //--

    // Font
    for (i = 0; i < FONT_MAX; i++)
        TTF_CloseFont(font[i]);

    // Joystick
    SDL_JoystickClose(joystick);

    // Close libraries
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}

void deinitGraphics() {}

void parseArgs(int argc, char *argv[]) {
    if (argc <= 1)
        return;
    for (int i = 0; i < argc; i++) {
        if (!strcasecmp(argv[i], "-nosound"))
            sound = false;
    }
}
