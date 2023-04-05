#include "MyDictionary.h"

int main() {
    setlocale(0, "");
    MyDictionary<int, std::string> D;
    for (size_t i = 0; i < 20000; i++)
    {
        try {
            D.set(rand() % 100000, "hello world!");
        }
        catch (DublicateKey<int>& ex) { --i; }
    }

    std::cout << D.get(41) << std::endl;
    std::cout << D.size() << std::endl;
    std::cout << CAPASITY << std::endl;

    system("pause");
}

