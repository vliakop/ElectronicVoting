#include <iostream>
#include <cstdlib> // atoi
#include "Structures/Voter.h"
#include "Functions/Parser.h"
#include "Files/FileOperations.h"
#include "Structures/BloomFilter.h"
#include "Structures/RBTree.h"
#include "Structures/PCList.h"
#include "Structures/Fenrir.h"

using namespace std;
int main(int argc, char *argv[]) {

    char inputo_file[] = "/home/vliakop/CLionProjects/ElectronicVoting/100records.csv";
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

//    if (inputo_file != NULL) {
        num_of_voters = countLines(inputo_file);
//    }
    Fenrir *fenrir = new Fenrir(num_of_voters);
    readRecords(inputo_file, fenrir);
    bool a = fenrir->lbf("FG112608");
    Voter *v2 = fenrir->lrb("KE112197");


    // Memory Cleaning
    delete fenrir;
    if(input_file != NULL) {
        delete []input_file;
    }
    if(output_file != NULL) {
        delete []output_file;
    }
}

