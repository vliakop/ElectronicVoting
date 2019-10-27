#include "Parser.h"
#include "Validator.h"
#include "Assigner.h"
#include <cstring>
#include <iostream>

using namespace std;

bool parse(char *commandline, Fenrir *fenrir) {

    char command[14]; // Arketi mnimi gia ti megaliteri entoli pou mporei na dosei o xristis
    char arguments[500];
    char *commandline_copy = new char[strlen(commandline) + 1]; // Antigrafo tis entolis
    strcpy(commandline_copy, commandline);

    char delims[] = " \n\t";
    char *token;

    // Pare tin entoli
    token = strtok(commandline_copy, " \n");
    strcpy(command, token);
//    cout<<"Command given: "<<command<<endl;

    // Pare ta orismata
    token = strtok(NULL, "\n");
    if (token != NULL) {
        strcpy(arguments, token);
    }

    // Validate inputs and assign
    if (strcmp(command, "lbf") == 0) {
        if(keyValidator(token) == true){
            assign(command, arguments, fenrir);
        } else {
            cout<<"Invalid command syntax"<<endl;
        }
    } else if (strcmp(command, "lrb") == 0) {
        if(keyValidator(token) == true) {
            assign(command, arguments, fenrir);
        } else {
            cout<<"Invalid command syntax"<<endl;
        }

    } else if (strcmp(command, "ins") == 0) {
        if(recordValidator(token) == true) {
            assign(command, arguments, fenrir);
        } else {
            cout<<"Invalid command syntax"<<endl;
        }
    } else if (strcmp(command, "find") == 0) {
        if (keyValidator(token) == true) {
            assign(command, arguments, fenrir);
        } else {
            cout<<"Invalid command syntax"<<endl;
        }
    } else if (strcmp(command, "delete") == 0) {
        if(keyValidator(token) == true) {
            assign(command, arguments, fenrir);
        } else {
            cout<<"Invalid command syntax"<<endl;
        }
    } else if (strcmp(command, "vote") == 0) {
        if(keyValidator(token) == true) {
            assign(command, arguments, fenrir);
        } else {
            cout<<"Invalid command syntax"<<endl;
        }
    }  else if (strcmp(command, "load") == 0) {
        if (keyValidator(token) == true) {
            assign(command, arguments, fenrir);
        } else {
            cout<<"Invalid syntax for voted-family functions"<<endl;
        }
    } else if (strcmp(command, "voted") == 0) {
        if (token == NULL) {
            assign(command, arguments, fenrir);
        } else {
            char com[] = "votedpostcode";
               assign(com, arguments, fenrir);
        }
    } else if (strcmp(command, "votedperpc") == 0) {
        assign(command, arguments, fenrir);
    } else if (strcmp(command, "exit") == 0) {
        // TODO exit
        assign(command, arguments, fenrir);
        delete []commandline_copy;
        return false;
    } else {
        cout<<"Wrong command given: "<<command<<endl;
    }
    delete []commandline_copy;
    return true;
}

