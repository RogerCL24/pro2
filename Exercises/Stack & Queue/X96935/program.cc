#include <stack>
#include <iostream>
using namespace std;

void output (bool palin) {
    if (palin) cout << "SI" << endl;
    else cout << "NO" << endl;
}

int main() {
    int size;
    cin >> size;
    int aux = size;
    if (size%2 != 0) ++size;
    size /= 2;
    stack<int> p;
    int num;
    while (size > 0) {
        cin >> num;
        p.push(num);
        --size;
    }
    if (aux%2 != 0) p.pop();
    int n;
    bool palin = true;
    while (not p.empty() and palin) {
        cin >> n;
        if (p.top() != n) palin = false;
        p.pop();
    }
    output(palin);
}