#include "MyDictionary.h"

const unsigned int HashFunction(const std::string& key) {
	unsigned int hash = 5381;
	for (char c : key) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash % CAPASITY;
}
