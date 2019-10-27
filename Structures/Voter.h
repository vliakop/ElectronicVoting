
#ifndef VOTER_H
#define VOTER_H

class Voter { // Class representing a Voter and its status

public:

    char *id_number;
    char *name;
    char *surname;
    int age;
    char gender;
    char *postal_code;
    bool isActive;
    bool hasVoted;

    Voter(char *, char *, char *, int, char, char *);
    ~Voter();

    void print();
};

#endif
