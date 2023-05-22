#include "mahjong.hpp"

int main(){
    int pinzu[9],c_pinzu[9],c1_pinzu[9];
    int manzu[9],c_manzu[9],c1_manzu[9];
    int souzu[9],c_souzu[9],c1_souzu[9];
    int jihai[7],c_jihai[7],c1_jihai[7];
    bool haipai_syuntu[34];
    bool agari[34];
    for(int i = 0; i< 34; i++){
        agari[i] = false;
        haipai_syuntu[i] = false;
    }

    pinzu[0] = 1;
    pinzu[1] = 1;
    pinzu[2] = 1;
    pinzu[3] = 1;
    pinzu[4] = 3;
    pinzu[5] = 3;
    pinzu[6] = 1;
    pinzu[7] = 2;
    pinzu[8] = 0;

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
            show(c_pinzu,c_manzu,c_souzu,c_jihai);
            cout << endl;
        }
        for(int i = 0; i < 34 ; i++){
            if(find_jyantou(i,c_pinzu,c_manzu,c_souzu,c_jihai)){
                copy_haipai(c_pinzu,c_manzu,c_souzu,c_jihai,c1_pinzu,c1_manzu,c1_souzu,c1_jihai);
                delete_jyantou(i,c1_pinzu,c1_manzu,c1_souzu,c1_jihai);
                for(int k = 0; k < 34; j ++){
                    if(find_syuntu(k,c1_pinzu,c1_manzu,c1_souzu,c1_jihai)){
                        haipai_syuntu[k] = true;
                    }
                }
                for(int j = 0;j < 34; j++){
                    if(haipai_syuntu[j] == true){
                        delete_syuntu(j,c1_pinzu,c1_manzu,c1_souzu,c1_jihai);
                        count_mentu ++;
                    }
                    if(find_coutu(j,c1_pinzu,c1_manzu,c1_souzu,c1_jihai)){
                        count_mentu ++;
                        // cout << count_mentu << endl;
                    }
                }
                for(int j = 0;j<34;j++){
                    if(find_syuntu(j,c1_pinzu,c1_manzu,c1_souzu,c1_jihai)){
                        count_mentu ++;
                        // cout << count_mentu << endl;
                    }
                }
                if(count_mentu == 4){
                    cout << "聴牌" << endl;
                    agari[j] = true;
                }else{
                    cout << "ノーテン" << endl;
                }
                cout << endl;
            }
            count_mentu = 0;
            // find_syuntu(i,pinzu,manzu,souzu,jihai);
            
        }
    }
    for(int i = 0; i < 34; i ++){
        if(agari[i]) cout << i+1 << " ";
    }
    cout << endl;
}