#!/bin/bash

read -p "Deseja compilar os algoritmos? (s/n) " resp

if [ "$resp" = "s" ]; then
    echo "Compilando os algoritmos...\n"

    echo "Compilando dijkstra..."
    cd dijkstra && make && cd ..
    echo "\n"

    echo "Compilando ford-fulkerson..."
    cd ford-fulkerson && make && cd ..
    echo "\n"

    echo "Compilando kruskal..."
    cd kruskal && make && cd ..
    echo "\n"

    echo "Compilando kosaraju..."
    cd kosaraju && make && cd ..
    echo "\n"

    echo "Compilando prim..."
    cd prim && make && cd ..
    echo "\n"


    echo "Copiando os algoritmos para Bat1..."
    cp dijkstra/dijkstra.bin Bat1/
    cp ford-fulkerson/ford-fulkerson.bin Bat1/
    cp kruskal/kruskal.bin Bat1/
    cp kosaraju/kosaraju.bin Bat1/
    cp prim/prim.bin Bat1/
    echo "\n"
    echo "Finalizado! Rode Bat1 em seguida."
    echo "\n"
fi

read -p "Deseja rodar o Bat1? (s/n) " resp

if [ "$resp" = "s" ]; then
    echo "Rodando Bat1..."
    cd Bat1 && sh ./Bat1.sh
fi
