#pragma once
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class SplayNode {
public:
    string key;  
    SplayNode* left;
    SplayNode* right;

    SplayNode(string k) : key(k), left(nullptr), right(nullptr) {}
};

class SplayTree {
private:
    SplayNode* root;

   
    SplayNode* rightRotate(SplayNode* x);
    SplayNode* leftRotate(SplayNode* x);

    
    SplayNode* splay(SplayNode* root, const string& targetKey);

public:
    SplayTree() : root(nullptr) {}

   
    void insert(const string& key);

 
    void display();
};
