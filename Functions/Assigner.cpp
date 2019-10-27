#include "Assigner.h"

#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

void assign(char *command, char *args, Fenrir *fenrir) {

    if (strcmp(command, "lbf") == 0) {

        char *key = strtok(args, " \n");
        bool exist = fenrir->lbf(key);
        if(exist == false) {
            cout<<"No"<<endl;
        } else {
            cout<<"Probably"<<endl;
        }
    } else if(strcmp(command, "lrb") == 0) {
        char *key = strtok(args, " \n");
        Voter *voter = fenrir->lrb(key);
        if (voter == NULL) {
            cout<<"Voter with id "<<key<<" was not found"<<endl;
        } else {
            voter->print();
        }
    } else if(strcmp(command, "ins") == 0) {

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
        delete id;
        delete name;
        delete surname;
        delete pc;
    } else if(strcmp(command, "find") == 0) {
        char *id_number = strtok(args, " \n");
        Voter *v = fenrir->findKey(id_number);
        if (v== NULL) {
            cout<<"No voter with id "<<id_number<<" was found"<<endl;
        } else {
            v->print();
        }
    } else if(strcmp(command, "delete") == 0) {
        char *key = strtok(args, " \n");
        fenrir->delet(key);
    } else if(strcmp(command, "vote") == 0) {
        // TODO vote
    } else if(strcmp(command, "load") == 0) {
        // TODO load
    } else if(strcmp(command, "voted") == 0) {
        // todo voted
    } else if(strcmp(command, "votedpostcode") == 0) {
        // TODO call from Parser with votedposcode arg
    } else if(strcmp(command, "votedperpc") == 0) {
        // TODO votedperpc
    } else if(strcmp(command, "exit") == 0) {
        // TODO exit
    }
}