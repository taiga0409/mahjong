#include "mahjong.hpp"

bool find_matihai(int i,int *pinzu,int *manzu, int *souzu, int *jihai){
    if(i < 9){
        if(pinzu[i] == 2){
            cout << "p" << i+1 << " シャボ待ち" << endl;
        }
        if(i == 0){
            if(pinzu[i] == 1 && pinzu[i+1] == 1)
                cout << "p" << (i+2)+1 << " ペンちゃん待ち" << endl;
        }
        if(i == 8){
            if(pinzu[i] == 1 && pinzu[i+1] == 1)
                cout << "p" << (i-1)+1 << " ペンちゃん待ち" << endl;
        }
        if(0 < i && i < 7){
            if(pinzu[i] == 1 && pinzu[i+1] == 1)
                cout << "p" << (i-1)+1 << "," << (i+2)+1 << " リャンメン待ち" << endl;
        }
    }else if(i < 18){
        if(manzu[i%9] == 2){
            cout << "m" << (i%9) + 1 << " シャボ待ち" << endl;
        }
        if(i == 9){
            if(manzu[i%9] == 1 && manzu[(i+1)%9] == 1)
                cout << "m" << (i+2)%9 << " ペンちゃん待ち" << endl;
        }
        if(i == 17){
            if(manzu[i%9] == 1 && manzu[(i+1)%9] == 1)
                cout << "m" << ((i-1)%9)+1 << " ペンちゃん待ち" << endl;
        }
        if(9 < i && i < 16){
            if(manzu[i%9] == 1 && manzu[(i+1)%9] == 1)
                cout << "m" << ((i-1)%9)+1 << "," << ((i+2)%9)+1 << " リャンメン待ち" << endl;
        }
    }else if(i < 27){
        if(souzu[i%9] == 2){
            cout << "s" << (i%9) + 1 << " シャボ待ち" << endl;
        }
        if(i == 18){
            if(souzu[i%9] == 1 && souzu[(i+1)%9] == 1)
                cout << "s" << (i+2)%9 << " ペンちゃん待ち" << endl;
        }
        if(i == 26){
            if(souzu[i%9] == 1 && souzu[(i+1)%9] == 1)
                cout << "s" << ((i-1)%9)+1 << " ペンちゃん待ち" << endl;
        }
        if(18 < i && i < 25){
            if(souzu[i%9] == 1 && souzu[(i+1)%9] == 1)
                cout << "s" << ((i-1)%9)+1 << "," << ((i+2)%9)+1 << " リャンメン待ち" << endl;
        }
    }else{
        if(jihai[i%7] == 2){
            show_jihai(i%7);
            cout << " シャボ待ち" << endl;
        }
    }
        
}
