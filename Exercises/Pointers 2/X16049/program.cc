void reorganitzar_in(const T& x) {
  if (longitud == 0) return;
  // <= [primer_node ... ult_men]
  // >  [act ... ultim_node]
  node_llista* m = primer_node;
  node_llista* ult_men = NULL;
  act = ultim_node = primer_node = NULL; 
  while (m != NULL) {
     if (m->info <= x) { 
         if (ult_men == NULL) { // cadena vacía
	    ult_men = m;      
            primer_node = ult_men;  
	    primer_node->ant = NULL;
	 }
	 else { // enlazamos detrás del último
            ult_men->seg = m; 
            m->ant = ult_men;
            ult_men = m;
         }  
      }
      else {
	if (ultim_node == NULL) { // cadena vacía
            ultim_node = m;
	    act = ultim_node;        
	    act->ant = NULL; 
         }
         else { // enlazamos detrás del último
	    ultim_node->seg = m; 
            m->ant = ultim_node; 
            ultim_node = m; 
         }
      }
      m = m->seg;
  }
  // ajustar los finales de las dos cadenas separadas de nodos
  if (primer_node == NULL) primer_node = act; 
  else if (act == NULL) ultim_node = ult_men; 
  else { // ambas cadenas son no vacías
    ult_men->seg = act; 
    act->ant = ult_men; 
  }
  ultim_node->seg = NULL; 
}