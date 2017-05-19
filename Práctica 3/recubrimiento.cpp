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

	std::cout << "dentro de gNMI" << std::endl ;

	int N = m.size();
	std::cout << "N= " << N << std::endl ;
	int max = 0 ;
	int contador = 0 ;

	for (int f = 0 ; f < N-1 ; f++) {

		if ( contains(LC, f) ) {
			std::cout << "LC contiene a f que vale " << f << std::endl ;

			contador = 0 ;

			for (int c = f+1 ; c < N ; c++) {
				if ( m[f][c] == 1 )
					contador++;
			}

			if (contador > max) //COMPARANDO NUMERO DE 1 CON NUMERO DE FILA
				max = f ;


		}


	}
	std::cout << "max = " << max << std::endl ;

	return max ;

}

std::vector<int> recubrimiento (std::vector<std::vector<int> > m , int N) {

	//std::cout << "dentro de recubrimiento" << std::endl ;

	std::vector<int> sol ;
	std::vector<int> LC ;
	int nodo ;

  // Inicializar la lista de candidatos

  for (int i= 0; i<N; i++)
    LC.push_back(i);

	//std::cout << "dentro de recubrimiento2" << std::endl ;


  while ( !LC.empty() && nodo != 0) { // Mientras la lista de candidatos no esté vacía...
	//std::cout << "dentro de recubrimientoI" << std::endl ;

		nodo = getNodoMaxInc(m, LC);
		std::cout << "nodo = " << nodo << std::endl ;
		if (nodo != 0) {
			sol.push_back(nodo);
		//std::cout << "dentro de recubrimientoI2" << std::endl ;
			for (int i = 0; i < LC.size(); i++) {
		//		std::cout << "LC[i] = " << LC[i] << std::endl ;
				if (LC[i] == nodo)
					LC.erase(LC.begin()+i);
			}
		}

	}
	//std::cout << "dentro de recubrimientoN" << std::endl ;

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

	std::cout << "a" << std::endl;

	if (flujo) {
		flujo >> tamanio ;
		matriz.resize(tamanio);
std::cout << "b" << std::endl ;
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
std::cout << "c" << std::endl ;
//		std::cout << "\n\n" << std::endl;
	std::cout << "f" << std::endl ;
	}
	else {
		std::cout << "Error al abrir el fichero" << std::endl ;
		return (-2);
	}
std::cout << "d" << std::endl ;
	std::vector<int> solucion = recubrimiento ( matriz, tamanio ) ;
std::cout << "e" << std::endl ;
	std::cout << "Conjunto de aristas solución: " ;
	for (int i = 0; i < solucion.size(); ++i)
			std::cout << solucion[i] << "," ;

	std::cout << "\n" ;

}
