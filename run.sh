#!/bin/bash

if [ -e "hola" ]; then 
    ./hola
    rm hola
fi
if [ -e "matihai" ]; then
    ./matihai
    rm matihai
fi
if [ -e "point" ]; then
    ./point
    rm point
fi
if [ -e "agari" ]; then
    ./agari
    rm agari
fi

#chmod +x run.sh