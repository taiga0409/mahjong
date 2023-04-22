#ifndef MAHJONG_HPP_
#define MAHJONG_HPP_

#include <iostream>
#include <string>
using namespace std;

bool count(int *pinzu,int *manzu,int *souzu,int *jihai);
void show(int *pinzu,int *manzu,int *souzu,int *jihai);
bool find_mentu(int i,int *pinzu,int *manzu,int *souzu,int *jihai);
bool find_jyantou(int i, int *pinzu, int *manzu, int *souzu, int *jihai);
bool find_syuntu(int i , int *pinzu, int *manzu, int *souzu, int *jihai);
void find_mentu();
void show_jihai(int i);

#endif //MAHJONG_HPP_