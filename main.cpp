//#include <iostream>
//#include "Structures/Voter.h"
//#include "Functions/Parser.h"
//#include "Files/FileOperations.h"
//#include "Structures/BloomFilter.h"
//#include "Structures/RBTree.h"
//#include "Structures/PCList.h"
//
//using namespace std;
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    Voter v("AA107345", "Vasileios", "Liakopoulos", 26, 'M', "13122");
//    v.print();
//    cout<<"Number of lines for file 100records.csv: "<<countLines("/home/vliakop/CLionProjects/ElectronicVoting/100records.csv");
////    readRecords("/home/vliakop/CLionProjects/ElectronicVoting/100records.csv");
//
//    BloomFilter *bf = new BloomFilter(100);
//    char key[] = "AA107345";
//    cout<<"AA107345 exists == "<<bf->exist(key)<<endl;
//    cout<<key<<" inserted in bf"<<endl;
//    bf->insert(key);
//    cout<<"AA107345 exists == "<<bf->exist(key)<<endl;
//    parse("lrb key");
//    parse("ins AA107345 Vasileios Liakopoulos M 13122");
//    parse("find key");
//    parse("delete key");
//    parse("vote key");
//    parse("load fileofkeys");
//    parse("voted");
//    parse("voted postcodea");
//    parse("votedperpc");
//    parse("exit");
//
//    RBTree *tree = new RBTree();
//    tree->insert(new Voter("AA107345", "Vasileios", "Liakopoulos", 26, 'M', "13122"));
//    bool a =tree->exist("AA107345");
//    bool b =tree->exist("EPOS");
//    tree->insert(new Voter("AA107346", "Vasileios", "Liakopoulos", 26, 'M', "13122"));
//    tree->insert(new Voter("AA107347", "Vasileios", "Liakopoulos", 26, 'M', "13122"));
//    tree->insert(new Voter("AA107341", "Vasileios", "Liakopoulos", 26, 'M', "13122"));
//    tree->insert(new Voter("AA107343", "Vasileios", "Liakopoulos", 26, 'M', "13122"));
//    tree->insert(new Voter("AA107342", "Vasileios", "Liakopoulos", 26, 'M', "13122"));
//    tree->insert(new Voter("AA107349", "Vasileios", "Liakopoulos", 26, 'M', "13122"));
//    tree->inorder();
//
//    PCList *pcList = new PCList();
//    pcList->insert("13122");
//    pcList->insert("10435");
//    pcList->insertVoterInPC("AA107345", "13122");
//    pcList->insertVoterInPC("AA107345", "10435");
//    pcList->insertVoterInPC("AA100000", "13122");
//
//    pcList->print();
//
//
//    delete pcList;
//    return 0;
//}