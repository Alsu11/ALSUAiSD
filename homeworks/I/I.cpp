#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    char letter;
    int freq;
    Tree* left;
    Tree* right;
};

vector<Tree*> v;

Tree* merge(Tree* l, Tree* r) {
    Tree* t = new Tree ;
    t -> left = l;
    t -> right = r;
    t -> letter = '\0';
    int l_freq = l -> freq;
    int r_freq =  r -> freq;
    t -> freq = l_freq + r_freq;
    return t;
}

// сортирует по убыванию
void quickSort(vector <Tree*> &vector, int begin, int end) {
    int i = begin;
    int j = end;
    Tree* tmp;
    Tree* pivot;
    pivot = vector[(i + j) /2];
    int fr = pivot -> freq;

    while (i <= j) {
        while (vector[i] -> freq > fr) {
            i++;
        }

        while (vector[j] -> freq < fr) {
            j--;
        }

        if (i <= j) {
            tmp = vector[i];
            vector[i] = vector[j];
            vector[j] = tmp;
            i++;
            j--;
        }
    }

    if (begin < j) quickSort(vector, begin, j);
    if (i < end) quickSort(vector, i, end);
}

void print(Tree* full, int l) {
    if(!full) return;
    if(!full -> right && !full -> left) {
        cout << full -> letter << " " << l << "\n";
    } else {
        l++;
        print(full -> right, l);
        print(full -> left, l);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int w;
        cin >> w;
        Tree* tree = new Tree;
        tree -> letter = c;
        tree -> freq = w;
        tree -> left = NULL;
        tree -> right = NULL;
        v.push_back(tree);
    }

    quickSort(v,0, v.size() - 1 );

    while(true) {
        // объединим
        Tree* t = merge(v[v.size()-1], v[v.size()-2]);

        // удалим
        v.pop_back();
        v.pop_back();

        // добавим
        v.push_back(t);

        // отсортируем
        quickSort(v, 0, v.size() -1);

        if(v.size() == 1) {
            break;
        }
    }

    // выведем
    Tree* full = v[0];
    print(full, 0);

    return 0;
}