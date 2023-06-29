#include "Cjt_estudiants.hh"
#include <iostream>
using namespace std;

const int MAX_NEST = 5; 

double redondear(double r) {  
  return int(10.*(r + 0.05)) / 10.0;
} 

void rounding_notes (Cjt_estudiants& Kentall) {
    int n = Kentall.mida();
    for (int i = 1; i <= n; ++i) {
        Estudiant Conifus = Kentall.consultar_iessim(i);
        if (Conifus.te_nota()) {
            double note = Conifus.consultar_nota();
            note = redondear(note);
            Conifus.modificar_nota(note);
            Kentall.modificar_estudiant(Conifus);   
        }
    }
}

void modify_mark(Cjt_estudiants& Genes, int& dni, double note) {
    Estudiant Mary (dni);
    Mary.afegir_nota(note);
    if (Genes.existeix_estudiant(dni)) Genes.modificar_estudiant(Mary); 
    else {
        cout << "el estudiante " << dni << " no esta" << endl;
        cout << endl;
    }
}

void query_note(const Cjt_estudiants& Bravo, int& dni) {
    if (Bravo.existeix_estudiant(dni)) {
        Estudiant Kenneth = Bravo.consultar_estudiant(dni);
        if (Kenneth.te_nota()) {
            double note = Kenneth.consultar_nota();
            cout << "el estudiante " << dni << " tiene nota " << note << endl;
        }
        else cout << "el estudiante " << dni << " no tiene nota" << endl;
    }
    else cout << "el estudiante " << dni << " no esta" << endl;

    cout << endl;
}

void add_new_std(Cjt_estudiants& Connie, const Estudiant& Gohan) {
    int dni = Gohan.consultar_DNI();
    if (not Connie.existeix_estudiant(dni)) {
        if (MAX_NEST > Connie.mida()) Connie.afegir_estudiant(Gohan);
        else {
            cout << "el conjunto esta lleno" << endl;
            cout << endl;
        }
    }
    else {
        cout << "el estudiante " << dni << " ya estaba" << endl;
        cout << endl;
    }
}


int main() {
    Cjt_estudiants conj;
    conj.llegir();
    int n;
    cin >> n;
    while (n != -6) {
        int dni;
        double note;
        if (n == -1) {
            Estudiant Gohan;
            Gohan.llegir();
            add_new_std(conj, Gohan);
        }
        
        else if (n == -2) {
            cin >> dni;
            query_note(conj, dni);
        }
        
        else if (n == -3) {
            cin >> dni >> note;
            modify_mark(conj, dni, note);
        }

        else if (n == -4) {
            rounding_notes(conj);
        }

        else {
            conj.escriure();
            cout << endl;
        }

        cin >> n;
    }
}