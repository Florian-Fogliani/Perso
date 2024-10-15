#!/bin/sh

while (true); do
    IFS= read -r line
    if ([ -z "$line" ] || echo "$line" | grep -qE '^[" "]+$') ; then 
        printf "%s\n" "it is empty"
    elif (echo "$line" | grep -qE '^[a-zA-Z]+$'); then
        printf "%s\n" "it is a word"
    elif echo "$line" | grep -qE '^[0-9]$'; then
        printf "%s\n" "it is a digit"
    elif echo "$line" | grep -qE '^[0-9]+$'; then
        printf "%s\n" "it is a number"
    elif echo "$line" | grep -qE '^[[:alnum:]]+$'; then
        printf "%s\n" "it is an alphanum"
    else
        printf "%s\n" "it is too complicated"
        exit 0;
    fi
done
