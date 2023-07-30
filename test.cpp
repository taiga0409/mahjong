#include "agari.hpp"

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
int main(){
    vector<int> a = {1,2,3};
    vector<int> b = {2,3,4};
    vector<int> c = {3,4,5};
    vector<int> d = {4,5,6};
    vector<int> e = {5};
    vector<int> c_a = {};
    vector<int> c_b = {};
    vector<int> c_c = {};
    vector<int> c_d = {};
    vector<int> c_e = {};
    for(int i = 0; i < a.size();i++){
        cout << a.at(i) << endl;
    }
    

    copy_vector(a,b,c,d,e,c_a,c_b,c_c,c_d,c_e);
for(int i = 0; i < c_a.size();i++){
        cout << c_a.at(i) << endl;
    }
}