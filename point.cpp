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
void sansyoku_doujyun(bool menzen, vector<int> syuntu, int *han){
    if(syuntu.size() >= 3){
        vector<int> num(0);
        bool a = true;
        int count = 0;
        for(int i = 0; i < syuntu.size();i++){
            for(int j = i + 1; j < syuntu.size();j++){
                if(syuntu.at(i) == syuntu.at(j)){
                    a = false;
                }
            }
            if(a){
                num.push_back(syuntu.at(i) % 9);
            }
            a = true;
            if(i == syuntu.size() - 1){
                num.push_back(syuntu.at(i) % 9);
            }
        }
        for(int i : num){
            for(int j : num){
                if(num.at(i) == num.at(j)){
                    count ++;
                }
            }
            if(count == 3){
                cout << "三色同順" << endl;
                if(menzen){
                    *han = *han + 2;
                }else{
                    *han = *han + 1;
                }
                break;
            }else{
                count = 0;
            }
        }
    }
}
bool find_yaotyu(vector<int> array){
    for(int i : array){
        if(!(array.at(i) >= 27 || array.at(i) % 9 == 0 || array.at(i) %9 == 8)){
            return false;
        }
    }
    return true;
}
void honroutou(int jyantou, vector<int> anko,vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    int num = anko.size() + minko.size() + ankan.size() + minkan.size();
    if(num == 4){
        if(jyantou >= 27 || jyantou % 9 == 0 || jyantou % 9 == 8){
            if(find_yaotyu(anko) && find_yaotyu(minko) && find_yaotyu(ankan) && find_yaotyu(minkan)){
                cout << "混老頭" << endl;
                *han = *han + 2;
            }
        }
    }
}
void tyanta(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    if(jyantou >= 27 || jyantou % 9 == 0 || jyantou % 9 == 8){
        if(find_yaotyu(anko) && find_yaotyu(minko) && find_yaotyu(ankan) && find_yaotyu(minkan)){
            for(int i : syuntu){
                if(!(syuntu.at(i) % 9 == 0 && syuntu.at(i) % 9 == 6 )){
                    break;
                }
            }
            cout << "チャンタ" << endl;
            if(menzen){
                *han = *han + 2;
            }else{
                *han = *han + 1;
            }
        }
    }
}
void syousangen(int jyantou, vector<int> anko, vector<int> minko, vector<int> ankan ,vector<int> minkan, int *han){
    int count = 0;
    bool syousangen = false;
    if(30 < jyantou && jyantou < 34) {
        count ++;
        syousangen = true;
        if(syousangen){
            for(int i : anko){
                if(30 < anko.at(i) && anko.at(i) < 34) count ++;
            }
            for(int i : minko){
                if(30 < minko.at(i) && minko.at(i) < 34) count ++;
            }
            for(int i : ankan){
                if(30 < ankan.at(i) && ankan.at(i) < 34) count ++;
            }
            for(int i : minkan){
                if(30 < minkan.at(i) && minkan.at(i) < 34) count ++;
            }
            if(count == 3){
                cout <<"小三元" << endl;
                *han = *han + 2;
            }
        }
    }
}
void sankantu(vector<int> ankan, vector<int> minkan, int *han){
    int num ;
    num = ankan.size() + minkan.size();
    if(num == 3){
        cout << "三槓子" << endl;
        *han = *han + 2;
    }
}
void ikkituukan(vector<int> syuntu, bool menzen, int *han){
    if(syuntu.size() >= 3){
        vector<int> num (0);
        bool a = true;
        bool choice = false;
        int count = 0;
        for(int i = 0; i < syuntu.size(); i++){
            for(int j = i + 1; j < syuntu.size();j++){
                if(syuntu.at(i) == syuntu.at(j)){
                    a = false;
                }
            }
            if(a){
                num.push_back(syuntu.at(i));
            }
            a = true;
            if(i == syuntu.size() - 1){
                num.push_back(syuntu.at(i));
            }
        }
        for(int i : num){
            if(syuntu.at(i) < 9 && syuntu.at(i) % 3 == 0){
                count ++;
            }
        }
        if(count == 3){
            choice = true;
        }
        count = 0;
        for(int i : num){
            if(8 < syuntu.at(i)&& syuntu.at(i) && syuntu.at(i) % 3 == 0){
                count ++;
            }
        }
        if(count == 3){
            choice = true;
        }
        count = 0;
        for(int i : num){
            if(17 < syuntu.at(i) && syuntu.at(i) < 27 && syuntu.at(i) % 3 == 0){
                count ++;
            }
        }
        if(count == 3){
            choice = true;
        }
        if(choice){
            cout << "一気通貫" << endl;
            if(menzen){
                *han = *han + 2;
            }else{
                *han = *han + 1;
            }
        }
    }
}
void honitu_pinzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    if((0 <= jyantou && jyantou <= 8)|| 27 <= jyantou){
        for(int i : syuntu){
            if(!(0 <= syuntu.at(i) && syuntu.at(i) <= 8)){
                return;
            }
        }
        for(int i : anko){
            if(!((0 <= anko.at(i) && anko.at(i) <= 8)|| 27 <= anko.at(i) )){
                return;
            }
        }
        for(int i : minko){
            if(!((0 <= anko.at(i) && anko.at(i) <= 8)|| 27 <= anko.at(i) )){
                return;
            }
        }
        for(int i : ankan){
            if(!((0 <= anko.at(i) && anko.at(i) <= 8)|| 27 <= anko.at(i) )){
                return;
            }
        }
        for(int i : minkan){
            if(!((0 <= anko.at(i) && anko.at(i) <= 8)|| 27 <= anko.at(i) )){
                return;
            }
        }
        cout << "混一色" << endl;
        if(menzen) *han = *han + 3;
        else *han = *han + 2;
       
    }
}
void honitu_manzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    if((9 <= jyantou && jyantou <= 17)|| 27 <= jyantou){
        for(int i : syuntu){
            if(!(9 <= syuntu.at(i) && syuntu.at(i) <= 17)){
                return;
            }
        }
        for(int i : anko){
            if(!((9 <= anko.at(i) && anko.at(i) <= 17)|| 27 <= anko.at(i) )){
                return;
            }
        }
        for(int i : minko){
            if(!((9 <= anko.at(i) && anko.at(i) <= 17)|| 27 <= anko.at(i) )){
                return;
            }
        }
        for(int i : ankan){
            if(!((9 <= anko.at(i) && anko.at(i) <= 17)|| 27 <= anko.at(i) )){
                return;
            }
        }
        for(int i : minkan){
            if(!((9 <= anko.at(i) && anko.at(i) <= 17)|| 27 <= anko.at(i) )){
                return;
            }
        }
        cout << "混一色" << endl;
        if(menzen) *han = *han + 3;
        else *han = *han + 2;
       
    }
}
void honitu_souzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    if((18 <= jyantou && jyantou <=26)|| 27 <= jyantou){
        for(int i : syuntu){
            if(!(18 <= syuntu.at(i) && syuntu.at(i) <= 8)){
                return;
            }
        }
        for(int i : anko){
            if(!((18 <= anko.at(i) && anko.at(i) <= 26)|| 27 <= anko.at(i) )){
                return;
            }
        }
        for(int i : minko){
            if(!((18 <= anko.at(i) && anko.at(i) <= 26)|| 27 <= anko.at(i) )){
                return;
            }
        }
        for(int i : ankan){
            if(!((18 <= anko.at(i) && anko.at(i) <= 26)|| 27 <= anko.at(i) )){
                return;
            }
        }
        for(int i : minkan){
            if(!((18 <= anko.at(i) && anko.at(i) <= 26)|| 27 <= anko.at(i) )){
                return;
            }
        }
        cout << "混一色" << endl;
        if(menzen) *han = *han + 3;
        else *han = *han + 2;
       
    }
}
void jyuntyan(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko,vector<int> ankan, vector<int> minkan, int *han){
    if(jyantou % 9 == 0 || jyantou % 9 == 8 ){
        for(int i : syuntu){
            if(!(syuntu.at(i) % 9 == 0 ||syuntu.at(i) % 9 == 6)){
                return;
            }
        }
        for(int i : anko){
            if(!((anko.at(i) % 9 == 0 || anko.at(i) % 9 == 8) && anko.at(i) < 27)){
                return;
            }
        }
        for(int i : minko){
            if(!((minko.at(i) % 9 == 0 || minko.at(i) % 9 == 8) && minko.at(i) < 27)){
                return;
            }
        }
        for(int i : ankan){
            if(!((ankan.at(i) % 9 == 0 || ankan.at(i) % 9 == 8) && ankan.at(i) < 27)){
                return;
            }
        }
        for(int i : minkan){
            if(!((minkan.at(i) % 9 == 0 || minkan.at(i) % 9 == 8) && minkan.at(i) < 27 )){
                return;
            }
        }
        cout << "純全帯么九" << endl;
        if(menzen) *han = *han + 3;
        else *han = *han + 2;
    }
}
void chinitu_pinzu(bool menzen, int jyantou,vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han ){
    if (jyantou < 9){
        for(int i : syuntu){
            if(!(syuntu.at(i) < 9)) return;
        }
        for(int i : anko){
            if(!(anko.at(i) < 9)) return;
        }
        for(int i : minko){
            if(!(minko.at(i) < 9)) return;
        }
        for(int i : ankan){
            if(!(ankan.at(i) < 9)) return;
        }
        for(int i : minkan){
            if(!(minkan.at(i) < 9)) return;
        }
        cout << "清一色" << endl;
        if(menzen){
            *han = *han + 6;
        }else{
            *han = *han + 5;
        }
    }
}
void chinitu_manzu(bool menzen, int jyantou, vector<int> syuntu , vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    if(8 < jyantou && jyantou < 18){
        for(int i : syuntu){
            if(!(8 < syuntu.at(i)&& syuntu.at(i) < 18)) return;
        }
        for(int i : anko){
            if(!(8 < anko.at(i) && anko.at(i) < 18 )) return;
        }
        for(int i : minko){
            if(!(8 < minko.at(i) && minko.at(i) > 18))return;
        }
        for(int i : ankan){
            if(!(8 < ankan.at(i) && ankan.at(i) > 18))return;
        }
        for(int i : minkan){
            if(!(8 < minkan.at(i) && minkan.at(i) > 18)) return;
        }
        cout << "清一色" << endl;
        if(menzen){
            *han = *han + 6;
        }else{
            *han = *han + 5;
        }
    }
}
void chinitu_souzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    if(17 < jyantou && jyantou < 27){
        for(int i : syuntu){
            if(!(17 < syuntu.at(i) && syuntu.at(i) < 27)) return;
        }
        for(int i : anko){
            if(!(17 < anko.at(i) && anko.at(i) < 27)) return;
        }
        for(int i : minko){
            if(!(17 < minko.at(i) && minko.at(i) < 27)) return;
        }
        for(int i : ankan){
            if(!(17 < ankan.at(i) && ankan.at(i) < 27)) return;
        }
        for(int i : minkan){
            if(!(17 < minkan.at(i) && minkan.at(i) < 27))return;
        }
        cout << "清一色" << endl;
        if(menzen){
            *han = *han + 6;
        }else {
            *han = *han + 5;
        }
    }
}