#include "Fenrir.h"

// Constructor
Fenrir::Fenrir(unsigned long bf_size) {

    voters_bf = new BloomFilter(bf_size);
    rbTree = new RBTree();
    pcList = new PCList();
    size = 0;
    disabled = 0;
    voted = 0;
}

// Destructor
Fenrir::~Fenrir() {

    delete voters_bf;
    delete rbTree;
    delete pcList;
    int a = 1;
}

// Inserts the voter
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
        } else if (in_rbtree == true) { // If the voter is virtually deleted (exists with isActive = 0 -> activate him)
            Voter *v = rbTree->fetchVoter(voter->id_number);
            if (v->isActive == false) {
                v->isActive = true;
                v->hasVoted = false;
                size += 1;
            }
        }
        return false;
    }
}

// Looks in BloomFilter
bool Fenrir::lbf(char *key) {
    return voters_bf->exist(key);
}

// Looks in RBTree
Voter* Fenrir::lrb(char *key) {
    return rbTree->fetchVoter(key);
}

// Looks in the Structures
Voter* Fenrir::findKey(char *key) {

    bool in_bf = voters_bf->exist(key); // Search in boom filter
    if (in_bf == false) { // Not found in bloom filter: certainly does not exist
        return NULL;
    } else { // If it exists in the bloom filter it could be a false positive, we have to search in the tree
        return rbTree->fetchVoter(key);
    }
}

// Virtually deletes a voter by setting the field 'isActive' to false
int Fenrir::delet(char *key) {

    Voter *v = rbTree->fetchVoter(key);
    if (v == NULL) {
        return 0;   // Not found
    }
    if (v->isActive == false) { // Can't delete a voter if already deleted
        return 0; // Not found
    }
    v->isActive = false; // Virtually delete him
    disabled += 1;
    if (v->hasVoted == true) { // One less voter
        voted -= 1;
    }
    pcList->deleteVoterFromPC(key, v->postal_code); // Virtually delete him from the PostalCode List
    return 1;   // Deleted

}

// Marks hasVoted as true
int Fenrir::vote(char *key) {

    Voter *v = rbTree->fetchVoter(key);
    if (v == NULL) {
        return 0; // Voter does not exist
    } else if (v->isActive == false) {
        return 0; // Voter is virtually deleted - cannot vote
    } else if (v->hasVoted == true) {
        return 2; // Voter has already voted
    } else { // Mark hasVoted = true
        v->hasVoted = true;
        voted += 1;
        pcList->vote(v->id_number, v->postal_code);
        return 1;
    }
}

// Returns the total number of voters
int Fenrir::voted_f() {

    return voted;
}

// Returns the total number of voters for a given Postal Code
int Fenrir::votedpostcode(char *postal_code) {

    return pcList->votedpostcode(postal_code);
}

// Prints the percentage of voters for each Postal Code
void Fenrir::votedperpc() {

    pcList->votedperpc();
}