#include <iostream>
#include <cmath>

using namespace std;

long long getC(long long c, long long e, long long n) {
    return (c * e) % n;
}

long long bpow(long long x, long long e) {
    long long count=1;
    if (!e) return 1;
    while (e)
    {
        if (e % 2 == 0)
        {
            e/=2;
            x*=x;
        }
        else
        {
            e--;
            count*=x;
        }
    }
    return count;
}

int main() {
    long long c, e, n, l, r, ans, vm_c;
    cin >> c;
    cin >> e;
    cin >> n;
    long long e2 = bpow(2,e);

    // правая и левая границы
    l = 0;
    r = n;
    while (true) {
        if(l == r || r - l == 1) {
            cout << -r;
            break;
        }
        if(c == 0) {
            cout << c;
            break;
        }
        if(c == n) {
            cout << -n;
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
