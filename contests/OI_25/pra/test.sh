#!/bin/sh

make

for((i=0; i<10000; i++)) ; do
	echo "Generowanie..."
	./gen $i > t.in
	echo "Odpalanie..."
	./wzo < t.in > wzo.out
	echo "Sprawdzanie..."
	if cat t.in wzo.out | ./spr ; then
		echo "Test $i: OK!"
	else
		echo "Test $i: BUG, HONOR, OJCZYZNA!"
		break
	fi

	rm t.in wzo.out
done

