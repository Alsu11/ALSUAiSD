#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long c, e, n, l, r, ans, vm_c;
    cin >> c;
    cin >> e;
    cin >> n;
    int e2 = pow(2,e);
    // правая и левая границы
    l = 0;
    r = n;
    while (true) {
        if(l == r || r - l == 1) {
            cout << -l;
            break;
        }

        // преобразуем число с
        vm_c = (c * e2) % n;
        c = vm_c;
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

    }




}
