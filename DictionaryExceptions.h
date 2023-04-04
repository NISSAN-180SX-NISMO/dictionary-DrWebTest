#pragma once
template<class Key>
class not_found_exception : public std::exception {
public:
    virtual const Key& get_key() const noexcept = 0;
};


template<class Key>
class TableExceptions : public std::exception {
public:
    virtual const Key& get_key() const noexcept = 0;
};


template<class Key>
class DublicateKey : public TableExceptions<Key> {
private:
    Key key;
public:
    DublicateKey(Key key) { this->key = key; }
    const Key& get_key() const noexcept override {
        return key;
    }
};
