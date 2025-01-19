#pragma once
#include <map>
#include <iostream>

using namespace std;

class IDBinarySearchTree {
private:
    struct TreeNode {
        int* id;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int* id)
            : id(id), left(nullptr), right(nullptr) {
        }
    };

    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int* id) {
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

    int* searchNode(TreeNode* node, int* id) const {
        if (node == nullptr) {
            return nullptr;
        }
        if (id == node->id) {
            return node->id; 
        }
        if (id < node->id) {
            return searchNode(node->left, id);
        }
        else {
            return searchNode(node->right, id);
        }
    }

    void inOrderTraversal(TreeNode* node) const {
        if (node) {
            inOrderTraversal(node->left);
            cout<<node->id<<endl;
            inOrderTraversal(node->right);
        }
    }
    void postOrderTraversal(TreeNode* node) const {
        if (node) {
            inOrderTraversal(node->left);
            inOrderTraversal(node->right);
            cout << node->id<< endl;
        }
    }
    void preOrderTraversal(TreeNode* node) const {
        if (node) {
            cout << node->id << endl;
            inOrderTraversal(node->left);
            inOrderTraversal(node->right);
        }
    }

public:
    IDBinarySearchTree() : root(nullptr) {}

    void insertId(int* id) {
        root = insertNode(root, id);
    }

    int* searchId(int* id) const {
        return searchNode(root, id);
    }

    void displayIds() const {
        if (root == nullptr) {
            cout << "No ids available." << endl;
        }
        else {
            cout << "Ids (sorted with In Order Traversal):" << endl;
            inOrderTraversal(root);
            cout << "Ids (sorted with Post Order Traversal):" << endl;
            postOrderTraversal(root);
            cout << "Ids (sorted with Pre Order Traversal):" << endl;
            preOrderTraversal(root);
        }
    }
};
