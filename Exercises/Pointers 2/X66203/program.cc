  T maxim() const {
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
   return maxim_rec(primer_node)->info;
  } 

  static node_arbreNari* maxim_rec(node_arbreNari* n) {
    node_arbreNari* max = n;
    int size = (n->seg).size();
    for (int i = 0; i < size; ++i) {
      if (n->seg[i] != NULL) {
        node_arbreNari* max_i = maxim_rec(n->seg[i]);
        if (max_i->info > max->info) max = max_i;
      }
    }
    return max;
  } 