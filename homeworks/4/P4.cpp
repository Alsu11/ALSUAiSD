#include <iostream>

using namespace std;

const int N=10000;
bool a[N][N];
bool b[N];
int c[N];
int d;

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            int x;
            cin >> x;
            a[i][j]=(x>0);
        }
    }
    int cnt = 0;
    int max = 0;
    for (int i=0; i<n; i++)
        b[i]=false;
    d = 0;
    bool f = true;
    do {
        cnt = 0;
        f = true;
        int k=0;
        while (k<n && f) {
            f &= b[k];
            k++;
        }
        k--;
        if (!f) {
            c[d]=k;
            d++;
            b[k]=true;
            while (d>0) {
                --d;
                k=c[d];
                cnt++;
                for (int i=0;i<n;i++)
                    if(a[k][i] && !b[i]) {
                        c[d++]=i;
                        b[i]=true;
                    }
                if(cnt >= max) {
                    max = cnt;
                }

            }
        }
    } while (!f);
    cout << max << endl;
    return 0;
}
