#!/bin/sh

make gen

for((i=1001; i<=2000; i++)); do
    echo "$i - generuje..."
    ./gen $i > testy/in/roz$i.in
    echo "$i - obliczam..."
    ./brut1 < testy/in/roz$i.in > testy/out/roz$i.out
done
