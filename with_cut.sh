#!/bin/sh

if [ $# -ne 2 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

nb_l=$(wc -l < "$1")
if [ "$nb_l" -lt "$2" ];then
    exit 1
fi

head -n "$2" "$1" | tail -n 1 - | cut -f 2 -d ";"
head -n "$2" "$1" | tail -n 1 - | cut -f 3 -d ";"
