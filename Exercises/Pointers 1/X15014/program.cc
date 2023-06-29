/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
  void arb_sumes(Arbre<int> &asum) const {
    asum.primer_node = sum(primer_node);
  }

   static node_arbre* sum (node_arbre* m) {
    node_arbre* n;
    if (m == NULL) n = NULL;
    else {
      n = new node_arbre;
      n->info = m->info;
      n->segE = sum(m->segE);
      if (n->segE != NULL) n->info += n->segE->info;
      n->segD = sum(m->segD);
      if (n->segD != NULL) n->info += n->segD->info;
    }
    return n;
  }