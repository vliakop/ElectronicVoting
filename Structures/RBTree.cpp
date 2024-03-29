#include "RBTree.h"
#include <iostream>

using namespace std;

// Node Constructor
RBTree::Node::Node(Voter *voter, RBTree::Node *parent, RBTree::Node *left, RBTree::Node *right) {

    this->voter = voter;
    this->parent = parent;
    this->isActive = true;
    this->hasVoted = false;
    this->left = left;
    this->right = right;
}

// Node Destructor
RBTree::Node::~Node() {

    delete voter;
    if (left != NULL) {
        delete left;
    }
    if (right != NULL) {
        delete right;
    }
}

// Checks if certain id_number exists
bool RBTree::Node::exist(char *identity_number) {

    if (strcmp(voter->id_number, identity_number) == 0) {   // If it's the current node return true
        return true;
    }
    bool left_search = false;
    bool right_search = false;

    if (left != NULL) { // Search the left subtree
        left_search = left->exist(identity_number);
    }
    if (left_search == false && right != NULL) { // If id was not found in left subtree, search the right and return the results
        right_search = right->exist(identity_number);
        return right_search;
    } else { // Else return the (positive) result of left-subtree search
        return left_search;
    }
}

Voter* RBTree::Node::fetchVoter(char *identity_number) {

    if(strcmp(voter->id_number, identity_number) == 0) { // If it's the current node return
        return voter;
    }
    Voter* left_search = NULL;
    Voter* right_search = NULL;
    if (left != NULL) { // Search the left subtree
        left_search = left->fetchVoter(identity_number);
    }
    if (left_search == NULL && right != NULL) { // If id was not found in left subtree, search the right and return the results
        right_search = right->fetchVoter(identity_number);
        return right_search;
    } else { // Else return the (positive) result of left-subtree search
        return left_search;
    }
}

// Tree Constructor
RBTree::RBTree() {

    root = NULL;
    size = 0;
}

// Tree Destructor
RBTree::~RBTree() {

    delete root;
}

// Node visiting pattern - adjusted code from geeksforgeeks
void RBTree::inorder() {

    inorderHelper(root);
}

// A recursive function to do level order traversal - adjusted code from geeksforgeeks
void RBTree::inorderHelper(RBTree::Node* root) {
    if (root == NULL)
        return;

    inorderHelper(root->left);
    root->voter->print();
    inorderHelper(root->right);
}

// Function to insert a new node with given data - adjusted code from geeksforgeeks
void RBTree::insert(Voter *voter)
{
    Node *pt = new Node(voter);

    // Do a normal BST insert
    root = BSTInsert(root, pt);

    // fix Red Black Tree violations
    fixViolation(root, pt);
    size += 1;
}

/* A utility function to insert a new node with given key
   in BST */
// adjusted code from geeksforgeeks
RBTree::Node* RBTree::BSTInsert(RBTree::Node *root, RBTree::Node *pt) {
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return pt;

    /* Otherwise, recur down the tree */
    int compare = alphabetical_order(root->voter->id_number, pt->voter->id_number);
    if (compare < 0) {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (compare > 0) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}

// adjusted code from geeksforgeeks
void RBTree::rotateLeft(Node *&root, Node *&pt)
{
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

// adjusted code from geeksforgeeks
void RBTree::rotateRight(Node *&root, Node *&pt)
{
    Node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

// This function fixes violations caused by BST insertion
// adjusted code from geeksforgeeks
void RBTree::fixViolation(Node *&root, Node *&pt)
{
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->colour != BLACK) && (pt->parent->colour == RED)) {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /*  Case : A
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left) {

            Node *uncle_pt = grand_parent_pt->right;

            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->colour == RED) {
                grand_parent_pt->colour = RED;
                parent_pt->colour = BLACK;
                uncle_pt->colour = BLACK;
                pt = grand_parent_pt;
            } else {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->colour, grand_parent_pt->colour);
                pt = parent_pt;
            }
        } else {  /* Case : B Parent of pt is right child of Grand-parent of pt */
            Node *uncle_pt = grand_parent_pt->left;
            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->colour == RED)) {
                grand_parent_pt->colour = RED;
                parent_pt->colour = BLACK;
                uncle_pt->colour = BLACK;
                pt = grand_parent_pt;
            } else {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->colour, grand_parent_pt->colour);
                pt = parent_pt;
            }
        }
    }
    root->colour = BLACK;
}

// Returns the distance between 2 strings
int RBTree::alphabetical_order(char *str1, char *str2) {

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int compare = 0;
    if(len1 < len2) { // If string1 is longer than string2, compare until string1 is over
        for (int i = 0; i < len1; i++)  {
            if (str1[i] != str2[i]) {
                compare = (str1[i] - str2[i]);
                break;
            }
        }
    } else { // If string12 is longer than string1, compare until string2 is over
        for (int i = 0; i < len2; i++) {
            if (str1[i] != str2[i]) {
                compare = (str1[i] - str2[i]);
                break;
            }
        }
    }
    return compare;
}

// Checks if id_number exists
bool RBTree::exist(char *identity_number) {

    if (root == NULL) {
        return false;
    }
    return root->exist(identity_number);
}

// Returns Voter if exists, else NULL
Voter* RBTree::fetchVoter(char *identity_number) {

    if(exist(identity_number) == false) {
        return NULL;
    }
    return root->fetchVoter(identity_number);

}