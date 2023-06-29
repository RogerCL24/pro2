#include "Estudiant.hh"
#include <vector>
#include <iostream>

using namespace std;

// Llegir un vector de tipus Estudiant
void llegir_vector_Estudiant(vector<Estudiant>& v) {
    int size;
    cin >> size;
    v = vector<Estudiant> (size);
    for (int i = 0; i < size; ++i) v[i].llegir();

}

// Arrodonir la nota
void arrodonir_vector(vector<Estudiant>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].te_nota()) {
            v[i].modificar_nota(((int) (10. * (v[i].consultar_nota() + 0.05))) / 10.0);
        }
    }
}

// Escriure un vector de tipus Estudiant
void escriure_vector_Estudiant(const vector<Estudiant>& v) {
    for (int i = 0; i < v.size(); ++i) v[i].escriure();

}