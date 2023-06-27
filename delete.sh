#!/bin/bash
HOLA="hola"
MATIHAI="matihai"
POINT="point"
if [ $# == 0 ]; then
    if [ -e $HOLA ]; then
        rm hola
    fi
    if [ -e "matihai" ]; then
        rm matihai
    fi
    if [ -e "point" ]; then
        rm point
    fi
fi
case $1 in
    -h)
        if [ -e $HOLA ]; then
            rm hola
        fi
    ;;
    -m)
        if [ -e "matihai" ]; then
            rm matihai
        fi
    ;;
    -p)
        if [ -e "point" ]; then
            rm point
        fi
    ;;
esac

#chmod +x delete.sh