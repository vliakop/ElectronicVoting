#include "Parser.h"
#include "Validator.h"
#include <cstring>
#include <iostream>

using namespace std;

void parse(char *commandline) {

    char command[14]; // Arketi mnimi gia ti megaliteri entoli pou mporei na dosei o xristis
    char arguments[500];
    char *commandline_copy = new char[strlen(commandline) + 1]; // Antigrafo tis entolis
    strcpy(commandline_copy, commandline);

    char delims[] = " \n\t";
    char *token;

    // Pare tin entolis
    token = strtok(commandline_copy, " ");
    strcpy(command, token);
    cout<<"Command given: "<<command<<endl;

    // Pare ta orismata
    token = strtok(NULL, "\n");
    if (token != NULL) {
        strcpy(arguments, token);
    }

    if (strcmp(command, "lbf") == 0) {
        // TODO lbf
        keyValidator(token);
    } else if (strcmp(command, "lrb") == 0) {
        // TODO lrb
        keyValidator(token);
    } else if (strcmp(command, "ins") == 0) {
        // TODO ins
        recordValidator(token);
    } else if (strcmp(command, "find") == 0) {
        // TODO find
        keyValidator(token);
    } else if (strcmp(command, "delete") == 0) {
        // TODO delete
        keyValidator(token);
    } else if (strcmp(command, "vote") == 0) {
        // TODO vote
        keyValidator(token);
    }  else if (strcmp(command, "load") == 0) {
        // TODO load
        keyValidator(token);
    } else if (strcmp(command, "voted") == 0) {
        if (token == NULL) {
            // TODO voted
        } else if (strcmp(token, "postcode") == 0){
            // TODO voted postcode
        } else {
            cout<<"Invalid syntax for voted-family functions"<<endl;
        }
        // TODO voted + voted postcode
    } else if (strcmp(command, "votedperpc") == 0) {
        // TODO votedperpc
    } else if (strcmp(command, "exit") == 0) {
        // TODO exit
    } else {
        cout<<"Wrong command given "<<command<<endl;
    }


    delete []commandline_copy;
}

