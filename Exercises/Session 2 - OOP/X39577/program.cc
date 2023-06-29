#include "Estudiant.hh"
#include <vector>

typedef vector <Estudiant> Est;

void escriure_v(const Est& v) {
    for (int i = 0; i < v.size(); ++i) v[i].escriure();
    
}

int main() {
    int M, N, S;
    cin >> M >> N >> S;

    vector <int> pos (N,0);
    double pos_note;
    for (int i = 0; i < S; ++i) {
        cin >> pos_note;
        pos[pos_note - 1] = 1;
    }

    int dni = 0;
    double note = 0;
    
    Est vest (M);
    for (int i = 0; i < M; ++i) {
        double final_note = 0;
        cin >> dni;
        Estudiant Jaime(dni);
        vest[i] = Jaime;
        for (int j = 0; j < N; ++j) {
            cin >> note;
            if (pos[j] == 1) final_note += note;
        }

        final_note /= S;
        vest[i].afegir_nota(final_note);
    }

    escriure_v(vest);
}