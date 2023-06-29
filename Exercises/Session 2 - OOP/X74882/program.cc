#include "Cjt_estudiants.hh"

int main() {
    Cjt_estudiants first, second;
    
    first.llegir();
    second.llegir();

    int n = first.mida();
    double note1 = 0;
    double note2 = 0;
    for (int i = 1; i <= n; ++i) {
        Estudiant Santi = first.consultar_iessim(i);
        Estudiant Tenner = second.consultar_iessim(i);
        if (Santi.te_nota()) {
            note1 = Santi.consultar_nota();
            if (Tenner.te_nota()) {
                note2 = Tenner.consultar_nota();
                if (note1 < note2) first.modificar_iessim(i, Tenner);
            }

        }
        else first.modificar_iessim(i, Tenner);   
    }

    first.escriure();  
}