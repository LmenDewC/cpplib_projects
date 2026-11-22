#!/bin/bash
if [ "$LEMON" != "set" ]; then
    export LEMON=set
    dir=$(find /usr -type d -name "c++" -print -quit 2>/dev/null)
    export INCDIR=$dir
    echo "Global Variables set, type ./install.sh again"
elif [ "$LEMON" = "set" ]; then
    if [ "$#" != 1 ]; then
        echo "Usage: ./install all or ./install <filename>"
    else
        buf=$INCDIR
        end=$((${#buf}-4))
        dirc=${buf:0:$end}
        if [ "$1" = "all" ]; then
            cp ./include/* $dirc
            echo "Installed Successfully at $dirc"
        elif [ "$1" != "all" ]; then
            if [ -f "./include/$1" ]; then
                cp ./include/$1 $dirc
                echo "$1 Installed Successfully at $dirc"
            else
                echo "$1 does not exist"
            fi
        fi
    fi
fi