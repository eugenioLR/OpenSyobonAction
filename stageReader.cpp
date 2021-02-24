#include "stageReader.h"

void stageDataFromFile(char *filename, byte stageData[STAGEHEIGHT][STAGELENGTH]) {
    char line[BUFFERSIZE], *aux;
    FILE *file = fopen(filename, "r");
    if(file){
        for (int i = 0; i < STAGEHEIGHT; i++) {
            if (fgets(line, BUFFERSIZE, file)) {
                aux = strtok(line, ",");
            } else {
                aux = NULL;
            }

            for (int j = 0; j < STAGELENGTH; j++) {
                if (aux) {
                    stageData[i][j] = atoi(aux);
                    aux = strtok(NULL, ",");
                } else {
                    stageData[i][j] = 0;
                }
                //printf("%d ", stageData[i][j]); //debug
            }
            //printf("\n"); //debug
        }
    }else{
        printf("Stage \"%s\" does not exist\n", filename);
        for (int i = 0; i < STAGEHEIGHT; i++) {
            for (int j = 0; j < STAGELENGTH; j++) {
                stageData[i][j] = 0;
            }
        }
    }
}

void getStageData(int world, int level, int section, byte stageData[STAGEHEIGHT][STAGELENGTH]) {
    char filename[25];
    if ((world == 1 && level == 3 && section == 6) || (world == 2 && level == 4 && (section == 10 || section == 12))) {
        section = 0;
    }

    sprintf(filename, "stages/stage%d-%d-%d.stg", world, level, section);
    stageDataFromFile(filename, stageData);
}

/*
//debug
int main(){
    byte stageData[STAGEHEIGHT][STAGELENGTH];
    getStageData(10,1,0,stageData);
}
*/
