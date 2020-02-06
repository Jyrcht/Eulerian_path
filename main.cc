
#include <stdio.h>
#include <time.h>

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

#include "graph.h"

int main(int argc, char** argv) 
{

    int total_nodes = 0;
    int length;

    /*
    if (argc != 2) {
        fprintf(stderr,"usage: epath.exe number\n  number: number of graphs to make\n");
        exit(1);
    }
    
    try {
        length = std::stoi(argv[1]);
    }
    catch (std::invalid_argument) {
        fprintf(stderr, "Bad input, please input a number\n");
        fprintf(stderr, "usage: epath.exe number\n  number: number of graphs to make\n");
        exit(1);
    }
    catch (std::out_of_range) {
        fprintf(stderr, "Bad input, number too large\n");
        fprintf(stderr, "usage: epath.exe number\n  number: number of graphs to make\n");
        exit(1);
    }
    */

    srand(time(0));

    Graph g1(3,3);
    g1.connect(0,1);
    g1.connect(1,2);
    g1.connect(2,0);

    g1.printGraph();

    return 0;
}