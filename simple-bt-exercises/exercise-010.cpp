/*
Serialization is the process of converting a data structure
or object into a sequence of bits so that it can be stored
in a file or memory buffer, or transmitted across a network
connection link to be reconstructed later in the same or
another computer environment.

Design an algorithm to serialize and deserialize a binary tree.
There is no restriction on how your serialization/deserialization
algorithm should work. You just need to ensure that a binary tree
can be serialized to a string and this string can be deserialized
to the original tree structure.
*/
class Codec {
public:

    TreeNode* rdeserialize(stringstream& ss) {
        string x;
        ss >> x;

        if (x == "X") { return NULL; }

        TreeNode* root = new TreeNode(stoi(x));
        root->left = rdeserialize(ss);
        root->right = rdeserialize(ss);
        return root;
    }

    string serialize(TreeNode* root) {

        if (root == NULL) { return "X "; }

        return to_string(root->val) + " "
            + serialize(root->left)
            + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return rdeserialize(ss);
    }
};
