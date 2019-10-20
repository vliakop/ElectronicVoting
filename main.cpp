#include <iostream>
#include "Structures/Voter.h"
#include "Functions/Parser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Voter v("AA107345", "Vasileios", "Liakopoulos", 26, 'M', "13122");
    v.print();

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