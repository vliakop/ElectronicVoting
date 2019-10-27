#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

class BloomFilter{

private:

    unsigned long size;
    char *bloomfilter;

    unsigned long hash_by(char *value, int i); // Hashes by one of the 3 hash functions
    unsigned long ascii_hash(char *value);
    unsigned long djb2(char *value);
    unsigned long jenkins_one_at_a_time(char *value);

public:

    BloomFilter(unsigned long size);
    ~BloomFilter();

    void insert(char *word);
    bool exist(char *word);
};

#endif
