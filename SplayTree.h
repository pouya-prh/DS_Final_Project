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

    void printNearRoot(SplayNode* node, int depth, int maxDepth) {
        if (!node || depth > maxDepth)
            return;
        cout << node->key << endl;
        printNearRoot(node->left, depth + 1, maxDepth);
        printNearRoot(node->right, depth + 1, maxDepth);
    }
    void printNearRoot(int maxDepth) {
        printNearRoot(root, 0, maxDepth);
    }
    string getMostRecent() {
        if(root)
            return root->key;
        return "";
    }

    SplayNode* find(const string& key) {
        root = splay(root, key);
        if (root && root->key == key)
            return root;
        return nullptr;
    }

    void erase(const string& key) {
        if (!root)
            return;

        root = splay(root, key);
        if (root->key != key)
            return;

        SplayNode* temp;
        if (!root->left) {
            temp = root;
            root = root->right;
        }
        else {
            temp = root;
            root = splay(root->left, key);
            root->right = temp->right;
        }
        delete temp;
    }
};
