#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main(int argc, char *argv[]){

    int values[] = {8, 3, 1, 7, 2, 5, 10, 6, 4, 11};
    BinaryTree BT;

    for(int i = 0; i < 10; i++) {
        BT.insert(values[i]);
    }

    for(int i = 0; i < 10; i++) {
        assert(BT.contains(values[i]));
    }

    assert(BT.minimum()==1);
    assert(BT.contains(0)==false);
    assert(BT.contains(12)==false);

    vector<int> path = BT.inorder();
    print_vector(path);
    // 1 2 3 4 5 6 7 8 10 11

    BT.remove_minimum();
    BT.remove_minimum();
    BT.remove_minimum();

    BT.insert(0);
    BT.insert(13);
    BT.insert(9);

    vector<int> path2 = BT.inorder();
    print_vector(path2);
    // 0 4 5 6 7 8 9 10 11 13

    BT.insert(2);
    BT.insert(1);
    BT.insert(3);

    vector<int> path3 = BT.inorder();
    print_vector(path3);
    // 0 1 2 3 4 5 6 7 8 9 10 11 13

    //BT.remove(7);
    //vector<int> path4 = BT.inorder();
    //print_vector(path4);


    return 0;
}
