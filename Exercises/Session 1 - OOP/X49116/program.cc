#include <vector>
 using namespace std;
 
 struct parint {
int prim, seg;
};
 
 parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 {
    parint god;
    int min;
    int max;
    max = min = v[0];
    int size = v.size();
    for (int i = 1; i < size; ++i) {
	if (v[i] > max) max = v[i];
	if (v[i] < min) min = v[i];
   }
    god.prim = max;
    god.seg = min;
    return god;

 }
 
 pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
 {
 pair<int,int> PAIR;
int min;
    int max;
    max = min = v[0];

 int size = v.size();
    for (int i = 1; i < size; ++i) {
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
   }
    PAIR.first = max;
    PAIR.second = min;
    return PAIR;  
 }
 
 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
    x = y = v[0];
   int size = v.size();
    for (int i = 1; i < size; ++i) {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
   }
    
 }
