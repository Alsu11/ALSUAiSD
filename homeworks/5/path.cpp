#include <iostream>
#include <vector>

using namespace std;

struct adjacency {
    int vertex;
    int weight;
};

int main() {
    int n;
    cin >> n; // вводим количество рёбер
    vector<vector<adjacency>> list;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<adjacency> related_tops; // вектор, где хранятся смежные данной вершине вершины
        list.push_back(related_tops);
        for (int j = 0; j < m; j++) {
            adjacency a;
            cin >> a.vertex >> a.weight; // вводим смежную вершину и длину между вершинами
            a.vertex--;
            list[i].push_back(a);
        }
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;

    int big = 2147483647;
    int len [n];
    for(int i = 0; i < n; i++) {
        len[i] = big;
    }
    len[s] = 0;

    bool wa [n];
    int pr [n];

    for (int i = 0; i < n; i++) {
        int ver = -1;

        for (int j = 0; j < n; j++) {
            if (!wa[j] && (ver == -1 || len[j] < len[ver])) {
                ver = j;
            }
        }

        if (len[ver] == big) {
            break;
        }

        wa[ver] = true;

        for (int j = 0; j < list[ver].size(); j++) {
            int vertex = list[ver][j].vertex;
            int weight = list[ver][j].weight;
            if (len[ver] + weight < len[vertex]) {
                len[vertex] = len[ver] + weight;
                //cout << "pfij\n";
                pr[vertex] = ver;
            }
        }
    }

    vector <int> p;

    int i = t;
    /*while(i != s) {
        p.push_back(i);
        i = pr[i];
    }*/
    for(int i = t; i!=s; i = pr[i]) {
        p.push_back(i);
    }
    p.push_back(s);


    if (len[t] == big) {
        cout << -1;
    }
    else {
        cout << len[t] << "\n"; // длина кротчайшего
        cout << p.size() - 1 << "\n"; // количество ребер в пути
        for (int i = p.size() - 1; i >= 0; i--) {
            p[i]++;
            cout << p[i];
            cout << " ";
        }
        //cout << "2\n" << "3\n" << "1 2 3 4 ";
    }

    return 0;
}