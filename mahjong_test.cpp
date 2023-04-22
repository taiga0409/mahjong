#include "mahjong.hpp"


int main(){

    int pinzu[9];
    int manzu[9];
    int souzu[9];
    int jihai[7];

    pinzu[0] = 1;
    pinzu[1] = 1;
    pinzu[2] = 1;
    pinzu[3] = 1;
    pinzu[4] = 1;
    pinzu[5] = 1;
    pinzu[6] = 1;
    pinzu[7] = 1;
    pinzu[8] = 1;

    manzu[0] = 0;
    manzu[1] = 0;
    manzu[2] = 0;
    manzu[3] = 0;
    manzu[4] = 0;
    manzu[5] = 0;
    manzu[6] = 0;
    manzu[7] = 0;
    manzu[8] = 0;

    souzu[0] = 0;
    souzu[1] = 0;
    souzu[2] = 0;
    souzu[3] = 0;
    souzu[4] = 0;
    souzu[5] = 0;
    souzu[6] = 0;
    souzu[7] = 0;
    souzu[8] = 3;

    jihai[0] = 2;
    jihai[1] = 0;
    jihai[2] = 0;
    jihai[3] = 0;
    jihai[4] = 0;
    jihai[5] = 0;
    jihai[6] = 0;

    cout << souzu[8] << endl;

    if(count(pinzu,manzu,souzu,jihai)) 
    show(pinzu,manzu,souzu,jihai);
    for(int i = 0; i < 34 ; i++){
        find_mentu(i,pinzu,manzu,souzu,jihai);
        if(find_jyantou(i,pinzu,manzu,souzu,jihai)){
            // find_mentu(i,pinzu,manzu,souzu,jihai);
        }
        find_syuntu(i,pinzu,manzu,souzu,jihai);
        
    }
    return 0;
}