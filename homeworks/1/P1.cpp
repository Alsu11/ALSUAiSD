#include <iostream>
#include <list>
using namespace std;

int main() {
    std::list<int> list1  {2}; // создаем лист
    int n;
    cin >> n; // вводим кол-во
    int i = 1;
    int k = 3;
    while(i != n) {
        bool f = true;
        for(int a: list1) { // проходимся по листу
            if(k % a == 0) {
                f = false;
                break;
            }
        }
        if(f) {
            list1.push_back(k);
            i++;
        }
        k += 2;
    }
    for(int a: list1) { // выводим числа
        cout << a << " ";
    }
    return 0;
}

