#include <cstring>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct elem {
    char val;
    elem* next;
};

// & - чтобы можно было менять аргумент
// (передача по ссылке)
void push(elem*& head, char n) {
    elem *p = new elem;
    p->val = n;
    p->next = head;
    head = p;
}

char pop(elem*& head) {
    elem *p = head;
    head = head->next;
    char n = p->val;
    delete p;
    return n;
}

char peek(elem*& head) {
    return head -> val;
}

bool empty(elem* head) {
    return head == NULL;
}

int priority(char c) {
    if (c == '+' || c =='-') {
        return 1;
    }
    if(c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

string compute(int n, const char* const s) {
    elem *head = NULL;
    string str;
    char number[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < n; i++) {
        bool is_number = false;
        for (int j = 0; j < 10; j++) {
            if (s[i] == number[j]) {
                str.push_back(s[i]);
                str.push_back(' ');
                is_number = true;
                break;
            }
        }
        if (!is_number) {
            bool sk = false;
            if (s[i] == '(') {
                sk = true;
                push(head, s[i]);
            }
            if (s[i] == ')') {
                sk = true;
                while (peek(head) != '(') {
                    str.push_back(peek(head));
                    str.push_back(' ');
                    pop(head);
                }
                pop(head);
            }
            if (!sk) {
                while (!empty(head) && priority(peek(head)) >= priority(s[i])) {
                    str.push_back(peek(head));
                    str.push_back(' ');
                    pop(head);
                }
                push(head, s[i]);
            }
        }
    }
    while(!empty(head)) {
        str.push_back(pop(head));
        str.push_back(' ');
    }
    return str;
}

int main() {
    string s;
    getline(cin,s);
    int n = strlen(s.c_str());
    cout << compute(n, s.c_str());
    return 0;
}