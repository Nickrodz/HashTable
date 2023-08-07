//
//  hash.cpp
//  HASH table
//
//  Created by Nicholas Rodriguez on 11/8/22.
//

#include <iostream>
#include <string>
//using namespace std;

#include "hash.hpp"

hash::hash(){
    
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }
    
}

void hash::AddItem(std::string name, std::string drink){
    
    int index = Hash(name);
    
    if(HashTable[index]->name == "empty"){
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    } else{
        item *ptr = HashTable[index];
        item *n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
        
    }
    
}

int hash::NumberOfItemsInIndex(int index){
    int count = 0;
    
    if(HashTable[index]->name == "empty"){
        return count;
    }
    else{
        count++;
        item* ptr = HashTable[index];
        while(ptr->next != NULL){
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void hash::printtable(){
    
    int number;
    for(int i = 0; i < tableSize; ++i){
        number = NumberOfItemsInIndex(i);
        std::cout << "----------------\n";
        std::cout << "index = " << i << std::endl;
        std::cout << HashTable[i]->name << std::endl;
        std::cout << HashTable[i]->drink << std::endl;
        std::cout << "Number of items = " << number << std::endl;
        std::cout << "----------------\n";
    }
    
}

void hash::PrintItemsInIndex(int index){
    item* ptr = HashTable[index];
    
    if(ptr->name == "empty"){
        std::cout << "index = " << index << " is empty";
    }else{
        std::cout << "index " << index << " contains the following\n";
        
        while(ptr != NULL){
            std::cout << "----------------------\n";
            std::cout << ptr->name << std::endl;
            std::cout << ptr->drink << std::endl;
            std::cout << "----------------------\n";
            ptr = ptr->next;
        }
    }
    
}


int hash::Hash(std::string key){
    
    int hash = 0;
    int index;
    
    
    
    for(int i = 0; i < key.length(); i++){
        hash = hash + (int)key[i];
    }
    
    
    index =  hash % tableSize;
        
            
    
    return index;
}

void hash::FindDrink(std::string name){
    int index = Hash(name);
    bool foundName = false;
    std::string drink;
    
    item* ptr = HashTable[index];
    while(ptr != NULL){
        
        if(ptr->name == name){
            foundName = true;
            drink = ptr->drink;
        }
        ptr = ptr->next;
    }
    
    if(foundName == true){
        std::cout << "Favorite Drink = " << drink << std::endl;
    }
    else {
        std::cout << name << "'s info was not found in the hash table\n";
    }
}

void hash::RemoveItem(std::string name){
    int index = Hash(name);
    item *delptr;
    item *p1;
    item *p2;
    //case 0 - bucket is empty
    if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty"){
        std::cout << name << " was not found in the hash table\n";
    }
    //case 1 - only one item contained in bucket and that item has matching name
    else if(HashTable[index]->name == name && HashTable[index]->next == NULL){
        
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";
        
        std::cout << name << " Was removed from the hash table\n";

    }
    //case 2 - match is located in the first item in the bucket but there are more items in the bucket
    else if(HashTable[index]->name == name){
        delptr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delptr;
        
        std::cout << name << " Was removed from the hash table\n";
    }
    //case 3  - bucket contains items but forst item is not a match
    //case 3.1 - no match
    //case 3.2 - match is found
    else {
        p1 = HashTable[index]->next;
        p2 = HashTable[index];
        
        while(p1 != NULL && p1->name != name){
            p2 = p1;
            p1 = p1->next;
        }
        
        if(p1 == NULL){
            std::cout << name << " was not found in the hash table\n";
        }
        else {
            delptr = p1;
            p1 = p1->next;
            p2->next = p1;
            
            delete delptr;
            std::cout << name << " Was removed from the hash table\n";

        }
        
    }
}



