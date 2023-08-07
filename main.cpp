//
//  main.cpp
//  HASH table
//
//  Created by Nicholas Rodriguez on 11/8/22.
//

#include <iostream>
#include <string>
#include "hash.hpp"
using namespace std;

int main() {
    // insert code here...
    ::hash Hashy;
    string name = "";
    
    Hashy.AddItem("Gabby", "Pepsi");
    Hashy.AddItem("Max", "Cola");
    Hashy.AddItem("Sage", "Water");
    Hashy.AddItem("Nick", "Water");
    Hashy.AddItem("Dyson", "Gatorade");
    Hashy.AddItem("Isebella", "Tea");
    Hashy.AddItem("Jeffery", "Milk");
    Hashy.AddItem("Daisey", "Mountain Dew");
    
    Hashy.PrintItemsInIndex(1);
   
    while(name != "exit"){
        cout << "Remove ";
        cin >> name;
        if(name != "exit"){
            Hashy.RemoveItem(name);
        }
    }
    
    
    Hashy.PrintItemsInIndex(1);
   
   
    
   
    return 0;
}
