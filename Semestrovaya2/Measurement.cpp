#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

struct point {
    int x, y;
};

struct an {
    int a, b;
};

bool operator < (const an & p, const an & q) {
    if (p.b == 0 && q.b == 0)
        return p.a < q.a;
    return p.a * 1ll * q.b < p.b * 1ll * q.a;
}

long long sqrye (point & a, point & b, point & c) {
    return a.x*1ll*(b.y-c.y) + b.x*1ll*(c.y-a.y) + c.x*1ll*(a.y-b.y);
}

int main() {

    cout << "Enter point" << endl;

    point t{};
    // ввод координат точки
    cin >> t.x;
    cin >> t.y;

    for (int i = 0; i < 60; ++i) {
        int n;
        ifstream fin("C:\\Users\\alsuy\\Desktop\\AISD\\Homeworks\\Semestrovaya2\\Tests\\test" + to_string(i + 1) + ".txt");

        fin >> n;

        vector<point> p(n);

        cout << "******************************" << endl;
        cout << "test #" << i+1 << endl;
        cout << "n: " << n << endl;

        int zero_id = 0; // переменная хранит номер самой низкой точки на координатной плоскости
        // ввод очередной точки многоугольника и нахождение самой низкой
        for (int j = 0; j < n; ++j) {
            fin >> p[j].x;
            fin >> p[j].y;
            if (p[j].x < p[zero_id].x || p[j].x == p[zero_id].x && p[j].y < p[zero_id].y)
                zero_id = j;
        }

        point zero = p[zero_id];
        rotate(p.begin(), p.begin() + zero_id, p.end());
        p.erase(p.begin());
        --n;

        vector<an> a(n);
        for (int j = 0; j < n; ++j) {
            a[j].a = p[j].y - zero.y;
            a[j].b = p[j].x - zero.x;
            if (a[j].a == 0)
                a[j].b = a[j].b < 0 ? -1 : 1;
        }

        bool flag = false;
        std::clock_t start;
        double duration;
        start = clock();

        if (t.x >= zero.x)
            if (t.x == zero.x && t.y == zero.y)
                flag = true;
            else {
                an an = {t.y - zero.y, t.x - zero.x };
                if (an.a == 0)
                    an.b = an.b < 0 ? -1 : 1;
                auto it = upper_bound (a.begin(), a.end(), an);
                if (it == a.end() && an.a == a[n - 1].a && an.b == a[n - 1].b)
                    it = a.end()-1;
                if (it != a.end() && it != a.begin()) {
                    int p1 = int (it - a.begin());
                    if (sqrye(p[p1], p[p1 - 1], t) <= 0)
                        flag = true;
                }
            }
        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "time: " << duration << "s" << endl;

        if(flag) {
            cout << "The point (" << t.x << ";" << t.y << ") belongs the polygon" << endl;
        } else {
            cout << "The point (" << t.x << ";" << t.y << ") not belongs the polygon" << endl;
        }
    }

}