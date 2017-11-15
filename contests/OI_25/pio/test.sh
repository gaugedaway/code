#!/bin/sh

G=5

for((i=281; i<=300; i++)) ; do
	./wzo < "$G/in/pow$i.in" > wzo.out
	if diff wzo.out "$G/out/pow$i.out" > /dev/null ; then
		echo "Test $i: OK!"
	else
		echo "Test $i: BUG, HONOR, OJCZYZNA!"
		break
	fi
done

