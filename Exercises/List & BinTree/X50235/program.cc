#include "BinTree.hh"
#include <iostream>
using namespace std;

bool poda_subarbre (BinTree<int>& a, int x) {
    if (a.empty()) return false;
    else if (a.value() == x) {
        a = BinTree<int>();
        return true;
    }
    else {
        BinTree<int> le = a.left();
        BinTree<int> ri = a.right();
        bool r = poda_subarbre(le, x);
        if (not r) r = poda_subarbre(ri, x);
        a = BinTree<int>(a.value(), le, ri);
        return r;
    }
}