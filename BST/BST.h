//
// Created by Christian Bain on 2019-06-10.
//

#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface {
public:
    BST ();
    ~BST ();

    NodeInterface * getRootNode() const;
    bool insert(Node* &T, int data);
    bool add(int data);
    bool unInsert(Node* &T, int data);
    bool remove(int data);
    void clear();
    bool find(Node *T, int val);

    Node *root;
    int size;

};