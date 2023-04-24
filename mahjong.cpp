#include "mahjong.hpp"

// ピンズ 36枚 ソウズ　36枚　マンズ　36枚　字牌 28枚
// int pinzu[36];
// int manzu[36];
// int souzu[36];
// int jihai[28];

// int pinzu[9];
// int manzu[9];
// int souzu[9];
// int jihai[7];

void show_jihai(int i){
    string jihai;
    switch(i){
        case 0: jihai = "東"; break;
        case 1: jihai = "南"; break;
        case 2: jihai = "西"; break;
        case 3: jihai = "北"; break;
        case 4: jihai = "白"; break;
        case 5: jihai = "發"; break;
        case 6: jihai = "中"; break;
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

void show(int *pinzu,int *manzu,int *souzu,int *jihai){
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

// void find_atama(){
//     for(int i = 0;i < 34;i++){
//         if(i < 9){
//             if(pinzu[i] >= 2)
//         }
//     }
// }

bool find_coutu(int i,int *pinzu,int *manzu,int *souzu,int *jihai){
    if(i < 9){
            if(pinzu[i] >= 3){
                cout << "メンツ : p" << i+1 << endl;
                pinzu[i] -= 3;
                return true;
            }
    }else if(i < 18){
            if(manzu[i % 9] >= 3){
                cout << "メンツ : m" << (i % 9)+1 << endl;
                manzu[i % 9] -= 3;
                return true;
            }
    }else if(i < 27){
            if(souzu[i % 9] >= 3){
                cout << "メンツ : s" << (i % 9)+1 << endl;
                souzu[i % 9] -= 3;
                return true;
            }
     }else{
            if(jihai[i % 9] >= 3){
                cout << "メンツ : " << i % 9 << endl;
                jihai[i % 9] -= 3;
                return true;
            }
        }
    return false;
}

bool find_jyantou(int i , int *pinzu, int *manzu , int *souzu, int *jihai,
                    int *c_pinzu, int *c_manzu, int *c_souzu, int *c_jihai){
    // cout << i << endl;
    if(i < 9){
        // cout << pinzu[i] << endl; 
            if(pinzu[i] >= 2){
                cout << "雀頭 : p" << i+1 << endl;
                copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
                c_pinzu[i] -= 2;
                return true;
            }
    }else if(i < 18){
        // cout << manzu[i % 9] << endl;
            if(manzu[i % 9] >= 2){
                cout << "雀頭 : m" << (i % 9) + 1 << endl;
                copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
                c_manzu[i % 9] -= 2;
                return true;
            }
    }else if(i < 27){
        // cout << souzu[i % 9] << endl;
        
            if(souzu[i % 9] >= 2){
                cout << "雀頭 : s" << (i % 9) + 1 << endl;
                copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
                c_souzu[i % 9] -= 2;
                return true;
            }
     }else{
        // cout << jihai[i % 9] << endl;

            if(jihai[i % 9] >= 2){
                cout << "雀頭 : " ;
                copy_haipai(pinzu,manzu,souzu,jihai,c_pinzu,c_manzu,c_souzu,c_jihai);
                show_jihai(i % 9);
                cout << endl;
                c_jihai[i % 9] -= 2;
                return true;
            }
        }
        // cout << i << endl;
    return false;
}

bool find_syuntu(int &i , int *pinzu, int *manzu, int *souzu, int *jihai){
    bool syuntu = false;
    if(i < 7){
        if(pinzu[i] >= 1 && pinzu[i+1] >= 1 && pinzu[i+2] >= 1){
    //  while(pinzu[i] >= 1 && pinzu[i+1] >= 1 && pinzu[i+2] >= 1){
            pinzu[i] --;
            pinzu[i+1] --;
            pinzu[i+2] --;
            cout << "順子 : p" << i+1 << i+2 << i+3 << endl;
            if(pinzu[i] >= 1) i--;
            return true;
            // syuntu = true;
     }
    //  if(syuntu)
        // return true;
        // }
    }else if (i >= 9 && i < 16){
        if(manzu[i%9] >= 1 && manzu[(i%9)+1] >= 1 && manzu[(i%9)+2] >= 1){
        // while(manzu[i%9] >= 1 && manzu[(i%9)+1] >= 1 && manzu[(i%9)+2] >= 1){
            manzu[i%9] --;
            manzu[(i%9)-1] --;
            manzu[(i%9)-2] --;
            cout << "順子 : m" << (i%9)+1 << (i%9)+2 << (i%9)+3 << endl;
            // syuntu = true;
            if(manzu[i%9] >= 1) i--;
            return true;
        }
        // if(syuntu)
        //     return true;
        
    }else if(i >= 18 && i < 26){
        if(souzu[i%9] >= 1 && souzu[(i%9)+1] >= 1 && souzu[(i%9)+2] >= 1){
            souzu[i%9] --;
            souzu[(i%9)+1] --;
            souzu[(i%9)+2] --;
            cout << "順子 : s" << (i%9)+1 << (i%9)+2 << (i%9)+3 << endl;
            // syuntu = true;
            if(souzu[i%9] >= 1) i--;
            return true;
        }
        // if(syuntu)
        //     return true;
    }
    return false;
}
// void find_mentu(){
//     for(int i = 0; i < 34; i++){
//         if(i < 9){
//             if(pinzu[i] >= 3){
//                 cout << "メンツ : p" << i << endl;
//             }
//         }else if(i < 18){
//             if(manzu[i % 9] >= 3){
//                 cout << "メンツ : m" << i % 9 << endl;
//             }
//         }else if(i < 27){
//             if(souzu[i % 9] >= 3){
//                 cout << "メンツ : s" << i % 9 << endl;
//             }
//         }else{
//             if(jihai[i % 9] >= 3){
//                 cout << "メンツ : " << i % 9 << endl;
//             }
//         }
//     }
    
// }

void copy_haipai(int *pinzu,int *manzu, int *souzu,int *jihai,
                int *c_pinzu, int *c_manzu, int *c_souzu, int *c_jihai){
                    for(int i = 0 ;i < 9;i++){
                        c_pinzu[i] = pinzu[i];
                        c_manzu[i] = manzu[i];
                        c_souzu[i] = souzu[i];
                        if(i < 7) c_jihai[i] = jihai[i];
                    }
                }

