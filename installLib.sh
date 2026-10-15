#!/bin/bash
read -p "which header file: " input

if [[ -f "./include/$input" ]]; then
    read -p "save as: " name
    sudo cp "./include/$input" "/usr/local/include/$name"
    echo "saved header at '/usr/local/include' as $name"
else
    echo "nonexistent"
fi

read -p "compile main.cpp? y/n:" yn
if [[ $yn -eq "y"||$yn -eq "Y" ]]; then
    g++ ./src/main.cpp -o ./io
else
    echo
fi
