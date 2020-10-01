//
// Created by Christian Bain on 2019-06-10.
//

#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
#include "NodeInterface.h"

class Node : public NodeInterface {

public:
    int value;
    Node *left, *right;
    Node (int data) {
        value = data;
        left = NULL;
        right = NULL;
    }
    ~Node() {}

    int getData () const {
        return value;
    }
    NodeInterface * getLeftChild() const {
        if (left == NULL) {
            return NULL;
        }
        else {
            return left;
        }
    }
    NodeInterface * getRightChild() const {
        if (right == NULL) {
            return NULL;
        }
        else {
            return right;
        }
    }

private:
    void setValue (int data) {
        value = data;
    }
    void setLeftChild (Node* data) {
        left = data;
    }
    void setRightChild (Node* data) {
        right = data;
    }

};


#endif //BST_NODE_H
