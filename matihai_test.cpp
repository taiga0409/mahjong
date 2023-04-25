#include "mahjong.hpp"

int main(){
    int pinzu[9],c_pinzu[9];
    int manzu[9],c_manzu[9];
    int souzu[9],c_souzu[9];
    int jihai[7],c_jihai[7];

    pinzu[0] = 2;
    pinzu[1] = 2;
    pinzu[2] = 2;
    pinzu[3] = 0;
    pinzu[4] = 0;
    pinzu[5] = 0;
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
    souzu[8] = 2;

    jihai[0] = 2;
    jihai[1] = 0;
    jihai[2] = 0;
    jihai[3] = 0;
    jihai[4] = 0;
    jihai[5] = 0;
    jihai[6] = 0;

    int count_mentu = 0;

    for(int i = 0; i < 34 ; i++){
        if(find_jyantou(i,pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai)){
            for(int j = 0;j < 34; j++){
                if(find_coutu(j,c_pinzu,c_manzu,c_souzu,c_jihai)){
                    count_mentu ++;
                    // cout << count_mentu << endl;
                }
            }
            for(int j = 0;j<34;j++){
                if(find_syuntu(j,c_pinzu,c_manzu,c_souzu,c_jihai)){
                    count_mentu ++;
                    // cout << count_mentu << endl;
                }
            }
            if(count_mentu == 3){
                for(int j = 0; j < 34; j ++){
                    find_matihai(j,c_pinzu,c_manzu,c_souzu,c_jihai);
                }
            }else{
                cout << "ノーテン" << endl;
            }
            cout << endl;
        }
        count_mentu = 0;
        // find_syuntu(i,pinzu,manzu,souzu,jihai);
        
    }
}