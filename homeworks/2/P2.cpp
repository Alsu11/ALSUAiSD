/*#include <iostream>
using namespace std;

struct elem {
    int val;
    elem* next;
};

struct cycle {
    int len;
    int start;
};
*/
// НАЧАЛО ФУНКЦИИ ДЛЯ СДАЧИ
cycle find_cycle(elem* head) {
    cycle ans;
    ans.len=-1;
    ans.start=-1;
    bool f = true;
    elem* ch = head;
    elem* z = head;
    ch = ch -> next;
    z = z -> next -> next;
    while (ch != z) {
        ch = ch -> next;
        if(z -> next -> next) {
            z = z -> next -> next;
        } else {
            f = false;
            break;
        }
    }
    if(f) {
        int l = 1;
        z = z -> next;
        while (z != ch) {
            l++;
        }
        int start;
        z = head;
        while (z != ch) {
            z = z -> next;
            ch = ch -> next;
        }
        start = z -> val;
        ans.start = start;
        ans.len = l;
    }
    if(!f) {
        ans.len = -1;
        ans.start = -1;
    }
    return ans;
}
// КОНЕЦ ФУНКЦИИ ДЛЯ СДАЧИ
/*
elem* add(elem* head, int x) {
    elem* p = new elem;
    p->val = x;
    p->next = head;
    return p;
}

int main() {
    int k,n;
    cin >> k >> n;
    elem* head = NULL;
    head = add(head,0);
    elem* p = head;
    for (int i = 1; i < n; i++) {
        head = add(head, i);
    }
    p->next = head;
    for (int i = 0; i < k; i++) {
        head = add(head, i + n);
    }

    cycle ans = find_cycle(head);
    cout << ans.start << " " << ans.len << endl;
    return 0;
}*/