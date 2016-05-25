#!/bin/bash
## perf.sh for perf.sh in /home/cheval_8/rendu/dante
## 
## Made by Nicolas Chevalier
## Login   <cheval_8@epitech.net>
## 
## Started on  Sun May 22 23:17:48 2016 Nicolas Chevalier
## Last update Sun May 22 23:40:11 2016 Nicolas Chevalier
##

make -s -C profondeur/
make -s -C astar/
make -s -C generateur/
make -s -C tournoi/
make -s -C largeur/

echo "Generating maze parfait 3000 x 3000..."
./generateur/generateur 3000 3000 parfait > mazes/tmp.txt
echo "We will test this map with all the algorithms"
time ./largeur/solver mazes/tmp.txt > /dev/null
echo "Algorithm largeur done"
time ./profondeur/solver mazes/tmp.txt > /dev/null
echo "Algorithm profondeur done"
time ./astar/solver mazes/tmp.txt > /dev/null
echo "Algorithm astar done"
time ./tournoi/solver mazes/tmp.txt > /dev/null
echo "Algorithm tournoi done"

echo "
"
echo "Generating maze imparfait 3000 x 3000..."
./generateur/generateur 3000 3000 imparfait > mazes/tmp.txt
echo "We will test this map with all the algorithms"
time ./largeur/solver mazes/tmp.txt > /dev/null
echo "Algorithm largeur done"
time ./profondeur/solver mazes/tmp.txt > /dev/null
echo "Algorithm profondeur done"
time ./astar/solver mazes/tmp.txt > /dev/null
echo "Algorithm astar done"
time ./tournoi/solver mazes/tmp.txt > /dev/null
echo "Algorithm tournoi done"
rm mazes/tmp.txt
