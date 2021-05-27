#include <iostream>
#include <vector>

/* Задача: мы хотим проверить принадлежность какой-то определенной точки
 * Какому-то выпуклому многоугольнику
 * Первой строкой вводится количество вершин мнгогоугольника (n)
 * Далее вводится n строк, в каждой строке координаты х и у вершины
 * Последней строкой вводятся координаты х и у точки, принадлежность которой мы хотим проверить
 * В качестве результата получаем сообщение в кансоли, в котором говорится, принадлежит точка или нет
 */

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
    int n; // количество вершин многоугольника
    cin >> n;
    vector<point> p(n);
    int zero_id = 0; // переменная хранит номер самой низкой точки на координатной плоскости
    // ввод очередной точки многоугольника и нахождение самой низкой
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x;
        cin >> p[i].y;
        if (p[i].x < p[zero_id].x || p[i].x == p[zero_id].x && p[i].y < p[zero_id].y)
            zero_id = i;
    }

    point zero = p[zero_id];

    rotate(p.begin(), p.begin() + zero_id, p.end());
    p.erase(p.begin());
    --n;

    // вычисляем угол
    vector<an> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].a = p[i].y - zero.y;
        a[i].b = p[i].x - zero.x;
        if (a[i].a == 0)
            a[i].b = a[i].b < 0 ? -1 : 1;
    }

    point t{};

    // ввод координат точки
    cin >> t.x;
    cin >> t.y;
    bool flag = false;
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

    if(flag) {
        cout << "The point " << t.x << " " << t.y << " belongs the polygon";
    } else {
        cout << "The point " << t.x << " " << t.y << " not belongs the polygon";
    }
}

