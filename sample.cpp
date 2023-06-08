#include "mahjong.hpp"

void find_mentu(int *pinzu, int*manzu, int *souzu, int *jihai){
    bool haipai[34];
    int count_mentu ;
    for(int i = 0; i < 34; i++){
        haipai[i] = false;
    }
    for(int i = 0;i < 34;i++){
        if(find_coutu(i,pinzu,manzu,souzu,jihai)){
            haipai[i] = true;
            
        }
    }
    for(int i = 0; i < 34; i++){
        if(haipai[i]){
            delete_coutu(i,pinzu,manzu,souzu,jihai);
            haipai[i] = false;
        }else{

        }
    }
    
}