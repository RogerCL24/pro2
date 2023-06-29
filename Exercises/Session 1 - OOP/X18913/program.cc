#include <vector>
 using namespace std;
 
 int busqueda_lin(const vector<int>& v, int x) {
	int size = v.size();
	int i = 0;
	bool found = false;	
	while (i < size and not found) {
		if (x == v[i]) found = true;
		else ++i;
	}
	return i;
}
