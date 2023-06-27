#ifndef MAHJONG_HPP_
#define MAHJONG_HPP_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//agari
bool count(int *pinzu,int *manzu,int *souzu,int *jihai);
void show_tehai(int *pinzu,int *manzu,int *souzu,int *jihai);
void show_matihai(bool *agari);
bool find_coutu(int i,int *pinzu,int *manzu,int *souzu,int *jihai);
void delete_coutu(int i, int *count,int *pinzu, int *manzu, int *souzu, int *jihai);
bool find_jyantou(int i, int *pinzu, int *manzu, int *souzu, int *jihai);
void delete_syuntu(int i , int *pinzu, int *manzu, int *souzu, int *jihai);
bool find_delete_syuntu(int &i , int *pinzu, int *manzu, int *souzu, int *jihai);
void set_syuntu( int *pinzu, int *manzu, int *souzu, int *jihai);
void show_jihai(int i);
void copy_haipai(int *pinzu, int *manzu, int *souzu, int *jihai,
                int *c_pinzu, int *c_manzu, int *c_souzu, int *c_jihai);
void delete_jyantou(int i,int *pinzu, int *manzu, int *souzu, int *jihai);
bool find_chitoi(int *pinzu, int *manzu, int *souzu, int *jihai);

void tumo(int i , int *pinzu, int *manzu,int *souzu, int *jihai);
void find_matihai(int i,int *count,int *pinzu, int *manzu, int *souzu, int *jihai);
void find_matihai(int i,int *count, int m, bool *agari,int *pinzu, int *manzu, int *souzu,int *jihai);
void choose_coutu(int i,int *pinzu, int *manzu, int *souzu, int *jihai);

#endif //MAHJONG_HPP_     