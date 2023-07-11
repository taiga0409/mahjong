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

#chmod +x run.sh