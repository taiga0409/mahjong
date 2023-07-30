#include "agari.hpp"
#include "point.hpp"

int main() {
    int pinzu[9],c_pinzu[9];
    int manzu[9],c_manzu[9];
    int souzu[9],c_souzu[9];
    int jihai[7],c_jihai[7];
    
    pinzu[0] = 2;
    pinzu[1] = 2;
    pinzu[2] = 2;
    pinzu[3] = 2;
    pinzu[4] = 2;
    pinzu[5] = 2;
    pinzu[6] = 2;
    pinzu[7] = 0;
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

    vector<int> anko(0);
    vector<int> minko(0);
    vector<int> ankan(0);
    vector<int> minkan(0);
    vector<int> syuntu(0);

    int count_mentu = 0;
    int jyantou;
    int tumo;

    

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
                        tumo,jyantou);
        }
        // find_syuntu(i,pinzu,manzu,souzu,jihai);
        
    }
    return 0;
}

