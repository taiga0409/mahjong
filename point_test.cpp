#include "point.hpp"
#include "mahjong.hpp"

int main(){
    vector<int> syuntu = {0,6,14};// g++ -std=c++11 -o
    vector<int> anko = {2};
    vector<int> minko = {};
    int jyantou = 6;
    int tumo = 6;
    int mati ;
    find_mati(&mati,tumo,syuntu,anko,minko,jyantou);

}