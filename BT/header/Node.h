#ifndef NODE_H_
#define NODE_H_

class Node {
    public:
        Node(int val);
        ~Node();
        int data;
        Node *left;
        Node *right;
};

#endif
