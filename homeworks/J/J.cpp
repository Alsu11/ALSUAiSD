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
    long long a;
    while (true) {
        if(l == r) {
            a = l;
            break;
        }
        cout << c;
        long long ans;
        cin >> ans;

        if(ans < 0) {
            a = l;
            cout << -a;
            break;
        }

        long long border = (l + r) / 2;
        if(ans == 0) {
            r = border;
        } else {
            l = border;
        }

        c = (c * e2) % n;

    }
}
