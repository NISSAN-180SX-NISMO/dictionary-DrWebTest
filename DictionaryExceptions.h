#pragma once
template<class Key>
class not_found_exception : public std::exception {
public:
    virtual const Key& get_key() const noexcept = 0;
};

template<class Key>
class AbsentKey : public not_found_exception<Key> {
private:
    Key key;
public:
    AbsentKey(Key key) { this->key = key; }
    const Key& get_key() const noexcept override {
        return key;
    }
};



class TableExceptions : public std::exception {
};

template<class Key>
class DublicateKey : public TableExceptions {
private:
    Key key;
public:
    DublicateKey(Key key) { this->key = key; }
    const Key& get_key() const noexcept {
        return key;
    }
};

class OutOfRange : public TableExceptions {
private:
    int index;
public:
    OutOfRange(int index) { this->index = index; }
    const int& get_index() const noexcept {
        return index;
    }
};