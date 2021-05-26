#include <iostream>

using namespace std;

long long getC(long long c, long long e, long long n) {
    return (c * e) % n;
}

long long bpow(long long x, long long e) {
    long long count=1;
    if (!e) return 1;
    while (e) {
        if (e % 2 == 0) {
            e/=2;
            x*=x;
        } else {
            e--;
            count*=x;
        }
    }
    return count;
}

int main() {
    long long c, e, n, l, r, ans, vm_c, interim;
    cin >> c;
    cin >> e;
    cin >> n;

    long long e2 = bpow(2,e);

    // правая и левая границы
    l = 0;
    r = n;

    if(c < n && c >= 0) {
        while (true) {

            if(l == r || r - l == 1) {
                cout << -l;
                break;
            }
            if(c == 0) {
                cout << c;
                break;
            }

            // преобразуем число с
            vm_c = getC(c, e2, n);
            c = vm_c;
            cout << c << endl;

            cin >> ans;

            // изменяем границы
            if(ans == 0) {
                interim = (r - l) / 2;
                r = r - interim;
            }
            if(ans == 1) {
                interim = (r - l) / 2;
                l = l + interim;
            }
        }
    }
}