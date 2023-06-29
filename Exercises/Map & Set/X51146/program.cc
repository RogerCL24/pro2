#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> totes, cap;
    string x;
    while (cin >> x and x != ".") cap.insert(x);

    int n;
    cin >> n;
    while (cin >> x and x != ".") {
            totes.insert(x);
            cap.erase(x);
    }
    
    set<string>::iterator it = totes.end();
    for (int i = 1; i < n; ++i) {
        it = totes.begin();
        while (cin >> x and x != ".") {
            cap.erase(x);
	    while (it != totes.end() and *it < x) it = totes.erase(it);
	    if (it != totes.end() and *it == x) ++it;
        }
    }
    while (it != totes.end()) it = totes.erase(it);
    cout << "Totes les activitats:";
    
    for (set<string>::const_iterator it = totes.begin(); it != totes.end(); ++it) cout << ' ' << *it;
    cout << endl;

    cout << "Cap activitat:";
    
    for (set<string>::iterator it = cap.begin(); it != cap.end(); ++it) cout << ' ' << *it;
    cout << endl;
}