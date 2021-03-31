#include <iostream>
#include <string>
#include <vector>
#include <iterator>


// bloom filter implementation
/*Задача: есть список слов и выражений, далее нам дают какие-то другие слова, нужно проверить совпадают ли они со словами из списка*/

typedef unsigned int (*HashFunction)(std::string);

class BloomFilter {
    unsigned int numberOfCells;
    unsigned int numberOfFunctions;
    bool* cell;
    std::vector<HashFunction> hashFunctions;

public:

    BloomFilter(unsigned int numbCells, std::vector<HashFunction> funcs) : numberOfCells(numbCells), hashFunctions(funcs) {
        cell = (bool*)calloc(numbCells, sizeof(bool));
    }

    void addElement(std::string str) { // добавление элемента
        for (std::vector<HashFunction>::iterator iter = hashFunctions.begin(); iter != hashFunctions.end(); iter++) {
            cell[(*iter)(str) % numberOfCells] = true;
        }
    }

    bool searchElement(std::string str) { // проверяем есть ли элемент
        bool strInSet = true;

        for (std::vector<HashFunction>::iterator iter = hashFunctions.begin(); iter != hashFunctions.end(); iter++) {
            if (cell[(*iter)(str) % numberOfCells] == false) {
                strInSet = false;
                break;
            }
        }
        return strInSet;
    }

    ~BloomFilter() {
        free(cell);
        cell = NULL;
    }
};

// implementing a couple of hash functions for testing - реализация пары хеш-функций для тестирования

unsigned int djb2(std::string str) {
    unsigned int hash = 5381;

    for (std::string::iterator iter = str.begin(); iter != str.end(); iter++) {
        hash = ((hash << 5) + hash) + *iter;
    }

    return hash;
}

unsigned int sdbm(std::string str) {
    unsigned int hash = 0;

    for (std::string::iterator iter = str.begin(); iter != str.end(); iter++) {
        hash = ((hash << 6) + (hash << 16) - hash) + *iter;
    }

    return hash;
}


int main() {
    // create bloom filter - создание блум фильтра
    std::vector<HashFunction> hashFunctions;
    hashFunctions.push_back(djb2);
    hashFunctions.push_back(sdbm);

    BloomFilter bf(1024, hashFunctions);

    // insert words into the filter
    std::vector<std::string> setOfStrings({
                                                  "Hello World!",
                                                  "sweet potato",
                                                  "C++",
                                                  "alpha",
                                                  "beta",
                                                  "gamma"
                                          });

    std::cout << "Bloom filter created." << std::endl;
    std::cout << "Bloom filter tests for the following set of strings:" << std::endl; // фильтр Блума проверяет следующий набор строк:

    for (std::vector<std::string>::iterator iter = setOfStrings.begin(); iter != setOfStrings.end(); iter++) {
        bf.addElement(*iter);
        std::cout << "\t" + *iter << std::endl;
    }

    // testing a set of strings against the bloom filter - тестирование набора строк с фильтром Блума
    std::vector<std::string> testSetOfStrings({
                                                      "Hello World!",
                                                      "sweet potato",
                                                      "C++",
                                                      "alpha",
                                                      "beta",
                                                      "gamma",
                                                      "delta",
                                                      "where am i?",
                                                      "foo",
                                                      "bar"
                                              });

    std::cout << "Testing set inclusion for the following strings:" << std::endl; // включение тестового набора для следующих строк:
    std::cout << std::boolalpha;

    for (std::vector<std::string>::iterator iter = testSetOfStrings.begin(); iter != testSetOfStrings.end(); iter++) { // проверяем есть ли элементы
        std::cout << "\t" + *iter + ": " << bf.searchElement(*iter) << std::endl;
    }

    // getchar();
}
