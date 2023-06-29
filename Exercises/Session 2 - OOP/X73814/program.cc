#include "Estudiant.hh"
#include <iostream>
#include <vector> 
using namespace std;

typedef vector<Estudiant> Est;

// Simplifica un vector de estudiantes de modo que no se repita el dni
Est simp_vec(Est& v, int size) {
  int n = v.size();
  int y = 0;
  int dni = v[0].consultar_DNI();
  Est s(size);
  Estudiant Hector(dni);
  s[0] = Hector;
  if (v[0].te_nota()) s[0].afegir_nota(v[0].consultar_nota());
  for (int i = 1; i < n; ++i) {
    if (dni != v[i].consultar_DNI()) {
        ++y;
        dni = v[i].consultar_DNI();
        Estudiant Jaime(dni);
        s[y] = Jaime;
        if (v[i].te_nota()) s[y].afegir_nota(v[i].consultar_nota());
    }
    else if (v[i].te_nota()) {
        if (s[y].te_nota()) {
            if (s[y].consultar_nota() < v[i].consultar_nota()) s[y].modificar_nota(v[i].consultar_nota());
        }
        else s[y].afegir_nota(v[i].consultar_nota());
    }

  }

  return s;
}

// Escribe el vector de estudiantes ya simplifacado
void write_vec(Est& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) v[i].escriure();
}

int main() {
    int n;
    cin >> n;
    Est v (n);
    int size = 0;
    int dni = 0;
    for (int i = 0; i < n; ++i) {
        v[i].llegir();
        if (v[i].consultar_DNI() != dni) {
            ++size;
            dni = v[i].consultar_DNI();
        }
    }
    Est s = simp_vec(v, size);
    write_vec(s);
}
