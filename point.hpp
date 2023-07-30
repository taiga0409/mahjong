#include <iostream>
#include <vector>

using namespace std;


void find_mati(int *mati,int tumo, vector<int> syuntu, vector<int> anko, vector<int> minko,int jyantou);

//１飜
void find_tumo(bool tumo,bool menzen,int *han); //OK
void reach(bool reach, int *han);//OK
void ippatu(bool ippatu, int *han);//OK
void tanyao(vector<int> syuntu,vector<int> anko,vector<int> minko,
            vector<int> ankan, vector<int> minkan,int jyantou, int *han); //OK
bool find_tanyao(vector<int> array);//OK
void pinhu(vector<int> syuntu,bool menzen, int jyantou,int bakaze, int jikaze,int mati, int *han);//OK
void peikou(vector<int> syuntu ,bool menzen, int *han);//OK
void find_yakuhai(vector<int> coutu,int bakaze, int jikaze, int *han);
void yakuhai(vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan,
            int bakaze, int jikaze, int *han);//OK
void haitei(bool haitei, int *han);//OK
void houtei(bool houtei, int *han);//OK
void rinsyan(bool rinsyan, int *han);//OK
void tyankan(bool tyankan, int *han);//OK
void dora_num(int dora,vector<int> syuntu,vector<int> anko,vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);//OK
void find_dora_coutu(int dora, int *dora_num,bool *choise, vector<int>array);
void find_dora_kan(int dora,int *dora_num,bool *choise, vector<int> array);
void uradora_num(int uradora, vector<int> syuntu,vector<int> anko, vector<int> minko,vector<int> ankan, vector<int> minkan, int *han);//OK

//２飜]
void double_reach(bool daburi,int *han);
void toitoi(vector<int> anko,vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);
void san_anko(vector<int> anko, vector<int> ankan, int *han);
void sansyoku_doukou(vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan,int *han);
void sansyoku_doujyun(bool menzen,vector<int> syuntu,int *han);
void honroutou(int jyantou,vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan,int *han);
void tyanta(bool menzen,int jyantou,vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);
void syousangen (int jyantou,vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan,int *han);
void sankantu(vector<int> ankan, vector<int> minkan,int *han);
void ikkituukan(vector<int> syuntu,bool menzen,int *han);
//void titoitu
//３飜以上
void somete_pinzu(bool menzen,int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);
void somete_manzu(bool menzen,int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);
void somete_souzu(bool menzen,int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);
void jyuntyan(bool menzen, int jyantou, vector<int>syuntu, vector<int> anko,vector<int> minko,vector<int> ankan,vector<int> minkan,int *han);
// void chinitu_pinzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko,vector<int> ankan,vector<int> minkan, int *han);
// void chinitu_manzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko,vector<int> ankan,vector<int> minkan, int *han);
// void chinitu_souzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko,vector<int> ankan,vector<int> minkan, int *han);
// void nagsimangan();
// 役満
void tenho(bool tenho, int *yakuman);
void tiho(bool tiho, int *yakuman);
void renho(bool tiho, int *yakuman);
void ryuuisou(int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *yakuman);
void daisangen(vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *yakuman);
void suusi(int jyantou, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *yakuman);
void tuisou(int jyantou, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *yakuman);
void suanko(int mati, vector<int> anko, vector<int> ankan, int *yakuman);
void tinroutou(int jyantou, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *yakuman);
void sukantu(vector<int> ankan, vector<int> minkan, int *yakuman);
//void kokusimusou
//void tyu-renpoutou

//その他

void show_han(int han);
int calculate_hu(int mati,bool tumo, bool menzen,int bakaze, int jikaze,int jyantou, vector<int> anko, vector<int> minko,vector<int> ankan,vector<int> minkan);
int calculate_point(int jikaze, int han, int hu);
   



