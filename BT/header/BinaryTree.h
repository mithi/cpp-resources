#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <vector>
#include "Node.h"

using namespace std;

class BinaryTree{

    private:
        Node* _rminimum(Node* current);
        bool _rcontains(Node* current, int value) ;
        Node* _rinsert(Node* current, int value);
        Node* _rremove(Node* current, int value);
        Node* _rremovemin(Node* current);
        void _rinorder(Node* current, vector<int>& v);
    public:
        Node* _root;
        BinaryTree();
        ~BinaryTree();
        bool contains(int value);
        void insert(int value);
        void remove(int value);
        void remove_minimum();
        vector<int> inorder();

        // postorder
        // levelorder

};

#endif
