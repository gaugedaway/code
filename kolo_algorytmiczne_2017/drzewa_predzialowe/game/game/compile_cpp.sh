#!/bin/bash

NAME=game

/usr/bin/g++ -DEVAL -O2 -o $NAME grader.c $NAME.cpp
