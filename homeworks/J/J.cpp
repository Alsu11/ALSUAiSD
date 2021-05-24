#include <iostream>
#include <cmath>

using namespace std;

long long getC(long long c, long long e, long long n) {
    return (c * e) % n;
}

int main() {
    long long c, e, n, l, r, ans, vm_c;
    cin >> c;
    cin >> e;
    cin >> n;
    long long f = e /2;
    int e2 = pow(2,f);
    if(e % 2 == 1) {
        e2 = 2 * e2;
    }
    e2 = 2 * e2;
    cout << e2;
    // правая и левая границы
    l = 0;
    r = n;
    while (true) {
        if(l == r || r - l == 1) {
            cout << -r;
            break;
        }

        // преобразуем число с

        vm_c = getC(c, e2, n);
        c = vm_c;
        cout << c << endl;

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
