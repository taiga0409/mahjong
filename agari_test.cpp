#include "agari.hpp"
#include "point.hpp"

int main() {
    int pinzu[9],c_pinzu[9];
    int manzu[9],c_manzu[9];
    int souzu[9],c_souzu[9];
    int jihai[7],c_jihai[7];
    
    pinzu[0] = 0;//0
    pinzu[1] = 0;
    pinzu[2] = 0;
    pinzu[3] = 0;
    pinzu[4] = 0;
    pinzu[5] = 0;
    pinzu[6] = 0;
    pinzu[7] = 0;
    pinzu[8] = 0;

    manzu[0] = 0;//9
    manzu[1] = 0;
    manzu[2] = 0;
    manzu[3] = 0;
    manzu[4] = 0;
    manzu[5] = 0;
    manzu[6] = 0;
    manzu[7] = 0;
    manzu[8] = 0;

    souzu[0] = 0;//18
    souzu[1] = 0;
    souzu[2] = 0;
    souzu[3] = 0;
    souzu[4] = 0;
    souzu[5] = 0;
    souzu[6] = 0;
    souzu[7] = 0;
    souzu[8] = 0;

    jihai[0] = 0; //東27
    jihai[1] = 0; //南
    jihai[2] = 0; //西
    jihai[3] = 0; //北
    jihai[4] = 0; //白
    jihai[5] = 0; //發
    jihai[6] = 0; //中

    int tumo = 32;

    vector<int> anko(0);
    vector<int> minko(0);
    vector<int> ankan(0);
    vector<int> minkan(0);
    vector<int> syuntu(0);

    int count_mentu = 0;
    int jyantou;
    int point = 0;

    

    int han = 0;

    if(count(pinzu,manzu,souzu,jihai)) 
        show_tehai(pinzu,manzu,souzu,jihai);
    cout << endl;
    // if(find_chitoi(pinzu,manzu,souzu,jihai)){
    //     cout << "チートイツ" << endl;
    // }
    for(int i = 0; i < 34 ; i++){
        if(find_jyantou(i,pinzu,manzu,souzu,jihai)){
            count_mentu = 0;
            anko.clear();
            minko.clear();
            ankan.clear();
            minkan.clear();
            syuntu.clear();
            copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
            delete_jyantou(i,c_pinzu,c_manzu,c_souzu,c_jihai,&jyantou);
            find_matihai(0,&count_mentu,c_pinzu,c_manzu,c_souzu,c_jihai,
                        syuntu,anko,minko,ankan,minkan,
                        tumo,jyantou,&point);
        }
        // find_syuntu(i,pinzu,manzu,souzu,jihai);
        
    }
    cout << "最終得点:" << point << endl; 
    return 0;
}

