#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool contains (std::vector<int> LC, int x) {
	
	if (LC.empty())
		return false ;
	
	if(std::find(LC.begin(), LC.end(), x) != LC.end()) 
		return true ;
	else 
		return false ;
}

int getNodoMaxInc (std::vector<std::vector<int> > m, std::vector<int> LC) {

	int N = m.size();
	int max = 0 ;
	int contador = 0 ;

	for (int f = 0 ; f < N ; f++) {
		
		if (contador > max) 
			max = f ;

		contador = 0 ;

		if ( contains(LC, f) ) {

			for (int c = f+1 ; c < N ; c++) {
				if ( m[f][c] == 1 ) 
					contador++;
			}

		}

	}

	return max ;

}

std::vector<int> recubrimiento (std::vector<std::vector<int> > m , int N) {

	std::vector<int> sol ;
	std::vector<int> LC ;
	int nodo ;

  // Inicializar la lista de candidatos

  for (int i= 0; i<N; i++)
    LC.push_back(i);


  while ( !LC.empty() ) { // Mientras la lista de candidatos no esté vacía...

		nodo = getNodoMaxInc(m, LC);
		sol.push_back(nodo);
		LC.erase (LC.begin()+nodo);
	
	}

	return sol ;

}
	
int main (int argc, char* argv[]) {

	if (argc < 2) {
		std::cout << "Error en la entrada de parámetros. Recuerde: ./recubrimiento fichero_entrada" << std::endl ;
		return (-1);
	}

	char* archivo = (char*) argv[1];
	int tamanio ;
	int dato ;
	std::vector<std::vector<int> > matriz ; 
	std::ifstream flujo (archivo) ;
	
	if (flujo) {
		flujo >> tamanio ;
		matriz.resize(tamanio);
		for (int i = 0; i < tamanio; i++)
			matriz[i].resize(tamanio);
		std::cout <<"TAM: "<< tamanio << std::endl;
	
		for (int f = 0; (f < tamanio) && flujo; ++f) {
			std::cout << "\n" ;
			for (int c = 0; (c < tamanio) && flujo; ++c) {	
				flujo >> dato ; 
				std::cout << dato;
				matriz[f][c] = dato; 
			}
		}
		std::cout << "\n\n" ;
	
	}
	else {
		std::cout << "Error al abrir el fichero" << std::endl ;
		return (-2);
	}

	std::vector<int> solucion = recubrimiento ( matriz, tamanio ) ;

	std::cout << "Conjunto de aristas solución: " ;
	for (int i = 0; i < solucion.size(); ++i) 
			std::cout << solucion[i] << "," ;

	std::cout << "\n" ;	

}
