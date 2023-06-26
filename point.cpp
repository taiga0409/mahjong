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
void yakuhai(vector<int> coutu,int bakaze,int jikaze, int *han){
    for(int i : coutu){
        if(i == 31 ) {
            cout << "白" << endl;
            *han = *han + 1;
        }
        if(i == 32){
            cout << "發" << endl;
            *han = *han + 1;
        }
        if(i == 33){
            cout << "中" << endl;
            *han = *han + 1;
        }
        if(i == jikaze){
            cout << "自風牌" << endl;
            *han = *han + 1;
        }
        if(i == bakaze){
            cout << "場風牌" << endl;
            *han = *han + 1;
        }
    }
}
void haitei(bool haitei, int *han){
    if(haitei){
        cout << "海底撈月" << endl;
        *han = *han + 1;
    }
}
void houtei(bool houtei , int *han){
    if(houtei){
        cout << "河底撈魚" << endl;
        *han = *han + 1;
    }
}
void rinsyan(bool rinsyan, int *han){
    if(rinsyan){
        cout << "嶺上開花" << endl;
        *han = *han + 1;
    }
}
void tyankan(bool tyankan, int *han){
    if(tyankan){
        cout << "槍槓" << endl;
        *han = *han + 1;
    }
}
// void pinhu(vector<int> syuntu)
