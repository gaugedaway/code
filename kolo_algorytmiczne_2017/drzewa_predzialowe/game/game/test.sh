#!/bin/sh

for file in *.in ; do
    rm game.in
    if [ $file != "game.in" ]; then
        ln -s $file "game.in"
        ./game > game.out
        if diff ${file%.out} game.out > /dev/null ; then
            echo "$file - OK!"
        else
            echo "$file - BUG, HONOR, OJCZYZNA!"
            break
        fi
    fi
done
