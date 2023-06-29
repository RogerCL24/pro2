#include <iostream>
#include <map>
using namespace std;

int main() {
    char a;
    string b;
    map <string, int> d;
    while (cin >> a >> b) {
        if (a == 'a') ++d[b];       
        else cout << d[b] << endl;      
    }
}