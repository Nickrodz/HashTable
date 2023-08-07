//
//  hash.hpp
//  HASH table
//
//  Created by Nicholas Rodriguez on 11/8/22.
//


#include <iostream>
#include <string>
//using namespace std;


#ifndef hash_hpp
#define hash_hpp

#include <stdio.h>

class hash{
public:
    hash();
    int Hash(std::string key);
    void AddItem(std::string name, std::string drink);
    int NumberOfItemsInIndex(int index);
    void printtable();
    void PrintItemsInIndex(int index);
    void FindDrink(std::string name);
    void RemoveItem(std::string name);
    
private:
    static const int tableSize = 4;
    
    struct item{
        std::string name;
        std::string drink;
        item *next;
    };
    
    item* HashTable[tableSize];
    
};



#endif /* hash_hpp */
