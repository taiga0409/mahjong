#include "mahjong.hpp"


int main(){

    int pinzu[9],c_pinzu[9];
    int manzu[9],c_manzu[9];
    int souzu[9],c_souzu[9];
    int jihai[7],c_jihai[7];

    pinzu[0] = 1;
    pinzu[1] = 1;
    pinzu[2] = 1;
    pinzu[3] = 1;
    pinzu[4] = 1;
    pinzu[5] = 1;
    pinzu[6] = 1;
    pinzu[7] = 1;
    pinzu[8] = 0;

    manzu[0] = 0;
    manzu[1] = 0;
    manzu[2] = 1;
    manzu[3] = 1;
    manzu[4] = 1;
    manzu[5] = 1;
    manzu[6] = 0;
    manzu[7] = 0;
    manzu[8] = 0;

    souzu[0] = 2;
    souzu[1] = 0;
    souzu[2] = 0;
    souzu[3] = 0;
    souzu[4] = 0;
    souzu[5] = 0;
    souzu[6] = 0;
    souzu[7] = 0;
    souzu[8] = 0;

    jihai[0] = 0;
    jihai[1] = 0;
    jihai[2] = 0;
    jihai[3] = 0;
    jihai[4] = 0;
    jihai[5] = 0;
    jihai[6] = 0;

    int count_mentu = 0;

    if(count(pinzu,manzu,souzu,jihai)) 
        show(pinzu,manzu,souzu,jihai);
    cout << endl;
    for(int i = 0; i < 34 ; i++){
        if(find_jyantou(i,pinzu,manzu,souzu,jihai)){
            count_mentu = 0;
            copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
            delete_jyantou(i,c_pinzu,c_manzu,c_souzu,c_jihai);
            find_matihai(0,&count_mentu,c_pinzu,c_manzu,c_souzu,c_jihai);
        }
        // find_syuntu(i,pinzu,manzu,souzu,jihai);
        
    }
    return 0;
}