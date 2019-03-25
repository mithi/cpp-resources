#ifndef TESTS_H_
#define TESTS_H_

#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void tests() {

    vector<int> answer1 = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11};
    vector<int> answer2 = {0, 4, 5, 6, 7, 8, 9, 10, 11, 13};
    vector<int> answer3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    vector<int> answer4 = {0, 1, 2, 3, 4, 5, 6, 8, 9, 11, 12, 13};

    int values[] = {8, 3, 1, 7, 2, 5, 10, 6, 4, 11};
    BinaryTree BT;

    for(int i = 0; i < 10; i++) {
        BT.insert(values[i]);
    }


    for(int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        assert(BT.contains(values[i]));
    }

    assert(BT.contains(0)==false);
    assert(BT.contains(12)==false);
    assert(BT.contains(9)==false);

    assert(BT.inorder()==answer1);

    BT.remove_minimum();
    BT.remove_minimum();
    BT.remove_minimum();

    BT.insert(0);
    BT.insert(13);
    BT.insert(9);

    assert(BT.inorder()==answer2);

    BT.insert(2);
    BT.insert(1);
    BT.insert(3);
    BT.insert(12);

    assert(BT.inorder()==answer3);

    BT.remove(7);
    BT.remove(10);
    assert(BT.inorder()==answer4);

    cout << "No problems encountered. :)" << endl;
}

#endif
