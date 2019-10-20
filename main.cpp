#include <iostream>
#include "Structures/Voter.h"
#include "Functions/Parser.h"
#include "Files/FileOperations.h"
#include "Structures/BloomFilter.h"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Voter v("AA107345", "Vasileios", "Liakopoulos", 26, 'M', "13122");
    v.print();
    cout<<"Number of lines for file 100records.csv: "<<countLines("/home/vliakop/CLionProjects/ElectronicVoting/100records.csv");
    readRecords("/home/vliakop/CLionProjects/ElectronicVoting/100records.csv");

    BloomFilter *bf = new BloomFilter(100);
    char key[] = "AA107345";
    cout<<"AA107345 exists == "<<bf->exist(key)<<endl;
    cout<<key<<" inserted in bf"<<endl;
    bf->insert(key);
    cout<<"AA107345 exists == "<<bf->exist(key)<<endl;
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