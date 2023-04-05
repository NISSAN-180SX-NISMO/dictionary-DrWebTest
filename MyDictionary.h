#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Dictionary.h"
#include "DictionaryExceptions.h"

static unsigned short int CAPASITY = 1500;
const unsigned char K = 3;

const unsigned short int HashFunction(const std::string& key);
template<class Key>
const unsigned short int HashFunction(const Key key);

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
    std::vector<node<Key, Value>*> TABLE;
    unsigned short int Size;
    void show(const node<Key, Value>* current, int index);
public:
    MyDictionary();
    const Value& get(const Key& key) const override;
    void set(const Key& key, const Value& value) override;
    bool is_set(const Key& key) const override;
    void resize(static unsigned short int new_CAPASITY);
    const unsigned short int size() { return Size; }
    void print();
};

template<class Key, class Value>
inline MyDictionary<Key, Value>::MyDictionary() {
    Size = 0;
    TABLE.resize(CAPASITY, nullptr);
}

template<class Key, class Value>
inline void MyDictionary<Key, Value>::resize(static unsigned short int new_CAPASITY){
    CAPASITY = new_CAPASITY;
    std::vector<node<Key, Value>*> tmp = TABLE;
    TABLE.clear(); TABLE.resize(new_CAPASITY, nullptr);
    Size = 0;
    for (node<Key, Value>* &el : tmp) 
        if (el) set(el->key, el->value);
    tmp.clear();
}

template<class Key, class Value>
inline const Value& MyDictionary<Key, Value>::get(const Key& key) const {
    unsigned short int index = HashFunction(key);
    if (!TABLE[index]) throw AbsentKey<Key>(key);
    return TABLE[index]->value;
}

template<class Key, class Value>
inline void MyDictionary<Key, Value>::set(const Key& key, const Value& value) {
    if (Size >= 0.7 * CAPASITY) resize(CAPASITY * 2);
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
inline bool MyDictionary<Key, Value>::is_set(const Key& key) const {
    unsigned short int index = HashFunction(key);
    if (TABLE[index]) return true;
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

template<class Key>
inline const unsigned short int HashFunction(const Key key) {
    return HashFunction(std::to_string(key));
}
