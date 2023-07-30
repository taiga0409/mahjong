#include "point.hpp"
#include "



void  find_mati(int *mati,int tumo, vector<int> syuntu, vector<int> anko,vector<int> minko,vector<int> ankan,vector<int> minkan,int jyantou){
    cout << "ツモ： " << tumo << endl;
    int point ;
    if(tumo == jyantou){
        cout << "単騎待ち" << endl;
        *mati = 0;
    }
    for(int i : anko){
        if(tumo == i){
            cout << "シャボ待ち" << endl;
            *mati = 1;
        }
    }
    for(int i : minko){
        if(tumo == i){
            cout << "シャボ待ち" << endl;
            *mati = 1;
        }
    }
    for(int i : syuntu){
        if(i + 1 == tumo){
            cout << "カンチャン待ち" << endl;
            *mati = 2;
        }
        if(i % 9 == 0){
            if (tumo == i+2){
                cout << "ペンチャン待ち" << endl;
                *mati = 3;
            }
            if(tumo == i){
                cout << "リャンメン待ち" << endl;
                *mati = 4;
            }
        }else if (i % 9 == 6){
            if(tumo == i){
                cout << "ペンチャン待ち" << endl;
                *mati = 3;
            }
            if(tumo == i+2){
                cout << "リャンメン待ち" << endl;
                *mati = 4;
            }
        }else{
            if(tumo == i || tumo == i+1){
                cout << "カンチャン待ち" << endl;
                *mati = 2;
            }
        }
    }
}

