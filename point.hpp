#include <iostream>
#include <vector>

using namespace std;


void find_mati(int *mati,int tumo, vector<int> syuntu, vector<int> coutu,int jyantou);

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
void uradora(int uradora, vector<int> syuntu,vector<int> anko, vector<int> minko,vector<int> ankan, vector<int> minkan, int *han)


