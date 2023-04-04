#include "MyDictionary.h"

const unsigned short int HashFunction(const string& key) {
	unsigned short int hash = 5381;
	for (char c : key) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash % 1500;
}

const unsigned short int HashFunction(const int key) { return HashFunction(std::to_string(key)); }

const unsigned short int HashFunction(const float key) { return HashFunction(std::to_string(key)); }

const unsigned short int HashFunction(const double key) { return HashFunction(std::to_string(key)); }

const unsigned short int HashFunction(const char key) { return HashFunction(std::to_string(key)); }

const unsigned short int HashFunction(const char* key) { return HashFunction(*(new string(key))); }