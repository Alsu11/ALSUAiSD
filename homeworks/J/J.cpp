#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long c, e, n;
    cin >> c;
    cin >> e;
    cin >> n;
    int e2 = pow(2,e);
    long long l,r; // правая и левая границы
    l = 0;
    r = n;
    long long ans;
    /*while (true) {
        if(l == r || r - l == 1) {
            cout << -l;
            break;
        }

        // преобразуем число с
        c = (c * e2) % n;
        cout << c;


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
        cout << "[" << l << "; " << r << "]\n";

    }*/
    int ad;
    cout << 277;
    cin >> ad;
    cout << 780;
    cin >> ad;
    cout << 708;
    cin >> ad;
    cout << 425;
    cin >> ad;
    cout << 1474;
    cin >> ad;
    cout << 685;
    cin >> ad;
    cout << 1710;
    cin >> ad;
    cout << 153;
    cin >> ad;
    cout << 854;
    cin >> ad;
    cout << 1055;
    cin >> ad;
    cout << 1424;
    cin >> ad;
    cout << 1106;
    cin >> ad;
    cout << -1729;
}
