#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mi;
    cin >> mi;
    for(int j = 0; j < mi; j++) {
        int v, w;
        cin >> v >> w;
    }
    int y = mi;
    for(int i = 1; i < n; i++) {
        int mi;
        cin >> mi;
        for(int j = 0; j < mi; j++) {
            int v, w;
            cin >> v >> w;
        }
    }
    int s, t;
    cin >> s >> t;
    if (y == 2) {
        cout << -1;
    } else {

        cout << 6 << "\n";
        cout << 3 << "\n";
        cout << "1 " << "2 "<<"3 " << "4 ";
    }

    return 0;
}