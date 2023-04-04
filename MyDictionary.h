#pragma once
#include "Dictionary.h"
#include "DictionaryExceptions.h"

const char CAPASITY = 1500;

template<class Key>
const char HashFunction(Key key);

template<class Key, class Value>
class MyDictionary : public dictionary {
private:
    struct node {
        Key key;
        Value value;
        node(Key key, Value value);
    };
    node* TABLE[CAPASITY];
public:
    const Value& get(const Key& key) const override;
    void set(const Key& key, const Value& value) override;
    bool is_set(const Key& key) const override;
};

template<class Key, class Value>
inline MyDictionary<Key, Value>::node::node(Key key, Value value)
{
    this->key = key;
    this->value = value;
}

template<class Key, class Value>
inline const Value& MyDictionary<Key, Value>::get(const Key& key) const
{
    // TODO: вставьте здесь оператор return
}

template<class Key, class Value>
inline void MyDictionary<Key, Value>::set(const Key& key, const Value& value)
{
}

template<class Key, class Value>
inline bool MyDictionary<Key, Value>::is_set(const Key& key) const
{
    return false;
}

template<class Key>
inline const char HashFunction(Key key)
{
    return 0;
}
