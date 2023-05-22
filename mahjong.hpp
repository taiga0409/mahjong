#ifndef MAHJONG_HPP_
#define MAHJONG_HPP_

#include <iostream>
#include <string>
using namespace std;

//agari
bool count(int *pinzu,int *manzu,int *souzu,int *jihai);
void show(int *pinzu,int *manzu,int *souzu,int *jihai);
bool find_coutu(int i,int *pinzu,int *manzu,int *souzu,int *jihai);
void delete_coutu(int i, int *pinzu, int *manzu, int *souzu, int *jihai);
bool find_jyantou(int i, int *pinzu, int *manzu, int *souzu, int *jihai);
void delete_syuntu(int i , int *pinzu, int *manzu, int *souzu, int *jihai);
bool find_syuntu(int &i , int *pinzu, int *manzu, int *souzu, int *jihai);
void show_jihai(int i);
void copy_haipai(int *pinzu, int *manzu, int *souzu, int *jihai,
                int *c_pinzu, int *c_manzu, int *c_souzu, int *c_jihai);
void delete_jyantou(int i,int *pinzu, int *manzu, int *souzu, int *jihai);
void find_matihai(int i,int *pinzu,int *manzu,int *souzu,int *jihai);

void tumo(int i , int *pinzu, int *manzu,int *souzu, int *jihai);
void find_matihai_1(int *pinzu, int *manzu, int *souzu, int *jihai);

#endif //MAHJONG_HPP_     