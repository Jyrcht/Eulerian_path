#include "Node.h"

Node::Node() {
    num = 0;
    total_edges = 0;
    connected = false;
}

Node::Node(int num){
    this->num = num;
    total_edges = 0;
    connected = false;
}

void Node::connect(Node* node) {
    //Make an edge and connect it to the node
    Edge* edge = new Edge();
    total_edges++;
    edge->num = total_edges;
    edge->left_node = this;
    edge->right_node = node;
    this->edges.push_back(*edge);
    
    connected = true;
}

bool Node::is_connected() {
    return connected;
}

std::vector<Edge> const& Node::get_edges() const{
    return edges;
}

int Node::get_num() {
    return num;
}

Node::~Node() {
    edges.clear();
    edges.shrink_to_fit();
}


