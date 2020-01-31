#ifndef NODE_H
#define NODE_H

#include <vector>

class Node;

struct Edge
{
    int num;
    bool traveled;

    Node* left_node;
    Node* right_node;
};

class Node
{
private:
    int num, total_edges;
    //change this to edge pointers instead
    std::vector<Edge> edges;
    bool connected;

public:
    Node();
    Node(int num);
    void connect(Node* node);
    std::vector<Edge> const &get_edges() const;
    int get_num();
    bool is_connected();
    ~Node();
};

#endif