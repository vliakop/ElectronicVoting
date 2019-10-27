#include "IdentityCardList.h"
#include <cstring>
#include <iostream>

using namespace std;

// Node Constructor
IdentityCardList::IDNode::IDNode(char *identity_number, IDNode *prev, IDNode *next) {

    this->identity_number = new char[strlen(identity_number) + 1];
    strcpy(this->identity_number, identity_number);

    this->next = next;
    this->prev = prev;
    this->hasVoted = false;
    this->isActive = true;
}

// Node Destructor
IdentityCardList::IDNode::~IDNode() {

    delete []identity_number;
}

// List Constructor
IdentityCardList::IdentityCardList() {

    start = NULL;
    end = NULL;
    size = 0;
    disabled = 0;
    voted = 0;
}

// List Destructor
IdentityCardList::~IdentityCardList() {

    IdentityCardList::IDNode *node = start;
    while (node != NULL) {
        start = start->next;
        delete node;
        node = start;
    }
}

// Insert in list
void IdentityCardList::insert(char *identity_number) {

    if (size > 0) { // If the list has members, check if already exists and add
        if (exist(identity_number) == true) {
            return;
        }
        end->next = new IDNode(identity_number, end);
        end = end->next;
    } else {    // If it's empty just add
        start = new IDNode(identity_number);
        end = start;
    }
    size += 1;
}

// Check if id_number exists
bool IdentityCardList::exist(char *identity_number) {

    if (size > 0) {
        IDNode *node = start;
        while(node != NULL) {
            if (strcmp(node->identity_number, identity_number) == 0) {
                return true;
            }
            node = node->next;
        }
    }
    return false;
}

// Print the list and who has voted
void IdentityCardList::print() {

    IDNode *node = start;
    while(node != NULL) {
        cout<<node->identity_number<<" ";
        if (node->hasVoted == true) {
            cout<<"has voted"<<endl;
        } else {
            cout<<"has not voted"<<endl;
        }
        node = node->next;
    }
}

// Virtually delete a voter by setting isActive = false
void IdentityCardList::delet(char *identity_number) {

    IDNode *node = start;
    while (node != NULL) {
        if (strcmp(node->identity_number, identity_number) == 0) {
            if (node->isActive == false) {  // Can't delete if already deleted
                return;
            }
            node->isActive = false;
            this->disabled += 1;
            if (node->hasVoted == true) {
                this->voted -= 1;
            }
            return;
        }
        node = node->next;
    }
}

// Set hasVoted = true
void IdentityCardList::vote(char *identity_number) {

    IDNode *node = start;
    while (node != NULL) {
        if (strcmp(node->identity_number, identity_number) == 0) { // If voter found mark that he has voted
            node->hasVoted = true;
            this->voted += 1;
        }
        node = node->next;
    }
}

// Return the field 'voted'
int IdentityCardList::getVoted() {

    return voted;
}

// Return percentage of total voters and those who have voted
float IdentityCardList::statistics() {

    if (size - disabled > 0) {
        return (float) 100 *voted/(size - disabled);
    } else {
        return 0;
    }
}