#include "Fenrir.h"

Fenrir::Fenrir(unsigned long bf_size) {

    voters_bf = new BloomFilter(bf_size);
    rbTree = new RBTree();
    pcList = new PCList();
    size = 0;
    disabled = 0;
    voted = 0;

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
        size += 1;
        return true;
    } else { // Voter might exist (false positive) in RBTree and PCList - look for him
        bool in_rbtree = rbTree->exist(voter->id_number);
        if (in_rbtree == false) { // If the voter was not found, add him in the data structures
            rbTree->insert(voter);
            pcList->insertVoterInPC(voter->id_number, voter->postal_code);
            size += 1;
            return true;
        }
        return false;
    }
}

bool Fenrir::lbf(char *key) {
    return voters_bf->exist(key);
}

Voter* Fenrir::lrb(char *key) {
    return rbTree->fetchVoter(key);
}

Voter* Fenrir::findKey(char *key) {

    bool in_bf = voters_bf->exist(key); // Search in boom filter
    if (in_bf == false) { // Not found in bloom filter: certainly does not exist
        return NULL;
    } else { // If it exists in the bloom filter it could be a false positive, we have to search in the tree
        return rbTree->fetchVoter(key);
    }
}

bool Fenrir::delet(char *key) {

    Voter *v = lrb(key);
    if (v == NULL) {
        return false;
    }
    v->isActive = false;
    disabled += 1;
    pcList->deleteVoterFromPC(key, v->postal_code);
    return true;

}