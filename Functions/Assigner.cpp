#include "Assigner.h"
#include "../Files/FileOperations.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

// Receives the command and the arguements. Tokenizes the arguments, Fenrir applies the changes in the structures and prints diagnostics
void assign(char *command, char *args, Fenrir *fenrir) {

    if (strcmp(command, "lbf") == 0) {
        char *key = strtok(args, " \n");
        bool exist = fenrir->lbf(key);
        if(exist == false) {    // If not found in BloomFilter, the record does not exist
            cout<<"No"<<endl;
        } else {
            cout<<"Probably"<<endl; // If found, it probably exists (could be a false positive
        }
    } else if(strcmp(command, "lrb") == 0) {
        char *key = strtok(args, " \n");
        Voter *voter = fenrir->lrb(key);
        if (voter == NULL) {
            cout<<"Voter with id "<<key<<" was not found"<<endl;
        } else if (voter->isActive == false){   // Virtually deleted
            cout<<"Voter with id "<<key<<" was not found"<<endl;
        } else {
            voter->print();
        }
    } else if(strcmp(command, "ins") == 0) { // Tokenizes the input and inserts in the data structures
        // id, name, surname, age, gender, postal code
        char *token, *id, *name, *surname, *pc, gender;
        int age;

        token = strtok(args, " "); // Get the id_number
        id = new char[strlen(token) + 1];
        strcpy(id, token);

        token = strtok(NULL, " "); // Get the name
        name = new char[strlen(token) + 1];
        strcpy(name, token);

        token = strtok(NULL, " "); // Get the surname
        surname = new char[strlen(token) + 1];
        strcpy(surname, token);

        token = strtok(NULL, " "); // Get the age
        age = atoi(token);

        token = strtok(NULL, " "); // Get the gender
        gender = token[0];

        token = strtok(NULL, " \n"); // Get the postal code
        pc = new char[strlen(token) + 1];
        strcpy(pc, token);

        fenrir->insert(new Voter(id, name, surname, age, gender, pc));
        cout<<"Executed!"<<endl;
        delete id;
        delete name;
        delete surname;
        delete pc;
    } else if(strcmp(command, "find") == 0) { // Searches in BloomFilter, if found it searches in the RBTree, else prints message
        char *id_number = strtok(args, " \n");
        Voter *v = fenrir->findKey(id_number);
        if (v == NULL) {
            cout<<"No voter with id "<<id_number<<" was not found"<<endl;
        } else {
            if (v->isActive == true) {
                v->print();
            } else {   // Exclude the virtually deleted
                cout<<"No voter with id "<<id_number<<" was not found"<<endl;
            }

        }
    } else if(strcmp(command, "delete") == 0) {
        char *key = strtok(args, " \n");
        int code = fenrir->delet(key);
        if (code == 0) { // Not found
            cout<<"Voter with id "<<key<< "was not found"<<endl;
        } else { // Succesfully virtually deleted
            cout<<"Voter with id "<<key<<" deleted"<<endl;
        }
    } else if(strcmp(command, "vote") == 0) {
        char *id_number = strtok(args, " \n");
        int code = fenrir->vote(id_number);
        if (code == 0) { // Not found
            cout<<"Voter with id "<<id_number<<" was not found"<<endl;
        } else if (code == 1) { // Voted
            cout<<"Voter with id "<<id_number<<" has succesfully voted"<<endl;
        } else if (code == 2){ // Has already voted
            cout<<"Voter with id "<<id_number<<" has already voted"<<endl;
        }
    } else if(strcmp(command, "load") == 0) {
        char *filename = strtok(args, " \n");
        readIDs(filename, fenrir);
    } else if(strcmp(command, "voted") == 0) {
        int voted = fenrir->voted_f();
        cout<<voted<<" voter(s) have voted so far"<<endl;
    } else if(strcmp(command, "votedpostcode") == 0) {
        char *postcode = strtok(args, " \n");
        int voted = fenrir->votedpostcode(postcode);
        if (voted == -1) {
            cout<<"Area with postal code "<<postcode<<" was not found"<<endl;
        } else {
            cout<<voted<<" voters voted in the area with postal code "<<postcode<<endl;
        }
    } else if(strcmp(command, "votedperpc") == 0) {
        fenrir->votedperpc();
    } else if(strcmp(command, "exit") == 0) {
        cout<<"Now exiting..."<<endl;
    }
}