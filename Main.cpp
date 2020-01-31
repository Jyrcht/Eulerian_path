
#include <stdio.h>
#include <time.h>

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Node.h"



void line(std::vector<Node> &nodes) {
    //unidirectional
    for (int i = 0; i < nodes.size() - 1; i++) {
        //uni-directional
        nodes[i].connect(&nodes[(double)i + 1]);
        //nodes[(double)i + 1].connect(&nodes[i]);
    }
}

void rand_graph(std::vector<Node>& nodes) {
    //unidirectional

    int edges;
    int length = nodes.size();

    for (int i = 0; i < length; i++) {
        int num = rand() % length;
        /*
        while (num == i || nodes[num].is_connected()) {
            num = rand() % length;
        }
        */
        nodes[i].connect(&nodes[num]);
        //nodes[(double)i + 1].connect(&nodes[i]);
    }
}


void print_graph(std::vector<Node>& nodes) {

    for (int i = 0; i < nodes.size(); i++) {

        if (!nodes[i].get_edges().empty()) {
            for (int j = 0; j < nodes[i].get_edges().size(); j++) {
                std::cout << "Node " << nodes[i].get_num() << " connects to ";
                std::cout << "node " << nodes[i].get_edges()[j].right_node->get_num() << " along edge " << j <<'\n';
            }
        }
        else {
            std::cout << "Node " << nodes[i].get_num() << " connects to nothing\n";
        }
    }
}

int main(int argc, char** argv) 
{

    int total_nodes = 0;
    int length;
    std::vector<Node> nodes;
    //make has set of nodes to check if connected
    //make vector of edges here and pass it as parameter to connect
    


    if (argc != 2) {
        fprintf(stderr,"usage: epath.exe number\n  number: number of nodes for this graph\n");
        exit(1);
    }
    
    try {
        length = std::stoi(argv[1]);
    }
    catch (std::invalid_argument) {
        fprintf(stderr, "Bad input, please input a number\n");
        fprintf(stderr, "usage: epath.exe number\n  number: number of nodes for this graph\n");
        exit(1);
    }
    catch (std::out_of_range) {
        fprintf(stderr, "Bad input, number too large\n");
        fprintf(stderr, "usage: epath.exe number\n  number: number of nodes for this graph\n");
        exit(1);
    }

    srand(time(0));

    //Populate nodes vector
    nodes.reserve(length);
    for (; total_nodes< length; total_nodes++) {
        nodes.push_back(total_nodes);
    }

    rand_graph(nodes);
    print_graph(nodes);

    return 0;
}