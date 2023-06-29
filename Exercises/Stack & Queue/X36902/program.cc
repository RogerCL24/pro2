#include <stack>
#include <iostream>
using namespace std;

int main() {
    stack <char> p;
    int count = 0;
    char letter;
    bool correcte = true;
    cin >> letter;
    while (letter != '.' and correcte) {
        if (letter == '(' or letter == '[') p.push(letter);
        else {
            if (not p.empty() and p.top() == '(' and letter == ')') p.pop();
            else if (not p.empty() and p.top() == '[' and letter == ']') p.pop();
            else {
                p.push(letter);
                correcte = false;
            }
        }
        ++count;
        cin >> letter;
    }
    if (p.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte " << count << endl;
}