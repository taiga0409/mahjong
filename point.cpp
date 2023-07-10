#include "point.hpp"

//１飜
void find_tumo(bool tumo,bool menzen, int *han){
    if(tumo && menzen){
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
void tanyao(vector<int> syuntu, vector<int> anko, vector<int> minko,
            vector<int> ankan, vector<int> minkan,int jyantou, int *han){
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
        if(!find_tanyao(anko)){
            tanyao = false;
        }
    }
    if(tanyao){
        if(!find_tanyao(minko)){
            tanyao = false;
        }
    }
    if(tanyao){
        if(!find_tanyao(ankan)){
            tanyao = false;
        }
    }
    if(tanyao){
        if(!find_tanyao(minkan)){
            tanyao = false;
        }
    }
    if(tanyao){
        cout << "タンヤオ" << endl;
        *han = *han + 1;
    }
}
bool find_tanyao(vector<int> array){
    for(int i : array){
        if(i >= 27){
            return false;
        }
        if(i % 9 == 0 || i % 9 == 8){
            return false;
        }
    }
    return true;
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
void find_yakuhai(vector<int> coutu,int bakaze,int jikaze, int *han){
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
void yakuhai(vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan,
            int bakaze, int jikaze, int *han){
                find_yakuhai(anko,bakaze,jikaze,han);
                find_yakuhai(minko,bakaze,jikaze,han);
                find_yakuhai(ankan,bakaze,jikaze,han);
                find_yakuhai(minko,bakaze,jikaze,han);
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
void pinhu(vector<int> syuntu,bool menzen,int jyantou,int bakaze, int jikaze,int mati,int *han){
    if(syuntu.size() == 4 && menzen){
        if(jyantou !=jikaze && jyantou != bakaze ){
            if(jyantou < 31){//三元牌以外
                if(mati == 4){
                    cout << "平和" << endl;
                    *han = *han + 1;
                }
            }
        }
    }
}
void dora(int dora,vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan,int *han){
    int dora_num = 0;
    bool choise = false;
    for(int i : syuntu){
        if(dora < 27){
            if(dora - i >= 0 && dora - i < 3){
                choise = true;
                dora_num ++;
            }
        }
    }
    find_dora_coutu(dora,&dora_num,&choise,anko);
    find_dora_coutu(dora,&dora_num,&choise,minko);
    find_dora_kan(dora,&dora_num, &choise,ankan);
    find_dora_kan(dora,&dora_num,&choise,minko);

    if(choise){
        cout << "ドラ " << dora_num << endl;
        *han = *han + dora_num;
    }
}
void uradora(int uradora,vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan,vector<int> minka , int *han){
    int uradora_num = 0;
    bool choise = false; 
    for(int i : syuntu){
        if(uradora < 27){
            if(uradora - i >= 0 && uradora - i < 3){
                choise = true;
                uradora_num ++;
            }
        }
    }
    find_dora_coutu(uradora,&uradora_num,&choise,anko);
    find_dora_coutu(uradora,&uradora_num,&choise,minko);
    find_dora_kan(uradora,&uradora_num, &choise,ankan);
    find_dora_kan(uradora,&uradora_num,&choise,minko);

    if(choise){
        cout << "裏ドラ" << uradora_num << endl;
        *han = *han + uradora_num;
    }
}
void find_dora_coutu(int dora,int *dora_num,bool *choise,vector<int> array){
    for(int i : array){
        if(dora == i){
            *dora_num = *dora_num + 3;
            *choise = true;
            break;
        }
    }
}
void find_dora_kan(int dora, int *dora_num,bool *choise,vector<int> array){
    for(int i : array){
        if(dora == i){
            *dora_num = *dora_num + 4;
            *choise = true;
            break;
        }
    }
}

//2飜
void double_reach(bool daburi, int *han){
    if(daburi){
        cout << "ダブルリーチ" << endl;
        *han = *han + 2;
    }
}
void toitoi(vector<int> anko,vector<int> minko,vector<int> ankan,vector<int> minkan,int*han){
    int a = anko.size() + minko.size() + ankan.size() + minkan.size();
    if(a == 4){
        cout << "トイトイ" << endl;
        *han = *han + 2;
    }
}
void sa_anko(vector<int> anko, vector<int> ankan, int *han){
    int a = anko.size() + ankan.size();
    if(a == 4){
        cout << "三暗刻" << endl;
        *han = *han + 2;
    }
}
void sansyoku_doukou(vector<int> anko, vector<int> minko,vector<int> ankan, vector<int> minkan,int *han){
    int a = anko.size() + minko.size() + ankan.size() + minkan.size();
    vector<int> num(0);
    if(a >= 3){
        for(int i : anko){
            if(i < 27){
                num.push_back(i%9);
            }
        }
        for(int i : minko){
            if(i < 27){
                num.push_back(i%9);
            }
        }
        for(int i : ankan){
            if(i < 27){
                num.push_back(i%9);
            }
        }
        for(int i : minkan){
            if(i < 27){
                num.push_back(i%9);
            }
        }
    }
    int count_num;
    for(int i = 0; i < 2;i++){
        count_num = count(num.begin(),num.end(),num.at(i));
        if(count_num == 3){
            cout << "三色同刻" << endl;
            *han = *han + 2;
            break;
        }
    }
   
    
}
void sansyoku_doukou(bool menzen, vector<int> syuntu, int *han){
    vector<int> num(0);
    if(syuntu.size() >= 3){
        for(int i : syuntu){
            num.push_back(i);
        }
    }
}
