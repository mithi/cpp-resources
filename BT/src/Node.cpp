#include "Node.h"
#include <cstddef>

Node::Node(int x) {
    data = x;
    right = NULL;
    left = NULL;
}

Node::~Node() {}
