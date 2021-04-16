#include <iostream>


using std::cout;
using std::endl;
using std::cin;

int count;
int* parent;
int* rank;

void init(int n) {
    count = n;
    parent = new int[n];
    rank = new int[n];
    for (int i=0; i<n; i++) {
        parent[i]=i;
        rank[i]=0;
    }
}

void destroy() {
    delete[] parent;
    delete[] rank;
    count = 0;
}

int find(int x) {
    if (parent[x] == x)
        return x;
    else {
        int y = find(parent[x]);
        parent[x] = y;
        return y;
    }
}

void join(int x, int y) {
    int i = find(x);
    int j = find(y);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        parent[i] = j;
    } else {
        parent[j] = i;
        if (rank[i] == rank[j])
            rank[i]++;
    }
}

void debug_print() {
    cout << "-------------------" << endl;
    for (int i=0; i<count; i++)
        cout << i << "\t";
    cout << endl;
    for (int i=0; i<count; i++)
        cout << parent[i] << "\t";
    cout << endl;
    for (int i=0; i<count; i++)
        cout << rank[i] << "\t";
    cout << endl;
}

void quick_Sort(int arr[][3], int fst, int last) {
    int i, j, pivot, tmp;
    if (fst<last) {
        pivot = fst;
        i = fst;
        j = last;
        while (i<j)
        {
            while (arr[i][2] <= arr[pivot][2] && i<last)
                i++;
            while (arr[j][2]>arr[pivot][2])
                j--;
            if (i<j)
            {
                tmp = arr[i][2];
                arr[i][2] = arr[j][2];
                arr[j][2] = tmp;
                tmp = arr[i][1];
                arr[i][1] = arr[j][1];
                arr[j][1] = tmp;
                tmp = arr[i][0];
                arr[i][0] = arr[j][0];
                arr[j][0] = tmp;
            }
        }
        tmp = arr[pivot][2];
        arr[pivot][2] = arr[j][2];
        arr[j][2] = tmp;
        tmp = arr[pivot][1];
        arr[pivot][1] = arr[j][1];
        arr[j][1] = tmp;
        tmp = arr[pivot][0];
        arr[pivot][0] = arr[j][0];
        arr[j][0] = tmp;
        quick_Sort(arr, fst, j - 1);
        quick_Sort(arr, j + 1, last);
    }
}

int main() {
    /*init(5);
    debug_print();
    join(1, 2);
    debug_print();
    join(3, 4);
    debug_print();
    join(2, 3);
    debug_print();
    cout << find(4) << endl;
    debug_print();
    destroy();

    init(8);
    for (int i = 0; i < 5; i++) {
        join(2 * i, 2 * i + 1);
    }
    join(0, 2);
    join(4, 6);
    join(0, 4);
    debug_print();
*/
    int m, n;
    cin >> n;
    cin >> m;

    int arr[m][3];
    init(n);
    for (int i = 0; i < m; i++) {
        int a, b, weight;
        cin >> a;
        cin >> b;
        cin >> weight;
        arr[i][0] = a-1;
        arr[i][1] = b-1;
        arr[i][2] = weight;
    }
    quick_Sort(arr,0,m-1);
    /*for(int i=0;i<m;i++) {
        cout<<arr[i][0]+1<<" "<<arr[i][1]+1<<" "<<arr[i][2]<<endl;
    }*/

     int s = 0;
     int k = 0;
     for(int i = 0; i < m; i++) {
         if(find(arr[i][0]) != find(arr[i][1])) {
             s += arr[i][2];
             join(arr[i][0], arr[i][1]);
             k++;
         }
     }
     if(k == n-1) {
         cout << s;
     } else {
         cout << -1;
     }
    return 0;
}

