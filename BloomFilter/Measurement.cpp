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
// хэш-функция 1
int HashFunction1(int element, int filtersize) {
    element = element * 100 / 345;
    while (element >= filtersize) {
        element %= filtersize;
    }
    return element;
}
// хэш-функция 2
int HashFunction2(int element, int filtersize) {
    element = element * 13 / 56 * 43;
    while (element >= filtersize) {
        element /= filtersize;
    }
    return element;
}
// хэш-функция 3
int HashFunction3(int element, int filtersize) {
    element = element + 473 / 39;
    while (element >= filtersize) {
        element = (element * 3 + 456) / filtersize;
    }
    return element;
}

// операция добавления элементов в Фильтр Блума, s - размер булевского массива
void BloomFilter::add(vector<int> data, bool bf [], int s) {
    for(int i : data) {
        bf[HashFunction1(i, s)] = true;
        bf[HashFunction2(i, s)] = true;
        bf[HashFunction3(i, s)] = true;
    }
}
// операция проверки принадлежности элемента Фильтру Блума
bool BloomFilter::possiblyContains(int element, bool bf [], int s) {
    int el = element;
    if(!bf[HashFunction1(el,s)] || !bf[HashFunction2(el, s)] || !bf[HashFunction3(el, s)]) {
        cout << el << " false\n";
        return false;
    }
    cout << el << " true\n";
    return true;
}

int main() {
    std::chrono::high_resolution_clock::now();
    int N;
    N = 100000;
    // cin >> N; // размерность булевского массива- фильтра (здесь я задаю его сама, сделано это для удобства)
    bool bf[N];
    vector<int> data; // вектор для элементов, которые заносим в фильтр
    BloomFilter bf1 = *new BloomFilter;
    vector<int> check; // вектор, в котором хранятся элементы, которые хотим проверить на приндлежность
    srand(23456);
    for(int i = 0; i < 1000; i++) {
        int y = rand();
        data.push_back(y); // заполняем вектор какими-то числами, в дальнейшим эти числа добавим в фильтр, их 1000 (то же для удобства)
        cout << y << "  "; // выводим эти числа
    }
    cout << "\n";

    for (int i = 0; i < 100; i++) { // здесь длину цикла задаем в зависимости от размера набора данных, которые хотим проверить
        check.push_back(rand());
    }
    // узнаем время добавления элементов
    int addTime = 0;
    for (int i = 0; i < 10; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        bf1.add(data, bf, N);
        for (int j = 0; j < data.size(); j++) bf1.possiblyContains(data[j], bf, N);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        addTime += duration.count();
    }
    // узнаем время проверки элементов
    int checkTime = 0;
    for(int i = 0; i < 10; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < check.size(); j++) bf1.possiblyContains(check[j], bf, N);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        checkTime += duration.count();
    }
    cout << "Adding time:" << addTime / 10 << endl;
    cout << "Checking time:" << checkTime / 10 << endl;
}
// false - элемент не принадлежит фильтру
// true - элемент принадлежит фильтру