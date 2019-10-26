#include "PCList.h"
#include <cstring>
#include <iostream>

using namespace std;

PCList::PCNode::PCNode(char *postal_code, PCNode *prev, PCNode *next) {

    this->postal_code = new char[strlen(postal_code) + 1];
    strcpy(this->postal_code, postal_code);
    id_list = new IdentityCardList();

    this->next = next;
    this->prev = prev;
}

PCList::PCNode::~PCNode() {

    delete []postal_code;
    delete id_list;
}

PCList::PCList() {

    start = NULL;
    end = NULL;
    size = 0;
}

PCList::~PCList() {

    PCList::PCNode *node = start;
    while (node != NULL) {
        start = start->next;
        delete node;
        node = start;
    }
}

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

void PCList::print() {

    PCNode *node = start;
    while (node != NULL) {
        cout<<"List for PC "<<node->postal_code<<" has members: "<<endl;
        node->id_list->print();
        node = node->next;
    }
}

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