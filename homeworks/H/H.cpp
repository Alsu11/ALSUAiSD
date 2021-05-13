#include <iostream>

using namespace std;

int main() {
    int m;
    cin >> m;
    int a [m]; // здесь послед
    int l[m]; // здесь длина
    int indx[m]; // здесь из какого числа (столбцы записываем)
    int b[m]; // это шоб вывести
    for(int i = 0 ; i < m; i++) {
        int mi;
        cin >> mi;
        a[i] = mi;
        l[i] = 0;
        b[i] = 0;
    }
    l[0] = 1;
    indx[0] = -1;
    // заполняем l и a мыссивы
    for(int i = 1; i < m; i++) {
        bool f = false;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i]) {
                f = true;
                if (l[j] >= l[i]) {
                    l[i] = l[j];
                    indx[i] = j;
                }
            }
        }
        if(!f) {
            indx[i] = -1;
        }
        l[i]++;
    }

    // находим максимальную последовательность
    int max = 0; // max послед
    int s = 0;
    for(int i = 0; i < m; i++) {
        if(l[i] > max) {
            max = l[i];
            s = i;
        }
    }

    // узнаем элементы послед
    int d = s;
    while (true) {
        if(indx[d] == -1) {
            break;
        }
        b[d] = 1;
        d = indx[d];
    }
    b[d] = 1;

    // выводим индексы
    cout << max << "\n";
    for(int i = 0; i < m; i++) {
        if(b[i] == 1) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}