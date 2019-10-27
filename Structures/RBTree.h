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
        bool hasVoted;
        bool isActive;
        Node *left;
        Node *right;
        Node *parent;

        Node(Voter *voter, Node *parent = NULL, Node *left = NULL, Node *right = NULL);
        ~Node();

        bool exist(char *identity_number);
        Voter *fetchVoter(char *identity_number);
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
    bool exist(char *identity_number); // Added functionality
    Voter *fetchVoter(char *identity_number);


private:

    Node *root;
    int size;

    Node* BSTInsert(Node* root, Node *pt);
};

#endif
