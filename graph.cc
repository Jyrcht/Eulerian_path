#include "graph.h"

#include <iostream>

Graph::Graph(int n, int e) {
    nodes_num_ = n;
    edges_num_ = e;
    nodes_.reserve(nodes_num_);
    used_edges_.reserve(edges_num_);
}

void Graph::connect(int n1, int n2) {
    nodes_[n1].push_back(n2);
    nodes_[n2].push_back(n1);
}

void Graph::printGraph() {
    for (auto const& pair: nodes_) {
        for (auto const& n2 : pair.second)
            std::cout << "Node " << pair.first << " connects to node " << n2 << '\n';
    }
}