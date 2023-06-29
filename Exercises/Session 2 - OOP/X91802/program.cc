#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

 pair<int,int>  max_min_vest(const vector<Estudiant>& v) 
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
    {
        pair<int,int> p;
        int size = v.size();
        bool nota = false;
        double max, min;
        max = 0;
        min = v[0].nota_maxima();
        for (int i = 0; i < size; ++i) {
            if (v[i].te_nota()) {
                nota = true;
                if (v[i].consultar_nota() <= min) {
                    if (v[i].consultar_nota() == min and v[i].consultar_DNI() < v[p.second].consultar_DNI()) {
                        p.second = i;
                    }
                    else if (v[i].consultar_nota() < min) p.second = i;
                       
                    min = v[i].consultar_nota();
                
                }

                if (v[i].consultar_nota() >= max) {
                    if (v[i].consultar_nota() == max and v[i].consultar_DNI() < v[p.first].consultar_DNI()) {
                        p.first = i;
                    }
                    else if (v[i].consultar_nota() > max) p.first = i;

                    max = v[i].consultar_nota();

                }

            }
        }
        if (not nota) {
            p.first = p.second = -1;
            return p;
        }
        return p;

    }


