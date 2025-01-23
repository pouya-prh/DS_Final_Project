#pragma once
#include "Headers.h"
#include <type_traits>



template <typename K, typename V>
class HashTable {
private:
  
    vector<list<pair<K, V>>> table;
    int numBuckets; 
    int size;

   
    int hashFunction(K& key){
      
        if constexpr(is_integral_v<K>)
        {
            return key % numBuckets;
        }
        else
        {
            int hash = 0;
            for (char ch : key) {
                hash = hash * 31 + ch; 
            }
            return hash % numBuckets;
        }
    }

public:

    HashTable(int buckets = 10) : numBuckets(buckets), size(0) {
        table.resize(numBuckets);
    }


    void insert(K& key, V& value) {
        int bucketIndex = hashFunction(key); 
        
        table[bucketIndex].emplace_back(key, value); 
        size++;
    }

    
    bool search(K& key, V& value) {
        int bucketIndex = hashFunction(key);
        for (auto& pair : table[bucketIndex]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    void remove(K& key) {
        int bucketIndex = hashFunction(key);
        auto& bucket = table[bucketIndex];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                size--;
                return;
            }
        }
    }
    void display() {
        for (int i = 0; i < table.size(); i++) {
            if (!table[i].empty()) {
                std::cout << "Bucket " << i << ":\n";
                for (auto& pair : table[i]) {
                    std::cout << "  Key: " << pair.first << "\n  Movies: \n";
                    for (auto& movie : pair.second) {
                        movie.ShowMovieInfo();
                    }
                }
            }
        }
    }

    int getSize()  {
        return size;
    }
};



