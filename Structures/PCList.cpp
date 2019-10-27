#include "PCList.h"
#include <cstring>
#include <iostream>

using namespace std;

// Node constructor
PCList::PCNode::PCNode(char *postal_code, PCNode *prev, PCNode *next) {

    this->postal_code = new char[strlen(postal_code) + 1];
    strcpy(this->postal_code, postal_code);
    id_list = new IdentityCardList();

    this->next = next;
    this->prev = prev;
}

// Node Destructor
PCList::PCNode::~PCNode() {

    delete []postal_code;
    delete id_list;
}

// List Constructor
PCList::PCList() {

    start = NULL;
    end = NULL;
    size = 0;
}

// List Destructor
PCList::~PCList() {

    PCList::PCNode *node = start;
    while (node != NULL) {
        start = start->next;
        delete node;
        node = start;
    }
}

// Inserts list for postal code if it doesn not exist
void PCList::insert(char *postal_code) {

    if (exist(postal_code) == true) { // If the postal code already exists, we don't want it again
        return;
    }
    if (size > 0) {
        end->next = new PCNode(postal_code, end);
        end = end->next;
    } else {
        start = new PCNode(postal_code);
        end = start;
    }
    size += 1;
}

// Checks if postal code exists
bool PCList::exist(char *postal_code) {

    if (size > 0) {
        PCNode *node = start;
        while(node != NULL) {
            if (strcmp(node->postal_code, postal_code) == 0) {
                return true;
            }
            node = node->next;
        }
    }
    return false;
}

// Prints the postal codes and the voters
void PCList::print() {

    PCNode *node = start;
    while (node != NULL) {
        cout<<"List for PC "<<node->postal_code<<" has members: "<<endl;
        node->id_list->print();
        node = node->next;
    }
}

// Inserts voter info in postal code
void PCList::insertVoterInPC(char *identity_number, char *postal_code) {

    if (exist(postal_code) == false) {
        insert(postal_code);
    }
    PCNode *node = start;
    while (node != NULL) {
        if (strcmp(node->postal_code, postal_code) == 0) {
            node->id_list->insert(identity_number);
            return;
        }
        node = node->next;
    }
}

// Virtually deleted voter from postal code
void PCList::deleteVoterFromPC(char *identity_number, char *postal_code) {

    if (exist(postal_code) == false) {
        return;
    }
    PCNode *node = start;
    while (node != NULL) {
        if (strcmp(node->postal_code, postal_code) == 0) {
            node->id_list->delet(identity_number);
            return;
        } else {
            node = node->next;
        }
    }
}

void PCList::vote(char *key, char *postal_code) {

    if(exist(postal_code) == false) {
        return;
    }
    PCNode *node = start;
    while(node != NULL) {
        if (strcmp(node->postal_code, postal_code) == 0) {
            node->id_list->vote(key);
            return;
        }
        node = node->next;
    }
}

int PCList::votedpostcode(char *postal_code) {

    if(exist(postal_code) == false) {
        return -1; // Postal Code not found
    }
    PCNode *node = start;
    while (node != NULL) {
        if (strcmp(node->postal_code, postal_code) == 0) {
            return node->id_list->getVoted();
        }
        node = node->next;
    }
}

void PCList::votedperpc() {

    PCNode *node = start;
    while (node != NULL) {
        float percentage = node->id_list->statistics();
        cout<<percentage<<"% turnout for the area with postal code "<<node->postal_code<<endl;
        node = node->next;
    }
}