#!/bin/bash

if  [ $# -eq 0 ] ; then 
    g++ -std=c++11 -o point point.cpp point_test.cpp matihai.cpp
    g++ -std=c++11 -o hola hola_test.cpp mahjong.cpp
    g++ -std=c++11 -o matihai matihai_test.cpp mahjong.cpp
fi

case $1 in  
    -p)
        g++ -std=c++11 -o point point.cpp point_test.cpp matihai.cpp
        ;;
    -h)
        g++ -std=c++11 -o hola hola_test.cpp mahjong.cpp
        ;;
    -m)
        g++ -std=c++11 -o matihai matihai_test.cpp mahjong.cpp
        ;;
    --)
        g++ -std=c++11 -o nothing point.cpp  matihai.cpp mahjong.cpp
        
        ;;
esac


#chmod +x build.sh
