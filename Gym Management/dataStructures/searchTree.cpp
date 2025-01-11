#pragma once

#include <iostream>
using namespace std;


struct TreeNode {
    int ID;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int id) : ID(id), left(nullptr), right(nullptr) {}
};

class IDBinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int id) {
        if (node == nullptr) {
            return new TreeNode(id);
        }

        if (id < node->ID) {
            node->left = insertNode(node->left, id);
        }
        else if (id > node->ID) {
            node->right = insertNode(node->right, id);
        }
        return node;
    }

    TreeNode* searchNode(TreeNode* node, int id) const {
        if (node == nullptr || node->ID == id) {
            return node;
        }

        if (id < node->ID) {
            return searchNode(node->left, id);
        }
        else {
            return searchNode(node->right, id);
        }
    }

    void inOrderTraversal(TreeNode* node) const {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->ID << " ";
            inOrderTraversal(node->right);
        }
    }

public:

    IDBinarySearchTree() : root(nullptr) {}


    void insertID(int id) {
        root = insertNode(root, id);
    }


    bool searchID(int id) const {
        return searchNode(root, id) != nullptr;
    }

    void displayIDs() const {
        cout << "IDs in ascending order: ";
        inOrderTraversal(root);
        cout << endl;
    }
};
