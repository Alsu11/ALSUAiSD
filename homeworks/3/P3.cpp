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

int pop(elem*& head) {
    elem *p = head;
    head = head->next;
    char n = p->val;
    delete p;
    return n;
}

char peek(elem*& head) {
    elem *p = head;
    return p -> val;
}

bool empty(elem* head) {
    return head == NULL;
}

char order(elem*& head) {
    char c_out = pop(head);
    if(head) {
        char c_in = pop(head);
        if((c_out == '+' || c_out == '-') && (c_in == '*' || c_in == '/')) {
            push(head, c_out);
            return c_in;
        }
        if((c_out == '*' || c_out == '/') && (c_in == '*' || c_out == '/')) {
            push(head, c_in);
            return c_out;
        }
        if((c_in == '+' || c_in == '-') && (c_out == '*' || c_in == '/')) {
            push(head, c_in);
            return c_out;
        }
        if((c_out == '+' || c_out == '-') && (c_in == '+' || c_in == '-')) {
            push(head, c_in);
            return c_out;
        }
    }
    return c_out;
}

void compute(int n, const char* const s) {
    elem *head = NULL;
    char number[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < n; i++) {
        bool is_number = false;
        // cout << "now: " << s[i] << " ";
        for (int j = 0; j < 10; j++) {
            if (s[i] == number[j]) {
                cout << number[j] << " ";
                is_number = true;
                break;
            }
        }
        if (s[i] != ')' && !is_number) {
            push(head, s[i]);
        }
        if (s[i] == ')') {
            while (head && peek(head) != '(') {
                cout << order(head) << " ";
            }/*
            if(peek(head) == '(' && ) {
                pop (head);
            }*/
        }
    }
    while (!empty(head)) {
        cout << order(head) << " ";
    }
}

int main() {
    stack<int> stack;
    string s;
    getline(cin,s);
    int n = strlen(s.c_str());
    compute(n, s.c_str());
    //cout << compute(n, s.c_str()) << endl;
    return 0;
}