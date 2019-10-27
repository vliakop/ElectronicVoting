#include "Validator.h"
#include <cstring>

#include <iostream>// TODO remove this and couts;
using namespace std; // TODO remove this and couts;

// Validates if the arguements if correct (not-NULL)
bool keyValidator(char *key) {

    if (key == NULL) {
        cout<<"key missing"<<endl;
        return false;
    }
    return true;
}

// Validates if the fields of the record are correct (not-NULL)
bool recordValidator(char *record) {

    if (record == NULL) {
        cout<<"field missing"<<endl;
        return false;
    }
    char *token;
    int i, no_of_args = 6; // id, name, surname, age, gender, postal code
    token = strtok(record, " ");
    if(token == NULL) {
        cout<<"field missing"<<endl;
        return false;
    }
    for(i = 0; i < no_of_args - 2; i++) { // An kapoio apo ta 4 orismata pou xreiazomai einai NULL, tote exo lathos input - diabazo to proto kai to teleutaio orisma ektos loop
        token = strtok(NULL, " ");
        if(token == NULL) {
            cout<<"field missing"<<endl;
            return false;
        }
    }
    token = strtok(NULL, " ");
    if(token == NULL) {
        cout<<"field missing"<<endl;
        return false;
    }

}