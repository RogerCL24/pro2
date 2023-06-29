

  node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a) {
    node_llista* aux; 
    if (m == NULL) a = aux = u = NULL;
    else {
      aux = new node_llista;
      aux->info = m->info;
      aux->ant = NULL;
      if (m == oact) a = aux;
      node_llista* n = aux;
      while (m->seg != NULL) {
        m = m->seg;
        n->seg = new node_llista;
        n->seg->ant = n;
        n = n->seg;
        n->info = m->info;
        if (m == oact) a = n;
      }
      n->seg = NULL;
      u = n;
      if (oact == NULL) a = NULL;
    }
    return aux;
  }

Llista& operator=(const Llista& original) 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una copia d'original i qualsevol contingut
     anterior del p.i. ha estat esborrat (excepte si el p.i. i original ja
     eren el mateix objecte) */
  {
    if (this != &original) {
      longitud = original.longitud;
      esborra_node_llista_it(primer_node);
      primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
    }
    return *this;
  }