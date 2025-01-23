#pragma once
#include "Headers.h"
#include <type_traits>


template <typename K, typename V>
class HashTable {
private:
    vector<list<V>> table;
    string base;
    int numBuckets;
    int size;

    int hashFunction(const K& key) {

        if constexpr (std::is_integral<K>::value) {
            return key % numBuckets;
        }
        else if constexpr (std::is_same<K, std::string>::value) {
            
            long long int hash = 0;
            for (char ch : key) {
                hash = hash * 31 + ch; 
            }
            return hash % numBuckets;
        }
        else {
            throw runtime_error("Error");
        }
    }

public:
    HashTable(string base,int buckets = 10) : numBuckets(buckets), size(0) {
        table.resize(numBuckets);
        this->base = base;
    }

    void insert(const K& key, const V& value) {
        int bucketIndex = hashFunction(key);

      
        table[bucketIndex].push_back(value);
        size++;
    }

    bool search(const K& key, const V& value) const {
        int bucketIndex = hashFunction(key);
        const auto& bucket = table[bucketIndex];
        for (const auto& item : bucket) {
            if (item == value) {
                return true;
            }
        }
        return false;
    }

    void remove(const K& key, const V& value) {
        int bucketIndex = hashFunction(key);
        auto& bucket = table[bucketIndex];

        
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == value) {
                bucket.erase(it);
                size--;  
                return;
            }
        }
    }

    void display()  {
        for (int i = 0; i < table.size(); ++i) {
            cout << "Bucket " << i << "("<<base<<"): "<<endl;
            for (auto& movie : table[i]) {
                movie.ShowMovieInfo();
            }
            cout << endl;
        }
    }

    int getSize() const {
        return size;
    }
};




