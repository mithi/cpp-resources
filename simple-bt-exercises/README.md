# Simple Binary Tree Exercises

## Introduction
- Pre-order
- In-order
- Post-order
- Level-order (list of lists)
- Implement both recursive and iterative implementations.

## Recursive Problems

### Top-down
- Pre-order traversal (root, left, right)

```
1. return specific value for null node
2. update the answer if need
3. left_answer = top_down(root.left, leftparameters)
4. right_answer = top_down(root.right, rightparamerters)
5. return answer if needed

rmax_depth(root, depth, answer):
    if root is null: return
    if root is leaf_node: answer = max(answer, depth)
    rmax_depth(root.left, depth + 1, answer)
    rmax_depth(root.left, depth + 1, answer)

rmax_depth(root, 0, 0)
```
### Bottom-up
- post-order traversal (left, right, root)
```
1. return specific value for null node
2. left_answer = bottom_up(root.left)
3. right_answer = bottom_up(root.right)
4. return answers

max_depth(root):
    if root is null: return 0
    left_answer = max_depth(root.left)
    right_answer = max_depth(root.right)
    return max(left_answer, right_answer) + 1
```

## Exercises
1. Get Maximum depth of binary tree
2. Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
3. Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
4. List all the paths in a tree that add up to the given sum. (list of lists of integets)
5. Construct a tree from inorder and preorder lists
6. Construct a tree from inorder and postoder lists
7. You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL. Initially, all next pointers are set to NULL
8. Do the above problem except the binary tree is not perfect
9. Lowest common ancestor

```
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

 “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

```
10. Serialize and deserialize
```
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
```
