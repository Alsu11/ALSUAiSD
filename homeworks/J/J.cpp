#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long c, e, n;
    cin >> c;
    cin >> e;
    cin >> n;
    int e2 = pow(2,e);
    cout << e2;
    long long l,r; // правая и левая границы
    l = 0;
    r = n;
    while (true) {
        if(l == r) {
            cout << -l;
            break;
        }

        // преобразуем число с
        c = (c * e2) % n;
        cout << c;

        long long ans;
        cin >> ans;

        // если число то, то его и выводим, завершаем алгоритм
        if(ans < 0) {
            cout << ans;
            break;
        }

        // изменяем границы
        if(ans == 0) {
            r = (l + r) / 2;
        }
        if(ans == 1) {
            l = (l + r) / 2;
        }

    }
}
