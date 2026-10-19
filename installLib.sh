#!/bin/bash
read -p "which header file: " input

if [[ -f "./include/$input" ]]; then
    read -p "save as: " name
    cp "./include/$input" "/usr/include/$name"
    echo "saved header at '/usr/include' as $name"
else
    echo "nonexistent"
fi