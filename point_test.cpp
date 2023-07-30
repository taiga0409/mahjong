#include "point.hpp"
#include "mahjong.hpp"

int main(){
    vector<int> syuntu = {14,4};// g++ -std=c++11 -o
    vector<int> anko = {2,3};
    vector<int> minko = {};
    vector<int> ankan = {};
    vector<int> minkan = {};
    int jyantou = 11;
    int tumo = 9;
    int mati = 1; //リャンメン待ち
    int jikaze = 29; //自風 : 西
    int bakaze = 27; //場風 : 東
    int dora = 25;
    int uradora = 19;
    bool menzen = false;
    bool B_tumo = false;
    bool B_reach = false;
    bool B_ippatu = false;
    bool B_haitei = false;
    bool B_houtei = false;
    bool B_rinsyan = false;
    bool B_tyankan = false;
    bool B_daburi = false;

    int han = 0;

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
    double_reach(B_daburi,&han);
    toitoi(anko,minko,ankan,minkan,&han);
    san_anko(anko,ankan,&han);
    sansyoku_doukou(anko,minko,ankan,minkan,&han);
    sansyoku_doujyun(menzen,syuntu,&han);
    honroutou(jyantou,anko,minko,ankan,minkan,&han);
    tyanta(menzen,jyantou,syuntu,anko,minko,ankan,minkan,&han);
    syousangen(jyantou,anko,minko,ankan,minkan,&han);
    sankantu(ankan,minkan,&han);
    ikkituukan(syuntu,menzen,&han);
    somete_pinzu(menzen,jyantou,syuntu,anko,minko,ankan,minkan,&han);
    somete_manzu(menzen,jyantou,syuntu,anko,minko,ankan,minkan, &han);
    somete_souzu(menzen,jyantou,syuntu,anko,minko,ankan,minkan,&han);
    jyuntyan(menzen,jyantou,syuntu,anko,minko,ankan,minkan,&han);
    //
    int hu = calculate_hu(mati,B_tumo,menzen,bakaze,jikaze,jyantou,anko,minko,ankan,minkan);
    cout << hu << endl;

    show_han(han);
    int point = calculate_point(jikaze,han,hu);
    cout << point << endl;

}