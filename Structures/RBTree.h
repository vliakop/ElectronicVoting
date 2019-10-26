#ifndef RBTREE_H
#define RBTREE_H

#define BLACK true
#define RED false

#include "Voter.h"
#include <cstring>

class RBTree {

public:
    struct Node {

        Voter *voter;
        bool colour;
        Node *left;
        Node *right;
        Node *parent;

        Node(Voter *voter, Node *parent = NULL, Node *left = NULL, Node *right = NULL);
        ~Node();
    };
    RBTree();
    ~RBTree();
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
    void insert(Voter *voter);
    void inorder();
    void inorderHelper(Node *);
    int alphabetical_order(char *str1, char *str2);


private:

    Node *root;
    Node* BSTInsert(Node* root, Node *pt);
};

#endif
