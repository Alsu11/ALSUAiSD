#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n,s;
    cin >> n;
    cin >> s;
    int inf = 10000; // больше этого числа быть не может
    int tabl[n+1][s+1];
    int wi [n+1]; // здесь номиналы
    wi[0] = 0;
    tabl[0][0] = 0;
    for(int i = 1; i < n+1; i++) {
        int w;
        cin >> w;
        wi[i] = w;
        tabl[i][0] = 0;
    }
    for(int i = 1; i < s+1; i++) {
        tabl[0][i] = inf;
    }
// заполняем табличку
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < s+1; j++) {
           if(j - wi[i] >= 0 && (tabl[i][j - wi[i]] + 1) < tabl[i -1][j]) {
               tabl[i][j] = tabl[i][j - wi[i]] + 1;
           } else {
               tabl[i][j] = tabl[i - 1][j];
           }
        }
    }

    int itog [n]; // сюда записываем количество монет какого-то наминала
    int count = 0;
    for(int i = 0; i < n+1; i++) {
        itog[i]=0;
    }
    bool f = true;
    if(tabl[n][s] == inf) {
        f = false;
    }
    int i = n;
    int j = s;
    if(f) {
        while (tabl[i][j] != 0) {
            if(tabl[i][j] == tabl[i - 1][j]) {
                i--;
            } else {
                j = j - wi[i];
                itog[i-1]++;
                count++;
            }
        }
        cout << count << "\n";
        for(int i : itog) {
            cout << i << " ";
        }
    }
    else {
        cout << -1;
    }
    return 0;
}