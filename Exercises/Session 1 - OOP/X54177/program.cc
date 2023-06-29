#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= a; ++i) {
   int x = 0;
   int y;
   cin >> y;
    while (y != b) {
	x += y;
        cin >> y;
    }
    string s;
    if (y == b) getline(cin, s);
    cout << "La suma de la secuencia " << i << " es " << x << endl; 
  }
}


// prueba
// otra prueba

