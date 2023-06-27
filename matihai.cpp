#include "point.hpp"



void  find_mati(int tumo, vector<int> syuntu, vector<int> coutu,int jyantou){
    cout << "ツモ： " << tumo << endl;
    if(tumo == jyantou){
        cout << "単騎待ち" << endl;
    }
    for(int i : coutu){
        if(tumo == i){
            cout << "シャボ待ち" << endl;
        }
    }
    for(int i : syuntu){
        if(i + 1 == tumo){
            cout << "カンチャン待ち" << endl;
        }
        if(i % 9 == 0){
            if (tumo == i+2){
                cout << "ペンチャン待ち" << endl;
            }
            if(tumo == i){
                cout << "リャンメン待ち" << endl;
            }
        }else if (i % 9 == 6){
            if(tumo == i){
                cout << "ペンチャン待ち" << endl;
            }
            if(tumo == i+2){
                cout << "リャンメン待ち" << endl;
            }
        }else{
            if(tumo == i || tumo == i+1){
                cout << "カンチャン待ち" << endl;
            }
        }
    }
}

