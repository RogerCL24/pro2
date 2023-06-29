void i_freq(node_arbreGen*& n, int& n_vegades, const T& x) {
  if (n != NULL) {
    if (n->info == x) ++n_vegades;
   
    for (int i = 0; i < int(n->seg.size()); ++i) {
      i_freq(n->seg[i], n_vegades, x);
    }
  }
}
 
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) {
  int n_vegades = 0;
  i_freq(this->primer_node, n_vegades, x);
  return n_vegades;
}