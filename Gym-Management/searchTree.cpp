#include "TreeNode.h"


TreeNode* insertNode(TreeNode* node, int id) {
    if (node == nullptr) {
        return new TreeNode(id);
    }
    if (id < node->id) {
        node->left = insertNode(node->left, id);
    }
    else if (id > node->id) {
        node->right = insertNode(node->right, id);
    }
    return node;
}
int searchNode(TreeNode* node, int id) {
    if (node == nullptr) {
        return -1;
    }
    if (node->id == id) {
        return node->id;
    }
    if (id < (node->id)) {
        return searchNode(node->left, id);
    }
    else {
        return searchNode(node->right, id);
    }
}
void inOrderTraversal(TreeNode* node) {
    if (node) {
        inOrderTraversal(node->left);
        cout << node->id << endl;
        inOrderTraversal(node->right);
    }
}

void postOrderTraversal(TreeNode* node) {
    if (node) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->id << endl;
    }
}

void preOrderTraversal(TreeNode* node) {
    if (node) {
        cout << node->id << endl;
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void displayIds(TreeNode* root) {
    if (root == nullptr) {
        cout << "No ids available." << endl;
    }
    else {
        cout << "Ids (sorted with In Order ):" << endl;
        inOrderTraversal(root);
        cout << "Ids (sorted with Post Order ):" << endl;
        postOrderTraversal(root);
        cout << "Ids (sorted with Pre Order ):" << endl;
        preOrderTraversal(root);
    }
}

