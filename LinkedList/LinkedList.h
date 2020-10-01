//
// Created by Christian Bain on 2019-06-08.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "LinkedListInterface.h"
#include <string>
#include <iostream>
#include <sstream>

template <typename T>
class LinkedList : public LinkedListInterface<T> {

public:

    class Node {
    public:
        T data;
        Node *next;
        Node(T value) {
            data = value;
            next = NULL;
        }
        ~Node() {
        }
    };

    bool find(T value) {
        Node *check = head;
        while (check != NULL) {
            if (check->data == value) {
                return true;
            }
            check = check->next;
        }
        return false;
    };

    LinkedList(void) {
        head = NULL;
        length = 0;
    }
    ~LinkedList(void) {

    }

    void insertHead(T value) {
        if (find(value) == true) {
            return;
        }
        if (head == NULL) {
            head = new Node(value);
            length++;
            return;
        }
        else {
            Node *n = new Node(value);
            n->next = head;
            head = n;
            length++;
            return;
        }
    }

    void insertTail(T value) {
        if (head == NULL) {
            insertHead(value);
            return;
        }
        if (find(value) == true) {
            return;
        }

        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        if (current->next == NULL) {
            Node *newTail = new Node(value);
            current->next = newTail;
            newTail->next = NULL;
        }
        length++;
    }


    void insertAfter(T value, T insertionNode) {
        if (find(value) == true) {
            return;
        }
        Node *current = head;
        while (current != NULL) {
            if (current->data == insertionNode) {
                Node *newNode = new Node(value);
                newNode->next = current->next;
                current->next = newNode;
                length++;
            }
            current = current->next;
        }
    }

    void remove(T value) {
        if (!find(value)) {
            return;
        }
        Node *current = head;
        Node *remove = head;
        if (head->data == value) {
            current = current->next;
            delete remove;
            head = current;
            length--;
            return;
        }
        while (current->next != NULL) {
            if (current->next->data == value) {     // FIXME
                remove = current->next;
                current->next = remove->next;
                remove->next = NULL;
                delete remove;
                length--;
                return;
            }
            current = current->next;
        }
    }

    void clear() {
        length = 0;
        while (head != NULL) {
            Node *n = head->next;
            delete head;
            head = n;
        }
    }

    T at(int index) {
        if ((index < 0) || (index >= length)) {
            throw std::out_of_range("OOF");
        }
        else {
            Node *current = head;
            int i = 0;
            while (current != NULL) {
                if (i == index) {
                    return current->data;
                }
                current = current->next;
                i++;
            }
        }
    }

    int size() {
        return length;
    }

    string toString() {
        string list = "";
        Node *current = head;
        int i = 0;

        if (length == 0) {
            return list;
        }
        while (current != NULL) {
            stringstream ss;
            ss << current->data;
            list.append(ss.str());
            if (i < length - 1) {
                list.append(" ");
            }
            current = current->next;
            i++;
        }
        return list;
    }

private:
//    struct Node {
//        T data;
//        Node* next;
//    };
    Node *head;
    int length;
};


#endif //LINKEDLIST_LINKEDLIST_H
