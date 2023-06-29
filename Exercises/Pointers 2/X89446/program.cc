Llista reorganitzar_out(const T& x) const {
  Llista l;
  if (longitud == 0) return l;
  // Construimos dos cadenas de nodos doblemente enlazados:
  // 1) menores iguales que x [l.primer_node ... ult_men]
  // 2) mayores que x  [l.act ...l.ultim_node]
  node_llista* ult_men = NULL;
  l.act = l.ultim_node = l.primer_node = NULL;
  l.longitud = longitud;
  node_llista* m = primer_node;
  while (m != NULL) {
     if (m->info <= x) { // m pasa a ser el último de los menores o iguales
         if (ult_men == NULL) { // cadena vacía
	    ult_men = new node_llista;      
            l.primer_node = ult_men;  
            l.primer_node->ant = NULL;
	 }
	 else {
            ult_men->seg = new node_llista; 
            (ult_men->seg)->ant = ult_men;
            ult_men = ult_men->seg;
         }  
         ult_men->info = m->info;
      }
      else { // m pasa a ser el último de los mayores
	 if (l.ultim_node == NULL) { // cadena vacía
	    l.ultim_node = new node_llista;        
            l.act = l.ultim_node; 
            l.act->ant = NULL; 
         }
         else {
	    l.ultim_node->seg = new node_llista; 
            (l.ultim_node->seg)->ant = l.ultim_node; 
            l.ultim_node = l.ultim_node->seg; 
         }
         l.ultim_node->info = m->info;
      }
      m = m->seg;
  }
  // ajustar los finales de las dos cadenas separadas de nodos
  if (l.primer_node == NULL) l.primer_node = l.act; // no hay menores o iguales que x
  else if (l.act == NULL) l.ultim_node = ult_men;   // no hay mayores que x
  else { // ambas cadenas son no vacías
    ult_men->seg = l.act; 
    l.act->ant = ult_men; 
  }
  l.ultim_node->seg = NULL;
  return l; 
}