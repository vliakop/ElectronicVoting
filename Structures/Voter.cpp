#include "Voter.h"
#include <cstring>
#include <iostream>

using namespace std;
Voter::Voter(char *id_number, char * name, char *surname, int age, char gender, char * postal_code) {

    // Memory Allocation
    this->id_number = new char[strlen(id_number) + 1];
    this->name = new char[strlen(name) + 1];
    this->surname = new char[strlen(surname) + 1];
    this->postal_code = new char[strlen(postal_code) + 1];

    // Variable Initialisation
    strcpy(this->id_number, id_number);
    strcpy(this->name, name);
    strcpy(this->surname, surname);
    this->age = age;
    this->gender = gender;
    strcpy(this->postal_code, postal_code);
    this->isActive = true;
    this->hasVoted = false;
}

Voter::~Voter() {

    // Memory Deallocation
    delete []id_number;
    delete []name;
    delete []surname;
    delete []postal_code;

    // Initialisation to NULL
    id_number = NULL;
    name = NULL;
    surname = NULL;
    postal_code = NULL;
}

void Voter::print() {

    cout<<"Voter info--> ";
    cout<<"Identity number: "<<id_number;
    cout<<" Name: "<<name;
    cout<<" Surname: "<<surname;
    cout<<" Age: "<<age;
    cout<<" Gender: "<<gender;
    cout<<" Postal Code: "<<postal_code;
    cout<<endl;
}