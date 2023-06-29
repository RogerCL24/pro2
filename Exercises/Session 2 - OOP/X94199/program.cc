#include "Estudiant.hh"
#include <vector>

void simplificar_vector(vector<Estudiant>& v, int& pos) {
	int n = v.size();
	pos = 0;
	for (int i = 1; i<n; i++) {
		if (v[i].consultar_DNI() == v[pos].consultar_DNI()) {
			if (v[i].te_nota()) {
				if (v[pos].te_nota() and v[i].consultar_nota() > v[pos].consultar_nota())
					v[pos].modificar_nota(v[i].consultar_nota());
				else if (not v[pos].te_nota())
					v[pos].afegir_nota(v[i].consultar_nota());
			}
		} else {
			pos++;
			swap(v[pos], v[i]);
		}
	}
}