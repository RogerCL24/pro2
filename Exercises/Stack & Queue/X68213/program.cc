#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

void read_book(vector<stack<string>>& p) {
    string w;
    cin >> w;
    int i;
    cin >> i;
    p[i - 1].push(w);
}

void eliminate(vector<stack<string> >& p) {
    int num, i;
    cin >> num >> i;
    for (int j = 0; j < num; ++j) p[i - 1].pop();   
}

void write(const vector<stack<string>>& p) {
    int i;
    cin >> i;
    stack<string> copy = p[i - 1];
    cout << "Pila de la categoria " << i << endl;
    while (not copy.empty()) {
        cout << copy.top() << endl;
        copy.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector <stack<string> > dev(n);
    int opt;
    while (cin >> opt and opt != -4) {
        if (opt == -1) read_book(dev);
        else if (opt == -2) eliminate(dev);
        else write(dev);   
    }
}