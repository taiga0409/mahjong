
#include "agari.hpp"
#include "point.hpp"

void show_jihai(int i){
    string jihai;
    switch(i%9){
        case 0: jihai = "東"; break;//27
        case 1: jihai = "南"; break;//28
        case 2: jihai = "西"; break;//29
        case 3: jihai = "北"; break;//30
        case 4: jihai = "白"; break;//31
        case 5: jihai = "發"; break;//32
        case 6: jihai = "中"; break;//33
    }
    cout << jihai ;
    

}

bool count(int *pinzu,int *manzu,int *souzu,int *jihai){
    int sum = 0;
    for(int i = 0;i < 9;i++){
        sum += souzu[i];
    }
    for(int i = 0;i < 9;i++){
        sum += manzu[i];
    }
    for(int i = 0;i < 9;i++){
        sum += pinzu[i];
    }
    for(int i = 0; i < 7 ; i++){
        sum += jihai[i];
    }
    if(sum == 14){
        cout << "COUNT : OK" << endl;
        return true;
    }else{
        cout << "ERROR" << endl;
        cout << "配牌の数 : " << sum << endl;
        return false;
    }
}

void show_tehai(int *pinzu,int *manzu,int *souzu,int *jihai){
    string tehai = "";
    string a;
    int copy;
    for(int i = 0;i < 9;i++){ // ピンズ
    copy = pinzu[i];
        while(copy != 0){
            a = to_string(i+1);
            tehai += a;
            copy --;
            // cout << pinzu[i] << endl;
        }
    }
    // cout << tehai << "endl" << endl;
    if(tehai != "")
        cout <<'p' << tehai ;
    tehai = "";
    for(int i = 0;i < 9;i++){// マンズ
    copy = manzu[i];
        while(copy != 0){
            a = to_string(i+1);
            tehai += a;
            copy --;
            // cout << pinzu[i] << endl;
        }
    }
    // cout << tehai << "endl" << endl;
    if(tehai != "")
        cout <<'m' << tehai ;
    tehai = "";
    for(int i = 0;i < 9;i++){
        copy = souzu[i];
        while(copy != 0){
            a = to_string(i+1);
            tehai += a;
            copy --;
            // cout << pinzu[i] << endl;
        }
    }
    // cout << tehai << "endl" << endl;
    if(tehai != "")
        cout <<'s' << tehai ;
    for(int i = 0; i < 7; i ++){
        copy = jihai[i];
        while(copy != 0){
            // if(i == 0) cout << "東";
            // if(i == 1) cout << "南";
            // if(i == 2) cout << "西";
            // if(i == 3) cout << "北";
            // if(i == 4) cout << "白";
            // if(i == 5) cout << "發";
            // if(i == 6) cout << "中";
            show_jihai(i);
            copy --;
        }
    }
    cout << endl;
}
void show_matihai(bool *agari){
    string a;
    string tehai = "";
    bool choise = false;
    cout << "待ち : ";
    for(int i = 0;i < 34;i++){
        if(agari[i] == true){
            
            choise = true;
            if(i < 9){
                cout << "p" << i+1 << " ";
            }else if (i < 18){
                cout << "m" << i%9+1 << " ";
            }else if(i < 27){
                cout << "s" << i%9+1 << " ";
            }else{
                show_jihai(i);
                cout << " ";
            }
        }
    }
    if(!choise){cout << "なし" ;}
    cout << endl;
}


bool find_coutu(int i,int *pinzu,int *manzu,int *souzu,int *jihai){

    if(i < 9){
            if(pinzu[i] >= 3){
                return true;
            }
    }else if(i < 18){
            if(manzu[i % 9] >= 3){
                return true;
            }
    }else if(i < 27){
            if(souzu[i % 9] >= 3){
                return true;
            }
     }else{
            if(jihai[i % 9] >= 3){
                return true;
            }
        }
    return false;
}
void delete_coutu(int i,int *count, int *pinzu, int *manzu, int *souzu, int *jihai,vector<int>& anko){
    
    if(i < 9){
        pinzu[i] -= 3;
        // cout << "面子 : p" << i+1 << endl;
    }else if(i < 18){
        manzu[i % 9] -= 3;
        // cout << "面子 : m" << i+1 << endl;
    }else if(i < 27){
        souzu[i % 9] -= 3;
        // cout << "面子 : s" << i+1 << endl;
     }else{
        jihai[i % 9] -= 3;
        // cout << "面子 : " ;
        // show_jihai(i);
        // cout << endl;
        }
    anko.push_back(i);
    *count = *count + 1;
}


