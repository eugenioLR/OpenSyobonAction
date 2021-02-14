#include "stageReader.h"

#define HEIGHT 17
#define LENGTH 1001
#define BUFFERSIZE 3000


void stageDataFromFile(char *filename, byte stageData[HEIGHT][LENGTH]){
    char line[BUFFERSIZE], *aux;
    FILE *file = fopen(filename, "r");
    for(int i = 0; i < HEIGHT; i++){
        if(fgets(line, BUFFERSIZE, file)){
            aux = strtok(line, ",");
        }else{
            aux = NULL;
        }

        for(int j = 0; j < LENGTH; j++){
            if(aux){
                stageData[i][j] = atoi(aux);
                aux = strtok(NULL, ",");
            }else{
                stageData[i][j] = 0;
            }
            //printf("%d ", stageData[i][j]); //debug
        }
        //printf("\n"); //debug
    }

}

void getStageData(int world, int level, int section, byte stageData[HEIGHT][LENGTH]){
    char filename[25];
    if((world == 1 && level == 3 && section == 6) || (world == 2 && level == 4 && (section == 10 || section == 12))){
        section = 0;
    }

    sprintf(filename, "stages/stage%d-%d-%d.stg", world, level, section);
    stageDataFromFile(filename, stageData);
}

/*
//debug
int main(){
    byte stageData[HEIGHT][LENGTH];
    getStageData(1,1,0,stageData);
}
*/
