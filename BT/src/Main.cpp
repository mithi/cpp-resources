#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){

    int values[] = {8, 3, 1, 7, 2, 5, 9, 6, 4, 11};
    BinaryTree BT;

    for(int i = 0; i < 9; i++) {
        BT.insert(values[i]);
    }

    for(int i = 0; i < 9; i++) {
        assert(BT.contains(values[i]));
    }

    assert(BT.minimum()==1);
    assert(BT.contains(0)==false);
    assert(BT.contains(10)==false);
    assert(BT.contains(12)==false);

    return 0;
}
