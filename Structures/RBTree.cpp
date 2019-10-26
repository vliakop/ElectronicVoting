#include "RBTree.h"
#include <iostream>

using namespace std;
RBTree::Node::Node(Voter *voter, RBTree::Node *parent, RBTree::Node *left, RBTree::Node *right) {

    this->voter = voter;
    this->parent = parent;
    this->left = left;
    this->right = right;
}

RBTree::Node::~Node() {

    delete voter;
}

RBTree::RBTree() {

    root = NULL;
}

RBTree::~RBTree() {

    // TODO Destructor
}

void RBTree::inorder() {

    inorderHelper(root);
}

// A recursive function to do level order traversal
void RBTree::inorderHelper(RBTree::Node* root) {
    if (root == NULL)
        return;

    inorderHelper(root->left);
    root->voter->print();
    inorderHelper(root->right);
}

// Function to insert a new node with given data
void RBTree::insert(Voter *voter)
{
    Node *pt = new Node(voter);

    // Do a normal BST insert
    root = BSTInsert(root, pt);

    // fix Red Black Tree violations
    fixViolation(root, pt);
}

/* A utility function to insert a new node with given key
   in BST */

RBTree::Node* RBTree::BSTInsert(RBTree::Node *root, RBTree::Node *pt) {
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return pt;

    /* Otherwise, recur down the tree */
    if (alphabetical_order(root->voter->id_number, pt->voter->id_number) < 0) { // TODO alphabetical ordering
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (alphabetical_order(root->voter->id_number, pt->voter->id_number) > 0) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}

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
void RBTree::fixViolation(Node *&root, Node *&pt)
{
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->colour != BLACK) &&
           (pt->parent->colour == RED))
    {

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

int RBTree::alphabetical_order(char *str1, char *str2) {

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    cout<<"Comparing strings "<<str1<<" and "<<str2<<endl;
    int compare = 0;
    if(len1 < len2) {
        for (int i = 0; i < len1; i++)  {
            if (str1[i] != str2[i]) {
                compare = (str1[i] - str2[i]);
                break;
            }
        }
    } else {
        for (int i = 0; i < len2; i++) {
            if (str1[i] != str2[i]) {
                compare = (str1[i] - str2[i]);
                break;
            }
        }
    }
    cout<<"compare is "<<compare<<endl;
    return compare;
}