#ifndef GRAPH_H
#define GRAPH_H


#include <unordered_map>
#include <unordered_set>
#include <vector>

class Graph {
public:
    Graph(int n, int e);
    void connect(int n1, int n2);
    void printGraph();

private:
    int nodes_num_;
    int edges_num_;

    std::unordered_map<int,std::vector<int>> nodes_;
    //std::unordered_map<int, std::vector<int>> edges_;
    std::unordered_set<int> used_edges_;
};

#endif // !GRAPH_H
