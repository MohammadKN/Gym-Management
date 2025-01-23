// TreeNode.h
#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
using namespace std;

struct TreeNode {
    int id;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int id) : id(id), left(nullptr), right(nullptr) {}
};
void displayIds(TreeNode* node);
int searchNode(TreeNode* node, int id);
TreeNode* insertNode(TreeNode* node, int id);
#endif 

