#include <graphics.h>
#include <stdio.h>

#define ROWS 12
#define COLS 12

IMAGE road,wall;

void printMap(int map[ROWS][COLS]);
void drawMap();

int main(){
    int map[ROWS][COLS] = {
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1,1,1,1,1},
        {1,0,1,1,1,1,0,1,1,1,1,1},
        {1,0,1,1,1,1,0,1,1,1,1,1},
        {1,0,1,1,1,1,0,1,1,1,1,1},
        {1,0,1,1,1,1,0,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1},
    };

    printMap(map);
}

void printMap(int map[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++)
    {
        for(int j=0;j<COLS;j++){
            if(map[i][j]==1){
                printf("墙");
            }else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    
}

void drawMap(){

}