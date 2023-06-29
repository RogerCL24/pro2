#include <iostream>
#include <map>
using namespace std;

int main() {
    char codi;
    string word;
    map <string, int> d;
    while (cin >> codi >> word) {
        if (codi == 'a') ++d[word];
        else if (codi == 'e') {
            if (d[word] > 0)--d[word];
        }
        else cout << d[word] << endl;
    }   

}