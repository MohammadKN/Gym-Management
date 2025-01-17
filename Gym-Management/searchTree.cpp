#pragma once

#include <iostream>
#include "Trainer.h"
using namespace std;


struct TreeNode {
    Trainer* trainer;  
    TreeNode* left;
    TreeNode* right;

    TreeNode(Trainer* trainer)
        : trainer(trainer), left(nullptr), right(nullptr) {}
};


class IDBinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, Trainer* trainer) {
        if (node == nullptr) {
            return new TreeNode(trainer);
        }

        if (trainer->getTrainerID() < node->trainer->getTrainerID()) {
            node->left = insertNode(node->left, trainer);
        }
        else if (trainer->getTrainerID() > node->trainer->getTrainerID()) {
            node->right = insertNode(node->right, trainer);
        }
        return node;
    }

    Trainer* searchNode(TreeNode* node, int id) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (id == node->trainer->getTrainerID()) {
            return node->trainer;
        }
        else if (id < node->trainer->getTrainerID()) {
            return searchNode(node->left, id);
        }
        else {
            return searchNode(node->right, id);
        }
    }

    void inOrderTraversal(TreeNode* node) const {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            node->trainer->displayTrainerDetails();
            inOrderTraversal(node->right);
        }
    }

public:
    IDBinarySearchTree() : root(nullptr) {}

    void insertTrainer(Trainer* trainer) {
        root = insertNode(root, trainer);
    }

    Trainer* searchTrainer(int id) const {
        return searchNode(root, id);
    }

    void displayTrainers() const {
        cout << "Trainers in ascending order by ID:" << endl;
        inOrderTraversal(root);
    }
};

