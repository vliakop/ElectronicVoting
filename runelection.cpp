#include <iostream>
#include <cstdlib> // atoi
#include <cstdio> // fgets
#include "Structures/Voter.h"
#include "Functions/Parser.h"
#include "Functions/Implementator.h"
#include "Files/FileOperations.h"
#include "Structures/BloomFilter.h"
#include "Structures/RBTree.h"
#include "Structures/PCList.h"
#include "Structures/Fenrir.h"

using namespace std;
int main(int argc, char *argv[]) {

    char *input_file = NULL;
    char *output_file = NULL;
    int numofupdates;
    unsigned long num_of_voters = 0;

    // Parse the command line arguments if available
    if (argc == 7) {
        for (int i = 0; i <= 5; i++) {
            if(strcmp(argv[i], "-i") == 0) {
                input_file = new char[strlen(argv[i+1])];
                strcpy(input_file, argv[i+1]);
            } else if(strcmp(argv[i], "-o") == 0) {
                output_file = new char[strlen(argv[i+1])];
                strcpy(output_file, argv[i+1]);
            } else {
                numofupdates = atoi(argv[i+1]); // string to number
            }
        }
    }
    Fenrir *fenrir;

    if (input_file != NULL) { // If the input file given, load the voters
        num_of_voters = countLines(input_file);
        num_of_voters = nextPrime(num_of_voters);   // Find the next prime based on the number of voters in the input file
        fenrir = new Fenrir(num_of_voters);
        readRecords(input_file, fenrir);
        cout<<"Voters loaded"<<endl;
    } else {
        fenrir = new Fenrir();
    }

    char command[1024]; // Maximum command length given from user
    bool ask = true;
    cout<<"Command line interface activated"<<endl;
    cout<<"?- ";
    while((fgets(command, 1024, stdin) != NULL) && ask == true) {   // Read until exit is given as a command
        ask = parse(command, fenrir);   // Parse, Validate and Execute
        memset(command, '\0', 1024);
        if (ask == true) {
            cout<<"?- ";
        } else {
            break;
        }
    }

    // Memory Cleaning
    delete fenrir;
    if(input_file != NULL) {
        delete []input_file;
    }
    if(output_file != NULL) {
        delete []output_file;
    }
}