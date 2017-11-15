#!/bin/sh

make

for((i=0; i<10000; i++)) ; do
	./gen $i > t.in
	./brut < t.in > brut.out
	./wzo < t.in > wzo.out

	if diff brut.out wzo.out > /dev/null ; then
		echo "Test $i: OK!"
	else
		echo "Test $i: BUG, HONOR, OJCZYZNA!"
		break
	fi

	rm t.in brut.out wzo.out
done

