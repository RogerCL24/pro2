#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    map<string,int> m;
    string name;
    cin >> name;
    while (name != ".") {
        m[name];
        cin >> name;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        set<string> d;
        cin >> name;
        while (name != ".") {
            d.insert(name);
            cin >> name;
        }
        for (set<string>::iterator it = d.begin(); it != d.end(); ++it) {
            map<string, int>::iterator itm = m.find((*it));
            ++itm->second;
        }
    }
    cout << "Totes les activitats:";
    for (map<string,int>::iterator it = m.begin(); it != m.end(); ++it) {
        if ((*it).second == n) cout << ' ' << (*it).first;
    }
    cout << endl;

    cout << "Cap activitat:";
    for (map<string,int>::iterator it = m.begin(); it != m.end(); ++it) {
        if ((*it).second == 0) cout << ' ' << (*it).first;
    }
    cout << endl;
}

