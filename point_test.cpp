#include "point.hpp"
#include "mahjong.hpp"

int main(){
    vector<int> syuntu = {1,12,14};// g++ -std=c++11 -o
    vector<int> anko = {};
    vector<int> minko = {};
    vector<int> ankan = {2};
    vector<int> minkan = {};
    int jyantou = 26;
    int tumo = 6;
    int mati = 4; //リャンメン待ち
    int han = 0;
    int jikaze = 28; //自風 : 南
    int bakaze = 27; //場風 : 東
    int dora = 3;
    int uradora = 2;
    bool menzen = true;
    bool B_tumo = true;
    bool B_reach = true;
    bool B_ippatu = false;
    bool B_haitei = false;
    bool B_houtei = false;
    bool B_rinsyan = false;
    bool B_tyankan = false;

    reach(B_reach,&han);
    find_tumo(B_tumo,menzen,&han);
    ippatu(B_ippatu,&han);
    tanyao(syuntu,anko,minko,ankan,minkan,jyantou,&han);
    pinhu(syuntu,menzen,jyantou,bakaze,jikaze,mati,&han);
    peikou(syuntu,menzen,&han);
    yakuhai(anko,minko,ankan,minkan,bakaze,jikaze,&han);
    haitei(B_haitei, &han);
    houtei(B_houtei,&han);
    rinsyan(B_rinsyan,&han);
    tyankan(B_tyankan, &han);
    dora_num(dora,syuntu,anko,minko,ankan,minkan,&han);
    uradora_num(uradora,syuntu,anko,minko,ankan,minkan,&han);
    //
    show_han(han);

}