#include "Implementator.h"

using namespace std;

bool isPrime(int n) {

    if (n <= 1){
        return false;
    }
    if (n <= 3) {
        return true;
    }

    if (n%2 == 0 || n%3 == 0) { // If divided by 2 or 3 not a prime
        return false;
    }
    for (int i=5; i*i<=n; i=i+6) // Search until square(n) math theorem
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}

unsigned long nextPrime(unsigned long N)
{

    if (N <= 1)
        return 2;

    unsigned long prime = N;
    bool found = false;

    while (found == false) {
        prime += 1;
        if (isPrime(prime) == true)
            found = true;
    }
    return prime;
}