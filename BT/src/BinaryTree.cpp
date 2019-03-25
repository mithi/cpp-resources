#include <cstddef>
#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() {
    _root = NULL;
}

BinaryTree::~BinaryTree() {}

Node* BinaryTree::_rinsert( Node* current, int value) {

    if (current == NULL) {
        return new Node(value);
    }
    if (value < current->data) {
        current->left = _rinsert(current->left, value);
    } else if (value > current->data) {
        current->right = _rinsert(current->right, value);
    } else {
        current->data = value;
    }
    return current;
}

void BinaryTree::insert(int value) {
    _root = _rinsert(_root, value);
}

Node* BinaryTree::_rminimum(Node* current) {

    if (current->left == NULL) {
        return current;
    }
    return _rminimum(current->left);
}

int BinaryTree::minimum(){
    Node* minimum_node = _rminimum(_root);
    return minimum_node->data;
}

bool BinaryTree::_rcontains(Node* current, int value) {
    if (current == NULL) { return false; }

    if (value < current->data) {
        return _rcontains(current->left, value);
    } else if (value > current->data) {
        return _rcontains(current->right, value);
    } else {
        return true;
    }
}

bool BinaryTree::contains(int value) {
    return _rcontains(_root, value);
}

