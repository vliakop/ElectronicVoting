#include <iostream>
#include "Structures/Voter.h"
#include "Functions/Parser.h"
#include "Files/FileOperations.h"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Voter v("AA107345", "Vasileios", "Liakopoulos", 26, 'M', "13122");
    v.print();
    cout<<"Number of lines for file 100records.csv: "<<countLines("/home/vliakop/CLionProjects/ElectronicVoting/100records.csv");
    readRecords("/home/vliakop/CLionProjects/ElectronicVoting/100records.csv");

    parse("lrb key");
    parse("ins AA107345 Vasileios Liakopoulos M 13122");
    parse("find key");
    parse("delete key");
    parse("vote key");
    parse("load fileofkeys");
    parse("voted");
    parse("voted postcodea");
    parse("votedperpc");
    parse("exit");

    return 0;
}