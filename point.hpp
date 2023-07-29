#include <iostream>
#include <vector>

using namespace std;


void find_mati(int *mati,int tumo, vector<int> syuntu, vector<int> anko, vector<int> minko,int jyantou);

//１飜
void find_tumo(bool tumo,bool menzen,int *han);
void reach(bool reach, int *han);
void ippatu(bool ippatu, int *han);
void tanyao(vector<int> syuntu,vector<int> anko,vector<int> minko,
            vector<int> ankan, vector<int> minkan,int jyantou, int *han);
bool find_tanyao(vector<int> array);
void pinhu(vector<int> syuntu,bool menzen, int jyantou,int bakaze, int jikaze,int mati, int *han);
void peikou(vector<int> syuntu , int *han);
void find_yakuhai(vector<int> coutu,int bakaze, int jikaze, int *han);
void yakuhai(vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan,
            int bakaze, int jikaze, int *han);
void haitei(bool haitei, int *han);
void houtei(bool houtei, int *han);
void rinsyan(bool rinsyan, int *han);
void tyankan(bool tyankan, int *han);
void dora(int dora,vector<int> syuntu,vector<int> anko,vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);
void find_dora_coutu(int dora, int *dora_num,bool *choise, vector<int>array);
void find_dora_kan(int dora,int *dora_num,bool *choise, vector<int> array);
void uradora(int uradora, vector<int> syuntu,vector<int> anko, vector<int> minko,vector<int> ankan, vector<int> minkan, int *han);

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
void honitu_pinzu(bool menzen,int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);
void honitu_manzu(bool menzen,int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);
void honitu_souzu(bool menzen,int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han);
void jyuntyan(bool menzen, int jyantou, vector<int>syuntu, vector<int> anko,vector<int> minko,vector<int> ankan,vector<int> minkan,int *han);
void chinitu_pinzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko,vector<int> ankan,vector<int> minkan, int *han);
void chinitu_manzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko,vector<int> ankan,vector<int> minkan, int *han);
void chinitu_souzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko,vector<int> ankan,vector<int> minkan, int *han);
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


