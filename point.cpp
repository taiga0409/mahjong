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
void peikou(vector<int> syuntu,bool menzen, int *han){
    if(menzen){
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
            *han = *han + 3;
        }else if (ipeikou){
            cout << "一盃口" << endl;
            *han = *han + 1;
        }
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
                find_yakuhai(minkan,bakaze,jikaze,han);
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
void dora_num(int dora,vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan,int *han){
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
void uradora_num(int uradora,vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan,vector<int> minka , int *han){
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
void san_anko(vector<int> anko, vector<int> ankan, int *han){
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
        for(int i = 0; i < anko.size();i++){
            if(i < 27){
                num.push_back(anko.at(i)%9);
            }
        }
        for(int i = 0; i < minko.size();i++){
            if(i < 27){
                num.push_back(minko.at(i)%9);
            }
        }
        for(int i = 0; i < ankan.size(); i++){
            if(i < 27){
                num.push_back(ankan.at(i)%9);
            }
        }
        for(int i = 0; i < minkan.size();i++){
            if(i < 27){
                num.push_back(minkan.at(i)%9);
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
   
    
}
void sansyoku_doujyun(bool menzen, vector<int> syuntu, int *han){
    if(syuntu.size() >= 3){
        vector<int> num;
        bool a = true;
        int count = 0;
        for(int i = 0; i < syuntu.size()-1;i++){
            for(int j = i + 1; j < syuntu.size();j++){
                if(syuntu.at(i) == syuntu.at(j)){
                    a = false;
                }
            }
            if(a){
                num.push_back(syuntu.at(i) % 9);
            }
            a = true;
        }
        num.push_back(syuntu.at(syuntu.size()-1)%9);
        // for(int i = 0; i < num.size(); i++){
        //     cout << num.at(i) << endl;
        // }
        for(int i = 0; i < num.size();i++){
            for(int j = 0; j < num.size(); j++){
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
    for(int i = 0;i < array.size() ;i++){
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
    if(syuntu.size() > 0){
        if(jyantou >= 27 || jyantou % 9 == 0 || jyantou % 9 == 8){
            if(find_yaotyu(anko) && find_yaotyu(minko) && find_yaotyu(ankan) && find_yaotyu(minkan)){
                for(int i = 0; i < syuntu.size(); i++ ){
                    if(!(syuntu.at(i) % 9 == 0 && syuntu.at(i) % 9 == 6 )){
                        return;
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
}
void syousangen(int jyantou, vector<int> anko, vector<int> minko, vector<int> ankan ,vector<int> minkan, int *han){
    int count = 0;
    bool syousangen = false;
    if(30 < jyantou && jyantou < 34) {
        count ++;
        syousangen = true;
        if(syousangen){
            for(int i = 0;i < anko.size();i++){
                if(30 < anko.at(i) && anko.at(i) < 34) count ++;
            }
            for(int i = 0; i < minko.size();i++){
                if(30 < minko.at(i) && minko.at(i) < 34) count ++;
            }
            for(int i = 0; i < ankan.size();i++){
                if(30 < ankan.at(i) && ankan.at(i) < 34) count ++;
            }
            for(int i = 0; i < minkan.size();i++){
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
        for(int i = 0; i < syuntu.size()-1; i++){
            for(int j = i + 1; j < syuntu.size();j++){
                if(syuntu.at(i) == syuntu.at(j)){
                    a = false;
                }
            }
            if(a){
                num.push_back(syuntu.at(i));
            }
            a = true;
        }
        num.push_back(syuntu.at(syuntu.size()-1));
        for(int i = 0; i < num.size();i++){
            if(syuntu.at(i) < 9 && syuntu.at(i) % 3 == 0){
                count ++;
            }
        }
        if(count == 3){
            choice = true;
        }
        count = 0;
        for(int i = 0; i < num.size(); i++){
            if(8 < syuntu.at(i)&& syuntu.at(i) && syuntu.at(i) % 3 == 0){
                count ++;
            }
        }
        if(count == 3){
            choice = true;
        }
        count = 0;
        for(int i = 0; i < num.size(); i++){
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
void somete_pinzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    bool tinitu = true;
    if((0 <= jyantou && jyantou <= 8)|| 27 <= jyantou){
        if(27 <= jyantou ) tinitu = false;
        for(int i = 0; i < syuntu.size();i++){
            if(!(0 <= syuntu.at(i) && syuntu.at(i) <= 8)){
                return;
            }
        }
        for(int i = 0; i < anko.size(); i++){
            if(!((0 <= anko.at(i) && anko.at(i) <= 8)|| 27 <= anko.at(i) )){
                return;
                if(27 <= anko.at(i) ) tinitu = false;
            }
        }
        for(int i = 0; i < minko.size();i++){
            if(!((0 <= minko.at(i) && minko.at(i) <= 8)|| 27 <= minko.at(i) )){
                return;
                if(27 <= minko.at(i) ) tinitu = false;
            }
        }
        for(int i = 0; i < ankan.size(); i ++){
            if(!((0 <= ankan.at(i) && ankan.at(i) <= 8)|| 27 <= ankan.at(i) )){
                return;
                if(27 <= ankan.at(i) ) tinitu = false;
            }
        }
        for(int i = 0; i < minkan.size();i++){
            if(!((0 <= minkan.at(i) && minkan.at(i) <= 8)|| 27 <= minkan.at(i) )){
                return;
                if(27 <= minkan.at(i) ) tinitu = false;
            }
        }
        if(tinitu){
            cout << "清一色" << endl;
            if(menzen) *han = *han + 6;
            else *han = *han + 5;
        }else{
            cout << "混一色" << endl;
            if(menzen) *han = *han + 3;
            else *han = *han + 2;
        }
    }
}
void somete_manzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    
    if((9 <= jyantou && jyantou <= 17)|| 27 <= jyantou){
        bool tinitu = true;
        if(27 <= jyantou ) tinitu = false;
        for(int i=0;i< syuntu.size();i++){
            if(!(9 <= syuntu.at(i) && syuntu.at(i) <= 17)){
                return;
            }
        }
        for(int i = 0; i < anko.size(); i++){
            if(!((9 <= anko.at(i) && anko.at(i) <= 17)|| 27 <= anko.at(i) )){
                return;
                if(27 <= anko.at(i)) tinitu = false;
            }
        }
        for(int i = 0; i < minko.size();i++){
            if(!((9 <= minko.at(i) && minko.at(i) <= 17)|| 27 <= minko.at(i) )){
                return;
                if(27 <= minko.at(i)) tinitu = false;
            }
        }
        for(int i = 0; i < ankan.size(); i++){
            if(!((9 <= ankan.at(i) && ankan.at(i) <= 17)|| 27 <= ankan.at(i) )){
                return;
                if(27 <= ankan.at(i)) tinitu = false;
            }
        }
        for(int i = 0;i < minkan.size(); i ++){
            if(!((9 <= minkan.at(i) && minkan.at(i) <= 17)|| 27 <= minkan.at(i) )){
                return;
                if(27 <= minkan.at(i)) tinitu = false;
            }
        }
       if(tinitu){
            cout << "清一色" << endl;
            if(menzen) *han = *han + 6;
            else *han = *han + 5;
        }else{
            cout << "混一色" << endl;
            if(menzen) *han = *han + 3;
            else *han = *han + 2;
        }
    }
}
void somete_souzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
    if((18 <= jyantou && jyantou <= 26)|| 27 <= jyantou){
        bool tinitu = true;
        if(27 <= jyantou) tinitu = false;
        for(int i=0;i< syuntu.size();i++){
            if(!(18 <= syuntu.at(i) && syuntu.at(i) <= 26)){
                return;
            }
        }
        for(int i = 0; i < anko.size(); i++){
            if(!((18 <= anko.at(i) && anko.at(i) <= 26)|| 27 <= anko.at(i) )){
                return;
                if(27 <= anko.at(i)) tinitu = false;
            }
        }
        for(int i = 0; i < minko.size();i++){
            if(!((18 <= minko.at(i) && minko.at(i) <= 26)|| 27 <= minko.at(i) )){
                return;
                if(27 <= minko.at(i)) tinitu = false;
            }
        }
        for(int i = 0; i < ankan.size(); i++){
            if(!((18 <= ankan.at(i) && ankan.at(i) <= 26)|| 27 <= ankan.at(i) )){
                return;
                if(27 <= ankan.at(i)) tinitu = false;
            }
        }
        for(int i = 0;i < minkan.size(); i ++){
            if(!((18 <= minkan.at(i) && minkan.at(i) <= 26)|| 27 <= minkan.at(i) )){
                return;
                if(27 <= minko.at(i)) tinitu = false;
            }
        }
        if(tinitu){
            cout << "清一色" << endl;
            if(menzen) *han = *han + 6;
            else *han = *han + 5;
        }else{
            cout << "混一色" << endl;
            if(menzen) *han = *han + 3;
            else *han = *han + 2;
        }
    }
}
void jyuntyan(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko,vector<int> ankan, vector<int> minkan, int *han){
    if(jyantou % 9 == 0 || jyantou % 9 == 8 ){
        for(int i = 0; i <syuntu.size();i++){
            if(!(syuntu.at(i) % 9 == 0 ||syuntu.at(i) % 9 == 6)){
                return;
            }
        }
        for(int i= 0;i <anko.size();i++){
            if(!((anko.at(i) % 9 == 0 || anko.at(i) % 9 == 8) && anko.at(i) < 27)){
                return;
            }
        }
        for(int i = 0;i < minko.size();i++){
            if(!((minko.at(i) % 9 == 0 || minko.at(i) % 9 == 8) && minko.at(i) < 27)){
                return;
            }
        }
        for(int i = 0; i < ankan.size();i++){
            if(!((ankan.at(i) % 9 == 0 || ankan.at(i) % 9 == 8) && ankan.at(i) < 27)){
                return;
            }
        }
        for(int i = 0; i <  minkan.size();i++){
            if(!((minkan.at(i) % 9 == 0 || minkan.at(i) % 9 == 8) && minkan.at(i) < 27 )){
                return;
            }
        }
        cout << "純全帯么九" << endl;
        if(menzen) *han = *han + 3;
        else *han = *han + 2;
    }
}
// void chinitu_pinzu(bool menzen, int jyantou,vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han ){
//     if (jyantou < 9){
//         for(int i = 0;i <syuntu.size();i++){
//             if(!(syuntu.at(i) < 9)) return;
//         }
//         for(int i = 0;i < anko.size();i++){
//             if(!(anko.at(i) < 9)) return;
//         }
//         for(int i = 0; i < minko.size(); i++){
//             if(!(minko.at(i) < 9)) return;
//         }
//         for(int i = 0; i < anko.size(); i ++){
//             if(!(ankan.at(i) < 9)) return;
//         }
//         for(int i = 0; i < minkan.size();i++){
//             if(!(minkan.at(i) < 9)) return;
//         }
//         cout << "清一色" << endl;
//         if(menzen){
//             *han = *han + 6;
//         }else{
//             *han = *han + 5;
//         }
//     }
// }
// void chinitu_manzu(bool menzen, int jyantou, vector<int> syuntu , vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
//     if(8 < jyantou && jyantou < 18){
//         for(int i : syuntu){
//             if(!(8 < syuntu.at(i)&& syuntu.at(i) < 18)) return;
//         }
//         for(int i : anko){
//             if(!(8 < anko.at(i) && anko.at(i) < 18 )) return;
//         }
//         for(int i : minko){
//             if(!(8 < minko.at(i) && minko.at(i) > 18))return;
//         }
//         for(int i : ankan){
//             if(!(8 < ankan.at(i) && ankan.at(i) > 18))return;
//         }
//         for(int i : minkan){
//             if(!(8 < minkan.at(i) && minkan.at(i) > 18)) return;
//         }
//         cout << "清一色" << endl;
//         if(menzen){
//             *han = *han + 6;
//         }else{
//             *han = *han + 5;
//         }
//     }
// }
// void chinitu_souzu(bool menzen, int jyantou, vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan, int *han){
//     if(17 < jyantou && jyantou < 27){
//         for(int i : syuntu){
//             if(!(17 < syuntu.at(i) && syuntu.at(i) < 27)) return;
//         }
//         for(int i : anko){
//             if(!(17 < anko.at(i) && anko.at(i) < 27)) return;
//         }
//         for(int i : minko){
//             if(!(17 < minko.at(i) && minko.at(i) < 27)) return;
//         }
//         for(int i : ankan){
//             if(!(17 < ankan.at(i) && ankan.at(i) < 27)) return;
//         }
//         for(int i : minkan){
//             if(!(17 < minkan.at(i) && minkan.at(i) < 27))return;
//         }
//         cout << "清一色" << endl;
//         if(menzen){
//             *han = *han + 6;
//         }else {
//             *han = *han + 5;
//         }
//     }
// }

//その他

void show_han(int han){
    cout << "ハン：" << han << endl;
}
int calculate_hu(int mati, bool tumo, bool menzen,int bakaze, int jikaze,int jyantou, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan){


    int point = 20;
    if(menzen && !tumo) point += 10;

    if(jyantou % 9 == 0 || jyantou % 9 ==8 || jyantou == bakaze||jyantou == jikaze || 31<=jyantou) point += 2;

    for(int i = 0; i < anko.size(); i ++){
        if(anko.at(i) % 9 == 0 || anko.at(i) % 9 == 8 || 27 <= anko.at(i)) point += 8;
        else point += 4;
    }
    for(int i = 0; i < minko.size(); i++){
        if(minko.at(i) % 9 == 0 || minko.at(i) % 9 == 8 || 27 <= minko.at(i)) point += 4;
        else point += 2;
    }
    for(int i = 0; i < ankan.size();i++){
        if(ankan.at(i) % 9 == 0 || ankan.at(i) % 9 == 8 || 27 <= ankan.at(i)) point += 32;
        else point += 16;
    }
    for(int i = 0; i < minkan.size(); i++){
        if(minkan.at(i) % 9 == 0|| minkan.at(i) % 9 == 8 || 27 <= minkan.at(i)) point += 16;
        else point += 8;
    }

    switch(mati){
        case 0 : 
            if(tumo) point += 4;
            else point += 2;
            break;
        case 1 :
            if(tumo) point += 2;
            break;
        case 2 :
            if(tumo) point += 4;
            else point += 2;
        case 3 :
            if(tumo) point += 4;
            else point += 2;
            break;
        case 4 :
            if(tumo) point += 2;
            break;
    }
    int a = point % 10;
    if(a != 0) point = point - a + 10;
    return point;
}

int calculate_point(int jikaze, int han, int hu){
    if(jikaze == 27){
        if(han == 1){
            if(hu == 30) return 1500;
            else if(hu == 40) return 2000;
            else if(hu == 50) return 2400;
            else if (hu == 60) return 2900;
            else if(hu == 70) return 3400;
            else if (hu == 80) return 3900;
            else if (hu == 90) return 4400;
            else if (hu == 100) return 4800;
            else return 5300;
        }else if (han == 2){
            if(hu == 20) return 2000;
            else if(hu == 25) return 2400;
            else if(hu == 30) return 2900;
            else if(hu == 40) return 3900;
            else if(hu == 50) return 4800;
            else if(hu == 60) return 5800;
            else if(hu == 70) return 6800;
        }else if(han ==3 ){
            if(hu == 20) return 3900;
            else if(hu == 25) return 4800;
            else if(hu == 30) return 5800;
            else if(hu == 40) return 7700;
            else if(hu == 50) return 9600;
            else if(hu == 60) return 11600;
            else {
                cout << "満貫" << endl;
                return 12000;
            }
        } else if (han == 4){
            if(hu == 20) return 7700;
            else if (hu == 25) return 9600;
            else if (hu == 30) return 11600;
            else{
                cout << "満貫" << endl;
                return 12000;
            }
        }else if (han  == 5){
            cout << "満貫" << endl;
            return 12000;
        }else if (han == 6 || han == 7){
            cout << "跳満" << endl;
            return 18000;
        }else if (han == 8 || han == 9 || han == 10){
            cout << "倍満" << endl;
            return 24000;
        }else if (han == 11 || han == 12){
            cout << "三倍満" << endl;
            return 36000;
        }else {
            cout << "数え役満" << endl;
            return 48000;
        }
    } else {
        if(han == 1){
            if(hu == 30) return 1000;
            else if(hu == 40) return 1300;
            else if(hu == 50) return 1600;
            else if(hu == 60) return 2000;
            else if(hu == 70) return 2300;
        }else if (han == 2){
            if(hu == 20) return 1300;
            else if (hu == 25) return 1600;
            else if (hu == 30) return 2000;
            else if (hu == 40) return 2600;
            else if (hu == 50) return 3200;
            else if (hu == 60) return 3900;
            else if (hu == 70) return 4500;
        }else if (han == 3){
            if (hu == 20) return 2600;
            else if (hu == 25) return 3200;
            else if (hu == 30) return 3900;
            else if (hu == 40) return 5200;
            else if (hu == 50) return 6400;
            else if (hu == 60) return 7700;
            else {
                cout << "満貫" << endl;
                return 8000;
            }
        }else if (han == 4){
            if (hu == 20) return 5200;
            else if (hu == 25) return 6400;
            else if (hu == 30) return 7700;
            else {
                cout << "満貫" << endl;
                return 8000;
            }
        }else if (han == 5){
            cout << "満貫" << endl;
            return 8000;
        }else if (han == 6 || han == 7){
            cout << "跳満" << endl;
            return 12000;
        }else if (han == 8 || han == 9 || han == 10){
            cout << "倍満" << endl;
            return 16000;
        }else if (han == 11 || han == 12){
            cout << "三倍満" << endl;
            return 24000;
        } else {
            cout << "数え役満" << endl;
            return 32000;
        }
    }
    return -1;
}