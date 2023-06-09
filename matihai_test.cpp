#include "mahjong.hpp"
#include <vector>

int main(){
    int pinzu[9],c_pinzu[9],c1_pinzu[9];
    int manzu[9],c_manzu[9],c1_manzu[9];
    int souzu[9],c_souzu[9],c1_souzu[9];
    int jihai[7],c_jihai[7],c1_jihai[7];
    bool haipai_coutu[34];
    bool agari[34];
    for(int i = 0; i< 34; i++){
        agari[i] = false;
        haipai_coutu[i] = false;
    }

    pinzu[0] = 0;
    pinzu[1] = 0;
    pinzu[2] = 3;
    pinzu[3] = 1;
    pinzu[4] = 2;
    pinzu[5] = 1;
    pinzu[6] = 1;
    pinzu[7] = 4;
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
    souzu[8] = 0;

    jihai[0] = 0;
    jihai[1] = 0;
    jihai[2] = 0;
    jihai[3] = 0;
    jihai[4] = 0;
    jihai[5] = 0;
    jihai[6] = 0;

    int count_mentu = 0;
    for(int j = 0; j < 34; j ++){
        copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
        tumo(j,c_pinzu,c_manzu,c_souzu,c_jihai);
        if(count(c_pinzu,c_manzu,c_souzu,c_jihai)){
            show_tehai(c_pinzu,c_manzu,c_souzu,c_jihai);
            cout << endl;
        }else{
            break;
        }
            for(int i = 0; i < 34 ; i++){
            if(find_jyantou(i,c_pinzu,c_manzu,c_souzu,c_jihai)){
                count_mentu = 0;
                copy_haipai(c_pinzu,c_manzu,c_souzu,c_jihai,c1_pinzu,c1_manzu,c1_souzu,c1_jihai);
                delete_jyantou(i,c1_pinzu,c1_manzu,c1_souzu,c1_jihai);
                find_matihai(0,&count_mentu,j,agari,c1_pinzu,c1_manzu,c1_souzu,c1_jihai);
                
            }
            
            
            }
    }
    show_matihai(agari);
}