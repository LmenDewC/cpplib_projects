#!/bin/bash
read -p "which header file: " input

if [[ -f "./include/$input" ]]; then
    cp "./include/$input" "/usr/include/$input"
    echo "saved header at '/usr/include' as $input"
else
    echo "nonexistent"
fi