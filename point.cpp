#include "point.hpp"

void find_tumo(bool tumo, int *han){
    if(tumo){
        cout << "ツモ" << endl;
        *han = *han + 1;
    }
}
void reach(bool reach, int *han){
    if(reach){
        cout << "リーチ" << endl;
        *han = *han + 1;
    }
}
void ippatu(bool ippatu, int *han){
    if(ippatu){
        cout << "一発" << endl;
        *han = *han + 1;
    }
}
void tanyao(vector<int> syuntu, vector<int> coutu, int jyantou, int *han){
    bool tanyao = true;
    if(jyantou >= 27 || jyantou % 9 == 0 || jyantou % 9 == 8)
        tanyao = false;
    if(tanyao){
        for(int i : syuntu){
            if(i >=27 ){
                tanyao = false;
                break; 
            }if(i % 9 == 0 || i % 9 == 6){
                tanyao = false;
                break;
            }
        }
    }
    if(tanyao){
        for(int i : coutu){
            if(i >= 27){
                tanyao = false;
                break;
            }
            if(i % 9 == 0 || i % 9 == 8){
                tanyao = false;
                break;
            }
        }
    }
    
    if(tanyao){
        cout << "タンヤオ" << endl;
        *han = *han + 1;
    }
}
void peikou(vector<int> syuntu, int *han){
    bool ipeikou = false;
    bool ryanpeikou = false;
    if(syuntu.size() > 1){
        for(int i = 0; i < syuntu.size()-1; i++){
            if(syuntu.at(i) == syuntu.at(i+1)){
                if(ipeikou){
                    if(syuntu.at(i-1) != syuntu.at(i)){
                        ryanpeikou = true;
                    }
                }
                ipeikou = true;
            }
        }
    }
    if(ryanpeikou){
        cout << "二盃口" << endl;
        *han = *han + 2;
    }else if (ipeikou){
        cout << "一盃口" << endl;
        *han = *han + 1;
    }
}
void yakuhai(vector<int> coutu, int *han){
    
}