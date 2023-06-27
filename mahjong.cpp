#include "mahjong.hpp"


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
void delete_coutu(int i,int *count, int *pinzu, int *manzu, int *souzu, int *jihai){
    
    if(i < 9){
        pinzu[i] -= 3;
        cout << "面子 : p" << i+1 << endl;
    }else if(i < 18){
        manzu[i % 9] -= 3;
        cout << "面子 : m" << i+1 << endl;
    }else if(i < 27){
        souzu[i % 9] -= 3;
        cout << "面子 : s" << i+1 << endl;
     }else{
        jihai[i % 9] -= 3;
        cout << "面子 : " ;
        show_jihai(i);
        cout << endl;
        }
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

void delete_jyantou(int i ,int *pinzu,int *manzu, int *souzu, int *jihai){
    if(i < 9){
        pinzu[i] -= 2;;
    }else if (i < 18){
        manzu[i % 9] -= 2;
    }else if(i < 27){
        souzu[i % 9] -= 2;
    }else{
        jihai[i%9] -= 2;
    }
}

bool find_delete_syuntu(int *i , int *pinzu, int *manzu, int *souzu, int *jihai){
    bool syuntu = false;
    if(*i < 7){
        if(pinzu[*i] >= 1 && pinzu[*i+1] >= 1 && pinzu[*i+2] >= 1){
    //  while(pinzu[i] >= 1 && pinzu[i+1] >= 1 && pinzu[i+2] >= 1){
            pinzu[*i] --;
            pinzu[*i+1] --;
            pinzu[*i+2] --;
            cout << "順子 : p" << *i+1 << *i+2 << *i+3 << endl;
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
            cout << "順子 : m" << (*i%9)+1 << (*i%9)+2 << (*i%9)+3 << endl;
            // syuntu = true;
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
            cout << "順子 : s" << (*i%9)+1 << (*i%9)+2 << (*i%9)+3 << endl;
            // syuntu = true;
            if(souzu[*i%9] >= 1) *i = *i - 1;
            return true;
        }
        // if(syuntu)
        //     return true;
    }
    return false;
}
void set_syuntu(int *count,int *pinzu, int *manzu, int *souzu, int *jihai){
    for(int i = 0; i < 27;i++){
        if(find_delete_syuntu(&i,pinzu,manzu,souzu,jihai)){
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

void find_matihai(int n, int *count,int *pinzu , int *manzu , int *souzu, int *jihai){
    for(int i = n; i < 34; i ++){//刻子だけの選定
        if(find_coutu(i,pinzu,manzu,souzu,jihai)){
            int c_pinzu[9],c_manzu[9],c_souzu[9],c_jihai[7];
            copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
            int c_count = *count;
            find_matihai(i+1,&c_count,c_pinzu,c_manzu,c_souzu,c_jihai);
            delete_coutu(i,count,pinzu,manzu,souzu,jihai);
        }
    }
    set_syuntu(count,pinzu,manzu,souzu,jihai);
    if(*count == 4){
        cout << "テンパイ" << endl;
    }else{
         cout << "ノーテン" << endl;
    }

}
void find_matihai(int n ,int *count,int m,bool *agari,  int *pinzu, int *manzu, int *souzu, int *jihai){
    for(int i = n; i < 34; i ++){//刻子だけの選定
        if(find_coutu(i,pinzu,manzu,souzu,jihai)){
            int c_pinzu[9],c_manzu[9],c_souzu[9],c_jihai[7];
            copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
            int c_count = *count;
            find_matihai(i+1,&c_count,m,agari,c_pinzu,c_manzu,c_souzu,c_jihai);
            delete_coutu(i,count,pinzu,manzu,souzu,jihai);
        }
    }
    set_syuntu(count,pinzu,manzu,souzu,jihai);
    if(*count == 4){
        cout << "テンパイ" << endl;
        agari[m] = true;
    }else{
         cout << "ノーテン" << endl;
    }
}

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