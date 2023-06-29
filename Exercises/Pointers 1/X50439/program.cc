 
   /* Pre: cert */
    /* Post: si m és NULL, el resultat és NULL; en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que són
       còpia de de la cadena que té el node apuntat per m com a primer */
  node_pila* copia_node_pila_it(node_pila* m) {
    if (m == NULL) return NULL;
    else {
      node_pila* aux = new node_pila;
      node_pila* n = aux;
      n->info = m->info;
      m = m->seguent;
      while (m != NULL) {
        n->seguent = new node_pila; 
        n = n->seguent;
        n->info = m->info;
        m = m->seguent;
      }
      n->seguent = NULL;
      return aux;
    }
  }
 
 
 
 Pila& operator=(const Pila& original) 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una copia d'original i qualsevol
     contingut anterior del p.i. ha estat esborrat (excepte si el
     p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      altura = original.altura;
      esborra_node_pila_it(primer_node);
      primer_node = copia_node_pila_it(original.primer_node);
    }
    return *this;
  }