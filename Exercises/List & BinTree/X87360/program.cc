#include <iostream>
#include <list>
using namespace std;

void inter(list<int>& uno, const list<int>& dos)
 /* Pre: uno = U */
 /* Post: uno pasa a ser la interseccion de U y dos */ {
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();

    while (it1 != uno.end()) {
        if (it2 == dos.end()) it1 = uno.erase(it1);
        else {
            if (*it1 < *it2) it1 = uno.erase(it1);
            else if (*it1 > *it2) ++it2;
            else {
                ++it1;
                ++it2;
            }
        }
    }
    
 }