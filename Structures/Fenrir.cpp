#include "Fenrir.h"

Fenrir::Fenrir(unsigned long bf_size) {

    voters_bf = new BloomFilter(bf_size);
    rbTree = new RBTree();
    pcList = new PCList();

}

Fenrir::~Fenrir() {

    delete voters_bf;
    delete rbTree;
    delete pcList;
}

bool Fenrir::insert(Voter *voter) {

    bool in_bf;
    in_bf = voters_bf->exist(voter->id_number);
    if (in_bf == false) { // Voter with 100% certainty does not exist in RBTree and PCList so add him
        voters_bf->insert(voter->id_number); // Bloom Filter position must change to 1
        rbTree->insert(voter);
        pcList->insertVoterInPC(voter->id_number, voter->postal_code);
        return true;
    } else { // Voter might exist (false positive) in RBTree and PCList - look for him
        bool in_rbtree = rbTree->exist(voter->id_number);
        if (in_rbtree == false) { // If the voter was not found, add him in the data structures
            rbTree->insert(voter);
            pcList->insertVoterInPC(voter->id_number, voter->postal_code);
            return true;
        }
        return false;
    }
}