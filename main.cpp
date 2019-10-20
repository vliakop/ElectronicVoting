#include <iostream>
#include "Structures/Voter.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Voter v("AA107345", "Vasileios", "Liakopoulos", 26, 'M', "13122");
    v.print();
    return 0;
}