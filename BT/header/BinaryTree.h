#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "Node.h"

class BinaryTree{

    private:
        Node* _rinsert(Node* current, int value);
        Node* _rminimum(Node* current);
        bool _rcontains(Node* current, int value);
        void _rremovemin(Node* current);
        Node* _rremove(Node* current, int value);
    public:
        Node* _root;
        BinaryTree();
        ~BinaryTree();
        void insert(int value);
        int minimum();
        bool contains(int value);
        void remove(int value);
        void remove_minimum();
        // preorder
        // inorder
        // postorder
        // levelorder

};

#endif