bool find_jyantou(int i , int *pinzu, int *manzu , int *souzu, int *jihai){
    if(i < 9){
            if(pinzu[i] >= 2){
                cout << "雀頭 : p" << i+1 << endl;
                return true;
            }
    }else if(i < 18){
            if(manzu[i % 9] >= 2){
                cout << "雀頭 : m" << (i % 9) + 1 << endl;
                return true;
            }
    }else if(i < 27){
        
            if(souzu[i % 9] >= 2){
                cout << "雀頭 : s" << (i % 9) + 1 << endl;
                return true;
            }
     }else{

            if(jihai[i % 9] >= 2){
                cout << "雀頭 : " ;
                show_jihai(i);
                cout << endl;
                return true;
            }
        }
    return false;
}

void delete_jyantou(int i ,int *pinzu,int *manzu, int *souzu, int *jihai,int *jyantou){
    if(i < 9){
        pinzu[i] -= 2;
    }else if (i < 18){
        manzu[i % 9] -= 2;
    }else if(i < 27){
        souzu[i % 9] -= 2;
    }else{
        jihai[i%9] -= 2;
    }
    *jyantou = i;
}

bool find_delete_syuntu(int *i , int *pinzu, int *manzu, int *souzu, int *jihai,vector<int>& syuntu){

    if(*i < 7){
        if(pinzu[*i] >= 1 && pinzu[*i+1] >= 1 && pinzu[*i+2] >= 1){
    //  while(pinzu[i] >= 1 && pinzu[i+1] >= 1 && pinzu[i+2] >= 1){
            pinzu[*i] --;
            pinzu[*i+1] --;
            pinzu[*i+2] --;
            // cout << "順子 : p" << *i+1 << *i+2 << *i+3 << endl;
            syuntu.push_back(*i);
            if(pinzu[*i] >= 1) *i = *i - 1;
            return true;
            // syuntu = true;
     }
    //  if(syuntu)
        // return true;
        // }
    }else if (*i >= 9 && *i < 16){
        if(manzu[*i%9] >= 1 && manzu[(*i%9)+1] >= 1 && manzu[(*i%9)+2] >= 1){
        // while(manzu[i%9] >= 1 && manzu[(i%9)+1] >= 1 && manzu[(i%9)+2] >= 1){
            manzu[*i%9] --;
            manzu[(*i%9)+1] --;
            manzu[(*i%9)+2] --;
            // cout << "順子 : m" << (*i%9)+1 << (*i%9)+2 << (*i%9)+3 << endl;
            // syuntu = true;
            syuntu.push_back(*i);
            if(manzu[*i%9] >= 1) *i = *i -1;
            return true;
        }
        // if(syuntu)
        //     return true;
        
    }else if(*i >= 18 && *i < 26){
        if(souzu[*i%9] >= 1 && souzu[(*i%9)+1] >= 1 && souzu[(*i%9)+2] >= 1){
            souzu[*i%9] --;
            souzu[(*i%9)+1] --;
            souzu[(*i%9)+2] --;
            // cout << "順子 : s" << (*i%9)+1 << (*i%9)+2 << (*i%9)+3 << endl;
            // syuntu = true;
            syuntu.push_back(*i);
            if(souzu[*i%9] >= 1) *i = *i - 1;
            return true;
        }
        // if(syuntu)
        //     return true;
    }
    return false;
}
void set_syuntu(int *count,int *pinzu, int *manzu, int *souzu, int *jihai,vector<int>& syuntu){
    for(int i = 0; i < 27;i++){
        if(find_delete_syuntu(&i,pinzu,manzu,souzu,jihai,syuntu)){
            *count = *count + 1;
        }
    }
}


void copy_haipai(int *pinzu,int *manzu, int *souzu,int *jihai,
                int *c_pinzu, int *c_manzu, int *c_souzu, int *c_jihai){
                    for(int i = 0 ;i < 9;i++){
                        c_pinzu[i] = pinzu[i];
                        c_manzu[i] = manzu[i];
                        c_souzu[i] = souzu[i];
                        if(i < 7) c_jihai[i] = jihai[i];
                    }
                }
