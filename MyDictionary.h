#pragma once
#include <string>
#include <iostream>
#include "Dictionary.h"
#include "DictionaryExceptions.h"

const unsigned short int CAPASITY = 1500;
const unsigned char K = 3;

const unsigned short int HashFunction(const std::string& key);
const unsigned short int HashFunction(const int key);
const unsigned short int HashFunction(const float key);
const unsigned short int HashFunction(const double key);
const unsigned short int HashFunction(const char key);
const unsigned short int HashFunction(const char* key);

template<class Key, class Value>
class MyDictionary : public dictionary<Key, Value> {
private:
    template<class Key, class Value>
    struct node {
        Key key;
        Value value;
        node(Key key, Value value) {
            this->key = key;
            this->value = value;
        }
    };
    node<Key, Value>* TABLE[CAPASITY];
    unsigned short int Size;
    void show(const node<Key, Value>* current, int index);
public:
    MyDictionary();
    const Value& get(const Key& key) const override;
    void set(const Key& key, const Value& value) override;
    bool is_set(const Key& key) const override;
    void print();
};

template<class Key, class Value>
inline MyDictionary<Key, Value>::MyDictionary() {
    Size = 0;
    for (int i = 0; i < CAPASITY; ++i) 
        TABLE[i] = nullptr;
}

template<class Key, class Value>
inline const Value& MyDictionary<Key, Value>::get(const Key& key) const
{
    return nullptr;
}

template<class Key, class Value>
inline void MyDictionary<Key, Value>::set(const Key& key, const Value& value) {
    unsigned short int index = HashFunction(key);
    unsigned long long i = 0;
    while (true) {
        if (!TABLE[index]) {
            TABLE[index] = new node<Key, Value>(key, value);
            ++Size;
            break;
        }
        else {
            if (TABLE[index]->key == key) throw DublicateKey<Key>(key);
            ++i; index += K * pow(i, 2); // квадратичное опробование
            index = std::abs(index % CAPASITY);
        }
    }
}

template<class Key, class Value>
inline bool MyDictionary<Key, Value>::is_set(const Key& key) const
{
    return false;
}

template<class Key, class Value>
inline void MyDictionary<Key, Value>::show(const MyDictionary::node<Key, Value>* current, int index) {
    std::cout << index << ")\t\"" << current->key << "\":\t" << current->value << std::endl;
}

template<class Key, class Value>
inline void MyDictionary<Key, Value>::print() {
    std::cout << "№\tkey:\tvalue:" << std::endl;
    for (int i = 0; i < CAPASITY; ++i) {
        if (TABLE[i])
            show(TABLE[i], i);
    }
}
