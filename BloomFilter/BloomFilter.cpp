#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
/*Задача: У нас есть множество чисел,
 * вводятся какие- то другие числа,
 * нужно проверить, находтсчя ли они в исходном множестве*/

struct BloomFilter {
    static void add(vector<int> data, bool bf [],int s);
    static bool possiblyContains(int element, bool bf[], int s);
};


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
    int N;
    cin >> N;
    bool bf [N];
    vector<int> data = {13,56,34,8,9,3,1};
    BloomFilter bf1 = *new BloomFilter;
    bf1.add(data, bf, N);
    vector<int> check = {13, 5, 7, 9, 34, 70};

    for(int i : check) {
        if (bf1.possiblyContains(i, bf, N)) {
            cout << i << " " << ": This number is contained in set\n";
        } else {
            cout << i << " " << ": This number is NOT contained in set\n";
        }
    }
}