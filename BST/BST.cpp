//
// Created by Christian Bain on 2019-06-10.
//

#include "BST.h"

using namespace std;

    BST::BST() {
        root = NULL;
        size = 0;
    }
    BST::~BST() {
        clear();
    }

    bool BST::find(Node *T, int val) {
        if (T == NULL) {
            return false;
        }
        if (T->value == val) {
            return true;
        }
        if (val < T->value) {
            return find(T->left, val);
        }
        if (val > T->value) {
            return find(T->right, val);
        }
    };

    NodeInterface * BST::getRootNode() const {
        return root;
    }

    bool BST::insert(Node* &T, int data) {
        if (find(T, data)) {
            return false;
        }
        if (T == NULL) {
            T = new Node(data);
            size++;
            return true;
        }
        if (T->value == data) {
            return false;
        }
        else if (T->value > data) {
            return insert(T->left, data);
        }
        else {
            return insert(T->right, data);
        }
    }

    bool BST::add(int data) {
        return insert(root, data);
    }

    int getHighest(Node *T) {
        if (T->right == NULL) {
            return T->value;
        }
        else {
            return getHighest(T->right);
        }
    }

    bool hasNoChildren(Node* curr) {
        if (curr->left == NULL && curr->right == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    bool hasTwoChildren(Node* curr) {
        if (curr->left != NULL && curr->right != NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    bool hasLeftChild(Node* curr) {
        if (curr->left != NULL && curr->right == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    bool hasRightChild(Node* curr) {
        if (curr->left == NULL && curr->right != NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    bool BST::unInsert(Node* &deletion, int data) {
        if (!find(deletion, data)) {
            return false;
        }
        if (deletion == NULL) {
            return false;
        }
        if (deletion->value < data) {
            return unInsert(deletion->right, data);
        }
        else if (deletion->value > data) {
            return unInsert(deletion->left, data);
        }
        else {
            if (hasNoChildren(deletion)) {
                delete deletion;
                deletion = NULL;
                size--;
                return true;
            }
            else if (hasTwoChildren(deletion)) {
                int n = getHighest(deletion->left);
                unInsert(deletion->left, n);
                deletion->value = n;
                size--;
                return true;
            }
            else if (hasLeftChild(deletion)) {
                Node *curr = deletion;
                deletion = curr->left;
                delete curr;
                size--;
                return true;
            }
            else if (hasRightChild(deletion)) {
                Node *curr = deletion;
                deletion = curr->right;
                delete curr;
                size--;
                return true;
            }
        }
    };

    bool BST::remove(int data) {
        return unInsert(root, data);
    }

    void BST::clear() {
        while (root != NULL) {
            remove(root->value);
        }
    }