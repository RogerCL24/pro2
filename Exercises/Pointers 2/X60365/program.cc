bool buscar(const T& x) const {
  return buscar_node_arbreGen(primer_node,x); 
}


static bool buscar_node_arbreGen(node_arbreGen* m, const T& x) {
  if (m == NULL) return false; 
  else {
      if (m->info == x) return true; 
      int ari = (m->seg).size(); 
      for (int i = 0; i < ari; ++i) {
	if (buscar_node_arbreGen(m->seg[i],x)) return true; 
      }
      return false;
  }
}