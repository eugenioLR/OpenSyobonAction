#include "DxLib.h"

extern SDL_Surface *grap[161][8];
extern SDL_Surface *mgrap[51];
extern Mix_Music *otom[6];
extern Mix_Chunk *oto[19];

extern int anx[160], any[160];
extern int ne[40], nf[40];

#define PLAYER 0
#define BLOCKS 1
#define ITEMS 2
#define ENEMIES 3
#define BACKGD 4
#define BLOCKS2 5
#define BONUS 6
#define BONUS2 7
#define TITLE 30

void loadg(void) {
    int t;

    for (t = 0; t < 51; t++) {
        mgrap[t] = 0;
    }

    for (int i = 0; i < 161; i++)
        for (int j = 0; j < 8; j++)
            grap[i][j] = NULL;

    // ma-=100;//mb==5000;
    // end();

    //画像読み込み

    // 透過色を変更
    // SetTransColor( 9*16+9 , 255 , 255 ) ;

    //プレイヤー
    mgrap[PLAYER] = loadimage("res/player.PNG");
    //ブロック
    mgrap[BLOCKS] = loadimage("res/brock.PNG");
    //アイテム
    mgrap[ITEMS] = loadimage("res/item.PNG");
    //敵
    mgrap[ENEMIES] = loadimage("res/teki.PNG");
    //背景
    mgrap[BACKGD] = loadimage("res/haikei.PNG");
    //ブロック2
    mgrap[BLOCKS2] = loadimage("res/brock2.PNG");
    //おまけ
    mgrap[BONUS] = loadimage("res/omake.PNG");
    //おまけ2
    mgrap[BONUS2] = loadimage("res/omake2.PNG");
    //タイトル
    mgrap[TITLE] = loadimage("res/syobon3.PNG");

    //プレイヤー読み込み
    grap[40][PLAYER] = loadimageCut(0, 0, 30, 36, mgrap[PLAYER]);
    grap[0][PLAYER] = loadimageCut(31 * 4, 0, 30, 36, mgrap[PLAYER]);
    grap[1][PLAYER] = loadimageCut(31 * 1, 0, 30, 36, mgrap[PLAYER]);
    grap[2][PLAYER] = loadimageCut(31 * 2, 0, 30, 36, mgrap[PLAYER]);
    grap[3][PLAYER] = loadimageCut(31 * 3, 0, 30, 36, mgrap[PLAYER]);
    grap[41][PLAYER] = loadimageCut(50, 0, 51, 73, mgrap[BONUS]);

    //ブロック読み込み
    for (t = 0; t <= 6; t++) {
        grap[t][BLOCKS] = loadimageCut(33 * t, 0, 30, 30, mgrap[BLOCKS]);
        grap[t + 30][BLOCKS] = loadimageCut(33 * t, 33, 30, 30, mgrap[BLOCKS]);
        grap[t + 60][BLOCKS] = loadimageCut(33 * t, 66, 30, 30, mgrap[BLOCKS]);
        grap[t + 90][BLOCKS] = loadimageCut(33 * t, 99, 30, 30, mgrap[BLOCKS]);
    }
    grap[8][BLOCKS] = loadimageCut(33 * 7, 0, 30, 30, mgrap[BLOCKS]);
    grap[16][BLOCKS] = loadimageCut(33 * 6, 0, 24, 27, mgrap[2]);
    grap[10][BLOCKS] = loadimageCut(33 * 9, 0, 30, 30, mgrap[BLOCKS]);
    grap[40][BLOCKS] = loadimageCut(33 * 9, 33, 30, 30, mgrap[BLOCKS]);
    grap[70][BLOCKS] = loadimageCut(33 * 9, 66, 30, 30, mgrap[BLOCKS]);
    grap[100][BLOCKS] = loadimageCut(33 * 9, 99, 30, 30, mgrap[BLOCKS]);

    //ブロック読み込み2
    for (t = 0; t <= 6; t++) {
        grap[t][BLOCKS2] = loadimageCut(33 * t, 0, 30, 30, mgrap[BLOCKS2]);
    }
    grap[10][BLOCKS2] = loadimageCut(33 * 1, 33, 30, 30, mgrap[BLOCKS2]);
    grap[11][BLOCKS2] = loadimageCut(33 * 2, 33, 30, 30, mgrap[BLOCKS2]);
    grap[12][BLOCKS2] = loadimageCut(33 * 0, 66, 30, 30, mgrap[BLOCKS2]);
    grap[13][BLOCKS2] = loadimageCut(33 * 1, 66, 30, 30, mgrap[BLOCKS2]);
    grap[14][BLOCKS2] = loadimageCut(33 * 2, 66, 30, 30, mgrap[BLOCKS2]);

    //アイテム読み込み
    for (t = 0; t <= 5; t++) {
        grap[t][ITEMS] = loadimageCut(33 * t, 0, 30, 30, mgrap[ITEMS]);
    }

    //敵キャラ読み込み
    grap[0][ENEMIES] = loadimageCut(33 * 0, 0, 30, 30, mgrap[ENEMIES]);
    grap[1][ENEMIES] = loadimageCut(33 * 1, 0, 30, 43, mgrap[ENEMIES]);
    grap[2][ENEMIES] = loadimageCut(33 * 2, 0, 30, 30, mgrap[ENEMIES]);
    grap[3][ENEMIES] = loadimageCut(33 * 3, 0, 30, 44, mgrap[ENEMIES]);
    grap[4][ENEMIES] = loadimageCut(33 * 4, 0, 33, 35, mgrap[ENEMIES]);
    grap[5][ENEMIES] = loadimageCut(0, 0, 37, 55, mgrap[BONUS2]);
    grap[6][ENEMIES] = loadimageCut(38 * 2, 0, 36, 50, mgrap[BONUS2]);
    grap[150][ENEMIES] = loadimageCut(38 * 2 + 37 * 2, 0, 36, 50, mgrap[BONUS2]);
    grap[7][ENEMIES] = loadimageCut(33 * 6 + 1, 0, 32, 32, mgrap[ENEMIES]);
    grap[8][ENEMIES] = loadimageCut(38 * 2 + 37 * 3, 0, 37, 47, mgrap[BONUS2]);
    grap[151][ENEMIES] = loadimageCut(38 * 3 + 37 * 3, 0, 37, 47, mgrap[BONUS2]);
    grap[9][ENEMIES] = loadimageCut(33 * 7 + 1, 0, 26, 30, mgrap[ENEMIES]);
    grap[10][ENEMIES] = loadimageCut(214, 0, 46, 16, mgrap[BONUS]);

    //モララー
    grap[30][ENEMIES] = loadimageCut(0, 56, 30, 36, mgrap[BONUS2]);
    grap[155][ENEMIES] = loadimageCut(31 * 3, 56, 30, 36, mgrap[BONUS2]);
    grap[31][ENEMIES] = loadimageCut(50, 74, 49, 79, mgrap[BONUS]);

    grap[80][ENEMIES] = loadimageCut(151, 31, 70, 40, mgrap[BACKGD]);
    grap[81][ENEMIES] = loadimageCut(151, 72, 70, 40, mgrap[BACKGD]);
    grap[130][ENEMIES] = loadimageCut(151 + 71, 72, 70, 40, mgrap[BACKGD]);
    grap[82][ENEMIES] = loadimageCut(33 * 1, 0, 30, 30, mgrap[BLOCKS2]);
    grap[83][ENEMIES] = loadimageCut(0, 0, 49, 48, mgrap[BONUS]);
    grap[84][ENEMIES] = loadimageCut(33 * 5 + 1, 0, 30, 30, mgrap[ENEMIES]);
    grap[86][ENEMIES] = loadimageCut(102, 66, 49, 59, mgrap[BONUS]);
    grap[87][ENEMIES] = loadimageCut(33 * 8 - 5, 0, 16, 16, mgrap[ENEMIES]); // fireball segment
    grap[152][ENEMIES] = loadimageCut(152, 66, 49, 59, mgrap[BONUS]);

    grap[90][ENEMIES] = loadimageCut(102, 0, 64, 63, mgrap[BONUS]);

    grap[100][ENEMIES] = loadimageCut(33 * 1, 0, 30, 30, mgrap[ITEMS]);
    grap[101][ENEMIES] = loadimageCut(33 * 7, 0, 30, 30, mgrap[ITEMS]);
    grap[102][ENEMIES] = loadimageCut(33 * 3, 0, 30, 30, mgrap[ITEMS]);

    // grap[104][ENEMIES] = loadimageCut( 33*2, 0, 30, 30, mgrap[BLOCKS2]) ;
    grap[105][ENEMIES] = loadimageCut(33 * 5, 0, 30, 30, mgrap[ITEMS]);
    grap[110][ENEMIES] = loadimageCut(33 * 4, 0, 30, 30, mgrap[ITEMS]);

    //背景読み込み
    grap[0][BACKGD] = loadimageCut(0, 0, 150, 90, mgrap[BACKGD]);
    grap[1][BACKGD] = loadimageCut(151, 0, 65, 29, mgrap[BACKGD]);
    grap[2][BACKGD] = loadimageCut(151, 31, 70, 40, mgrap[BACKGD]);
    grap[3][BACKGD] = loadimageCut(0, 91, 100, 90, mgrap[BACKGD]);
    grap[4][BACKGD] = loadimageCut(151, 113, 51, 29, mgrap[BACKGD]);
    grap[5][BACKGD] = loadimageCut(222, 0, 28, 60, mgrap[BACKGD]);
    grap[6][BACKGD] = loadimageCut(151, 143, 90, 40, mgrap[BACKGD]);
    grap[7][BACKGD] = loadimageCut(151, 184, 60, 30, mgrap[BACKGD]); // pipe top
    grap[8][BACKGD] = loadimageCut(151, 217, 50, 29, mgrap[BACKGD]); // pipe bottom
    grap[30][BACKGD] = loadimageCut(293, 0, 149, 90, mgrap[BACKGD]);
    grap[31][BACKGD] = loadimageCut(293, 92, 64, 29, mgrap[BACKGD]);

    //中間フラグ
    grap[20][BACKGD] = loadimageCut(40, 182, 40, 60, mgrap[BACKGD]);

    //グラ
    grap[0][BLOCKS2] = loadimageCut(167, 0, 45, 45, mgrap[BONUS]);

    //敵サイズ収得
    // int GrHandle=0;
    for (t = 0; t <= 140; t++) {
        if (grap[t][ENEMIES]) {
            anx[t] = grap[t][ENEMIES]->w;
            any[t] = grap[t][ENEMIES]->h;
            // GetGraphSize(grap[t][x1] ,&anx[t] ,&any[t]);
            anx[t] *= 100;
            any[t] *= 100;
        } else {
            anx[t] = 0;
            any[t] = 0;
        }
    }
    anx[79] = 120 * 100;
    any[79] = 15 * 100;
    anx[85] = 25 * 100;
    any[85] = 30 * 10 * 100;

    //背景サイズ収得
    for (t = 0; t < 40; t++) {
        if (grap[t][BACKGD]) {
            ne[t] = grap[t][BACKGD]->w;
            nf[t] = grap[t][BACKGD]->h;
            // GetGraphSize(grap[t][x1] ,&ne[t] ,&nf[t]);
            // ne[t]*=100;nf[t]*=100;
        } else {
            ne[t] = 0;
            nf[t] = 0;
        }
    }

    /*
    anx[0]=30;any[0]=30;
    anx[1]=30;any[1]=43;
    anx[2]=30;any[2]=30;
    anx[3]=30;any[3]=44;
    */

    // ogg読み込み
    // try{
    // oto[2] = LoadSoundMem( "SE/1.mp3" ) ;
    otom[1] = LoadMusicMem("BGM/field.ogg");   // 50
    otom[2] = LoadMusicMem("BGM/dungeon.ogg"); // 40
    otom[3] = LoadMusicMem("BGM/star4.ogg");   // 50
    otom[4] = LoadMusicMem("BGM/castle.ogg");  // 50
    otom[5] = LoadMusicMem("BGM/puyo.ogg");    // 50
    // otom[6]=LoadMusicMem( "BGM/last.ogg");
    // ChangeVolumeSoundMem(50, otom[6]);

    oto[1] = LoadSoundMem("SE/jump.ogg");
    oto[2] = LoadSoundMem("SE/brockcoin.ogg");
    oto[3] = LoadSoundMem("SE/brockbreak.ogg");
    oto[4] = LoadSoundMem("SE/coin.ogg");
    oto[5] = LoadSoundMem("SE/humi.ogg");
    oto[6] = LoadSoundMem("SE/koura.ogg");
    oto[7] = LoadSoundMem("SE/dokan.ogg");
    oto[8] = LoadSoundMem("SE/brockkinoko.ogg");
    oto[9] = LoadSoundMem("SE/powerup.ogg");
    oto[10] = LoadSoundMem("SE/kirra.ogg");
    oto[11] = LoadSoundMem("SE/goal.ogg");
    oto[12] = LoadSoundMem("SE/death.ogg");
    oto[13] = LoadSoundMem("SE/Pswitch.ogg");
    oto[14] = LoadSoundMem("SE/jumpBlock.ogg");
    oto[15] = LoadSoundMem("SE/hintBlock.ogg");
    oto[16] = LoadSoundMem("SE/4-clear.ogg");
    oto[17] = LoadSoundMem("SE/allclear.ogg");
    oto[18] = LoadSoundMem("SE/tekifire.ogg");

    //}catch( int num){end();}

    //ループ設定-20000-20秒
    // SetLoopPosSoundMem( 1,oto[104]) ;
    // SetLoopSamplePosSoundMem(44100,oto[104]);
    // SetLoopSamplePosSoundMem(22050,oto[104]);
}

extern bool sound;
void parseArgs(int argc, char *argv[]) {
    if (argc <= 1)
        return;
    for (int i = 0; i < argc; i++) {
        if (!strcasecmp(argv[i], "-nosound"))
            sound = false;
    }
}