void copy_vector(vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan,
                vector<int>& c_syuntu, vector<int>& c_anko, vector<int>& c_minko, vector<int>& c_ankan, vector<int>& c_minkan){
                    for(int i = 0; i < syuntu.size();i++){
                        c_syuntu.push_back(syuntu.at(i));
                    }
                    for(int i = 0;i < anko.size();i++){
                        c_anko.push_back(anko.at(i));
                    }
                    for(int i = 0; i < minko.size();i++){
                        c_minko.push_back(minko.at(i));
                    }
                    for(int i = 0; i < ankan.size();i++){
                        c_ankan.push_back(ankan.size());
                    }
                    for(int i = 0; i < minkan.size();i++){
                        c_minkan.push_back(minkan.at(i));
                    }
                }
void find_matihai(int n, int *count,int *pinzu , int *manzu , int *souzu, int *jihai,
                    vector<int>&syuntu,vector<int>& anko,vector<int> &minko,vector<int>&ankan, vector<int>& minkan,
                    int tumo,int jyantou,int* point_max){
    int mati;
    for(int i = n; i < 34; i ++){//刻子だけの選定
        if(find_coutu(i,pinzu,manzu,souzu,jihai)){
            int c_pinzu[9],c_manzu[9],c_souzu[9],c_jihai[7];
            vector<int> c_anko(0);
            vector<int> c_minko(0);
            vector<int> c_ankan(0);
            vector<int> c_minkan(0);
            vector<int> c_syuntu(0);
            copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
            copy_vector(syuntu,anko,minko,ankan,minkan,c_syuntu,c_anko,c_minko,c_ankan,c_minkan);
            int c_count = *count;
            find_matihai(i+1,&c_count,c_pinzu,c_manzu,c_souzu,c_jihai,
                        c_syuntu,c_anko,c_minko, c_ankan,c_minkan,
                        tumo,jyantou, point_max);
            delete_coutu(i,count,pinzu,manzu,souzu,jihai,anko);
        }
    }
    set_syuntu(count,pinzu,manzu,souzu,jihai,syuntu);
    if(*count == 4){
        cout << "テンパイ" << endl;
        find_mati(&mati,tumo,syuntu,anko,minko,ankan,minkan,jyantou, point_max);

    }else{
         cout << "ノーテン" << endl;
    }

}
// void find_matihai(int n ,int *count,int m,bool *agari,  int *pinzu, int *manzu, int *souzu, int *jihai){
//     for(int i = n; i < 34; i ++){//刻子だけの選定
//         if(find_coutu(i,pinzu,manzu,souzu,jihai)){
//             int c_pinzu[9],c_manzu[9],c_souzu[9],c_jihai[7];
//             copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
//             int c_count = *count;
//             find_matihai(i+1,&c_count,m,agari,c_pinzu,c_manzu,c_souzu,c_jihai);
//             delete_coutu(i,count,pinzu,manzu,souzu,jihai);
//         }
//     }
//     set_syuntu(count,pinzu,manzu,souzu,jihai);
//     if(*count == 4){
//         cout << "テンパイ" << endl;
//         agari[m] = true;
//     }else{
//          cout << "ノーテン" << endl;
//     }
// }

bool find_chitoi(int *pinzu, int *manzu, int *souzu, int *jihai){
    int count = 0;
    for(int i = 0;i<34;i++){
        if(i<9){
            if(pinzu[i] == 2) count ++;
        }else if (i < 18){
            if(manzu[i%9] == 2) count ++;
        }else if(i < 27){
            if(souzu[i%9] == 2) count ++;
        }else{
            if(jihai[i%9] == 2) count ++;
        }
    }
    if(count == 7) {return true;}
    return false;
}


void tumo(int i, int *pinzu,int *manzu,int *souzu,int *jihai){
    cout << "ツモ : " ;
    if(i < 9){
        pinzu[i] ++;
        cout << "p" << i+1 << endl;
    }else if (i < 18){
        manzu[i % 9] ++;
        cout << "m" << (i % 9)+1 << endl;
    }else if (i < 27){
        souzu[i % 9] ++;
        cout << "s" << (i%9)+1 << endl;
    }else{
        jihai[i % 9] ++;
        show_jihai(i);
        cout << endl;
    }
    
}

