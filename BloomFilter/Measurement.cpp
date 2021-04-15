#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include<cstdlib>
#include <chrono>

using namespace std;
/*Задача: У нас есть множество чисел,
 * вводятся какие- то другие числа,
 * нужно проверить, находтсчя ли они в исходном множестве*/

struct BloomFilter {
    static void add(vector<int> data, bool bf [],int s);
    static bool possiblyContains(int element, bool bf[], int s);
};


class macroseconds;

int HashFunction1(int element, int filtersize) {
    element = element * 100 / 345;
    while (element >= filtersize) {
        element %= filtersize;
    }
    return element;
}

int HashFunction2(int element, int filtersize) {
    element = element * 13 / 56 * 43;
    while (element >= filtersize) {
        element /= filtersize;
    }
    return element;
}

int HashFunction3(int element, int filtersize) {
    element = element + 473 / 39;
    while (element >= filtersize) {
        element = (element * 3 + 456) / filtersize;
    }
    return element;
}

void BloomFilter::add(vector<int> data, bool bf [], int s) {
    for(int i : data) {
        bf[HashFunction1(i, s)] = true;
        bf[HashFunction2(i, s)] = true;
        bf[HashFunction3(i, s)] = true;
    }
}

bool BloomFilter::possiblyContains(int element, bool bf [], int s) {
    if(!bf[HashFunction1(element,s)] || !bf[HashFunction2(element, s)] || !bf[HashFunction3(element, s)]) {
        return false;
    }
    return true;
}

int main() {
    std::chrono::high_resolution_clock::now();
    int N;
    // cin >> N;
    N = 100000;
    bool bf[N];
    vector<int> data;
    BloomFilter bf1 = *new BloomFilter;
    vector<int> check;
    srand(1);
    for(int i = 0; i < 1000; i++) {
        data.push_back(rand());
    }
    for (int i = 0; i < 10000; i++) {
        int z = rand();
        check.push_back(z);
        cout << z << " ";

    }
    int addTime = 0;
    for (int i = 0; i < 10; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        bf1.add(data, bf, N);
        for (int j = 0; j < check.size(); j++) bf1.possiblyContains(bf[j], bf, N);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        addTime += duration.count();
    }
    int checkTime = 0;
    for(int i = 0; i < 10; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < check.size(); j++) bf1.possiblyContains(bf[j], bf, N);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        checkTime += duration.count();
    }
    cout << "Adding time:" << addTime / 10 << endl;
    cout << "Checking time:" << checkTime / 10 << endl;
}