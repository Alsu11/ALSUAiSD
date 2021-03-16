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
    elem* ch = head;
    elem* z = head;
    bool c = false;
    while (head && ch -> next && z -> next -> next) {
        ch = ch->next;
        z = z->next->next;
        if (ch == z) {
            c = true;
        }
        if(c) {
            break;
        }
    }
    if (c) {
        int l = 1;
        z = z->next;
        while (z != ch) {
            l++;
            z = z -> next;
        }
        z = head;
        int s = 0;
        while (z != ch) {
            ch = ch->next;
            z = z->next;
            s++;
        }
        ans.len = l;
        ans.start = s;
        return ans;
    }
    if(!c) {
        int r = 0;
        while (head && head -> next) {
            r++;
            head = head -> next;
        }
        ans.start = r;
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
}
*/