int find_point(int jyantou, int tumo, int mati,vector<int> syuntu, vector<int> anko, vector<int> minko, vector<int> ankan, vector<int> minkan){
    int han = 0;

    int jikaze = 28;
    int bakaze = 27;
    int dora = -1;
    int uradora = -1;
    bool menzen =true;
    bool B_tumo=false;
    bool B_reach=false;
    bool B_ippatu=false;
    bool B_haitei=false;
    bool B_houtei=false;
    bool B_rinsyan=false;
    bool B_tyankan=false;
    bool B_daburi=false;

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
    // for(int i = 0; i < syuntu.size(); i ++){
    //     cout << syuntu.at(i) << endl;
    // }


    int hu = calculate_hu(mati,B_tumo,menzen,bakaze,jikaze,jyantou,anko,minko,ankan,minkan);
    cout << "符："<<hu << endl;

    show_han(han);
    int point = calculate_point(jikaze,han,hu);
    cout << "点数："<<point << endl;

    return point;
}

void  find_mati(int *mati,int tumo, vector<int> syuntu, vector<int> anko,vector<int> minko,vector<int> ankan,vector<int> minkan,int jyantou,int* point_max){
    // cout << "ツモ： " << tumo << endl;
    int point ;
    int mati_max ;
    if(tumo == jyantou){
        cout << "単騎待ち" << endl;
        *mati = 0;
        point = find_point(jyantou,tumo,*mati,syuntu,anko,minko,ankan,minkan);
        if(point > *point_max){
            *point_max = point;
            mati_max = *mati;
        }
    }
    for(int i : anko){
        if(tumo == i){
            cout << "シャボ待ち" << endl;
            *mati = 1;
             point = find_point(jyantou,tumo,*mati,syuntu,anko,minko,ankan,minkan);
        if(point > *point_max){
            *point_max = point;
            mati_max = *mati;
        }
        }
    }
    for(int i : minko){
        if(tumo == i){
            cout << "シャボ待ち" << endl;
            *mati = 1; 
            point = find_point(jyantou,tumo,*mati,syuntu,anko,minko,ankan,minkan);
            if(point > *point_max){
            *point_max = point;
            mati_max = *mati;
        }
        }
    }
    for(int i : syuntu){
        if(i + 1 == tumo){
            cout << "カンチャン待ち" << endl;
            *mati = 2;
             point = find_point(jyantou,tumo,*mati,syuntu,anko,minko,ankan,minkan);
            if(point > *point_max){
            *point_max = point;
            mati_max = *mati;
        }
        }
        if(i % 9 == 0){
            if (tumo == i+2){
                cout << "ペンチャン待ち" << endl;
                *mati = 3;
                 point = find_point(jyantou,tumo,*mati,syuntu,anko,minko,ankan,minkan);
                if(point > *point_max){
            *point_max = point;
            mati_max = *mati;
        }
            }
            if(tumo == i){
                cout << "リャンメン待ち" << endl;
                *mati = 4;
                 point = find_point(jyantou,tumo,*mati,syuntu,anko,minko,ankan,minkan);
                if(point > *point_max){
            *point_max = point;
            mati_max = *mati;
        }
            }
        }else if (i % 9 == 6){
            if(tumo == i){
                cout << "ペンチャン待ち" << endl;
                *mati = 3;
                 point = find_point(jyantou,tumo,*mati,syuntu,anko,minko,ankan,minkan);
                if(point > *point_max){
            *point_max = point;
            mati_max = *mati;
        }
            }
            if(tumo == i+2){
                cout << "リャンメン待ち" << endl;
                *mati = 4;
                 point = find_point(jyantou,tumo,*mati,syuntu,anko,minko,ankan,minkan);
                if(point > *point_max){
            *point_max = point;
            mati_max = *mati;
        }
            }
        }else{
            if(tumo == i || tumo == i+1){
                cout << "カンチャン待ち" << endl;
                *mati = 2;
                 point = find_point(jyantou,tumo,*mati,syuntu,anko,minko,ankan,minkan);
                if(point > *point_max){
            *point_max = point;
            mati_max = *mati;
        }
            }
        }
    }
    // cout << "点数：" << *point_max << endl;
}



