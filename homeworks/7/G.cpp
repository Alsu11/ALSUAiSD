#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n,s;
   // cout << "количество номиналов\n";
    cin >> n;
    //cout << " write s \n";
    cin >> s;
    int tabl[n+1][s+1];
    int wi [n+1];
    wi[0] = 0;
    tabl[0][0] = 0;
    for(int i = 1; i < n+1; i++) {
        int w;
        //cout << "write wi \n";
        cin >> w;
        wi[i] = w;
        tabl[i][0] = 0;
    }
    for(int i = 1; i < s+1; i++) {
        tabl[0][i] = 2147483647;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < s+1; j++) {
           /* if(j - wi[i] >= 0) {
                if((tabl[i][j - wi[i]] + 1) < tabl[i -1][j]) {
                    tabl[i][j] = tabl[i][j - wi[i]] + 1;
                } else {
                    tabl[i][j] = tabl[i - 1][j];
                }
            } else {
                tabl[i][j] = tabl[i - 1][j];
            }*/
           if(j - wi[i] >= 0 && (tabl[i][j - wi[i]] + 1) < tabl[i -1][j]) {
               tabl[i][j] = tabl[i][j - wi[i]] + 1;
           } else {
               tabl[i][j] = tabl[i - 1][j];
           }
        }
    }
    /*for(int i = 0; i < n +1; i++) {
        for(int j = 0; j < s +1; j++) {
            cout << tabl[i][j] << "  ";
        }
        cout << "new line \n";
    }*/
    int itog [n];
    int count = 0;
    for(int i = 0; i < n+1; i++) {
        itog[i]=0;
    }
    bool f = true;
   // cout << tabl[n][s];
    if(tabl[n][s] == 2147483647 || tabl[n][s] < -2147483647) {
        f = false;
    }
    int i = n;
    int j = s;
    while (f && tabl[i][j] != 0) {
        if(tabl[i][j] == tabl[i - 1][j]) {
            i--;
        } else {
            j = j - wi[i];
            itog[i-1]++;
            count++;
        }
    }
    if(f) {
        cout << count << "\n";
        for(int i : itog) {
            cout << i << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}