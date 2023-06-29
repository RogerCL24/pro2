#include "BinTree.hh"
#include "ParInt.hh"

 void sumak(BinTree<ParInt>& a, int k)
 /*Pre: a = A */
 /*Post: a es com a A amb k sumat al segon component de cada node */ {
    if (not a.empty()) {
        BinTree<ParInt> a1 = a.left();
        BinTree<ParInt> a2 = a.right();
        sumak(a1, k);
        sumak(a2, k);
        ParInt p (a.value().primer(),a.value().segon() + k);
        a = BinTree<ParInt> (p, a1, a2);
    }

 }


