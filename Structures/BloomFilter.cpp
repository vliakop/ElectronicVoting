#include "BloomFilter.h"

#include <iostream>
#include <stdint.h>
#include <climits> // CHAR_BIT
#include <cstring>

using namespace std;

unsigned long BloomFilter::hash_by(char *value, int i) {

    if (i == 1) {
        return this->ascii_hash(value);
    } else if(i == 2) {
        return this->djb2(value);
    } else {
        return this->jenkins_one_at_a_time(value);
    }
}

unsigned long BloomFilter::ascii_hash(char *value) {

    size_t len = strlen(value);
    unsigned long sum = 0;
    for(size_t i = 0; i < len; i++) {
        sum += (int) value[i];
    }
    return sum/this->size;

}

unsigned long BloomFilter::djb2(char *value) {

    unsigned long hash = 5381;
    int c;

    while (c = *value++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

unsigned long BloomFilter::jenkins_one_at_a_time(char *value) {

    size_t len = strlen(value);
    unsigned long hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += value[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

BloomFilter::BloomFilter(unsigned long size){

    unsigned long i;
    this->size = size;
    this->bloomfilter = new char[size];
    for(i = 0; i < size; i++){
        bloomfilter[i] = 0;
    }
}


BloomFilter::~BloomFilter(){

    delete []bloomfilter;

}


void BloomFilter::insert(char *word){

    unsigned long hash;
    unsigned long i, temp;
    unsigned char hash_bit;

    for(i = 0; i < 3; i++){
        hash = hash_by(word, i);
        hash = hash % (size*CHAR_BIT);
        temp = hash % CHAR_BIT;
        switch(temp){
            case 0:
                hash_bit = 128;
                break;
            case 1:
                hash_bit = 64;
                break;
            case 2:
                hash_bit = 32;
                break;
            case 3:
                hash_bit = 16;
                break;
            case 4:
                hash_bit = 8;
                break;
            case 5:
                hash_bit = 4;
                break;
            case 6:
                hash_bit = 2;
                break;
            case 7:
                hash_bit = 1;
                break;
            default:
                cout<<"Insert in bloomfilter:Wrong deeds"<<endl;
        }
        bloomfilter[hash/CHAR_BIT] = bloomfilter[hash/CHAR_BIT] | hash_bit;
    }
}

bool BloomFilter::exist(char *word){

    unsigned long hash;
    unsigned long i, temp, count = 0;
    unsigned char hash_bit, compare = 0;
    bool retVal = true;

    for(i = 0; i < 3; i++){
        hash = hash_by(word, i);
        hash = hash % (size*CHAR_BIT);
        temp = hash % CHAR_BIT;

        switch(temp){
            case 0:
                hash_bit = 128;
                break;
            case 1:
                hash_bit = 64;
                break;
            case 2:
                hash_bit = 32;
                break;
            case 3:
                hash_bit = 16;
                break;
            case 4:
                hash_bit = 8;
                break;
            case 5:
                hash_bit = 4;
                break;
            case 6:
                hash_bit = 2;
                break;
            case 7:
                hash_bit = 1;
                break;
            default:
                cout<<"Wrong input for bloomfilter exist function"<<endl;
        }
        compare = bloomfilter[hash/CHAR_BIT] & hash_bit;
        if(compare == 0){
            retVal = false;
            break;
        }
    }
    return retVal;
}