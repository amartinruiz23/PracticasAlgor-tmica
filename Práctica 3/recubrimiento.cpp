#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int tamanio ; // Tamaño de la matriz de adyacencia que le pasamos al ejecutable

/*
 * @brief : función que devuelve si dos vectores tienen los mismos elementos
 * @param : v1 primer vector a comparar
 * @param : v2 segundo vector a comparar
 * @return : bool si tienen los mismos elementos o no
*/

bool iguales (std::vector<int> v1, std::vector<int> v2) {

	int c = 0 ;

	if (v1.size() != v2.size())
		return false ;

	for (int i = 0 ; i < v1.size() ; i++) {
		for (int j = 0 ; j < v2.size() ; j++) {
			if (v1[i] == v2[j]) {
				c++ ;
				j = v2.size() ;
			}
		}
	}

	if (c == v1.size())
		return true ;
	else 
		return false ;

}

/*
 * @brief : función que nos indica si un elemento está incluido o no en el vector
 * @param : v vector 
 * @param : x elemento que queremos saber si está o no dentro del vector
 * @return : booleano indicando si está o no dentro
*/

bool contains (std::vector<int> v, int x) {

	if (v.empty())
		return false ;

	if(std::find(v.begin(), v.end(), x) != v.end())
		return true ;
	else
		return false ;
}

/*
 * @brief : función que añade al vector Nodos Cubiertos (NC) los nodos adyacentes al nodo "nodo"
 * @param : nodo del que queremos incluir sus adyacentes
 * @param : NC lista de nodos cubiertos por el recubrimiento
 * @param : m matriz de adyacencia del grafo
*/

void adyacencias (int nodo, std::vector<int> &NC, std::vector<std::vector<int> > m) {
			
	for (int c = 0 ; c < tamanio ; c++) {
		if (m[nodo][c] != 0) {
			if ( !contains(NC,c) ) 
				NC.push_back(c);
			
		}
	}

}

/*
 * @brief : función que devuelve el nodo con mayor número de incidencias no usado de un grafo
 * @param : m matriz de adyacencia del grafo
 * @param : LCU lista de nodos usados
 * @return : nodo con más incidencias no usado
*/

int getNodoMaxInc (std::vector<std::vector<int> > m, std::vector<int> &LCU) {

	int nodo = -1 ;
	int max_incidencias = 0 ;
	int contador = 0 ;		// contador del número de adyacencias o 1s en una determinada fila de la matriz

	for (int f = 0 ; f < tamanio-1 ; f++) {

			contador = 0 ;

			if ( !contains (LCU, f) ) { 	// Si el nodo actual no ha sido usado ya

				for (int c = 0 ; c < tamanio ; c++) {
					if ( m[f][c] == 1 ) 
						contador++;
				}

				if (contador > max_incidencias){ 	// Si es el nodo que más adyacencias tiene, actualizamos el máximo y lo devolvemos en su caso 
					nodo = f ;
					max_incidencias = contador;
				}

			}

	}

	LCU.push_back(nodo);
	return nodo ;

}

std::vector<int> recubrimiento (std::vector<std::vector<int> > m) {

	std::vector<int> nodos ; 											// lista de nodos

  for (int i= 0; i<tamanio; i++)								// inicializamos lista de 
    nodos.push_back(i);													// nodos

	std::vector<int> sol ;												// lista de nodos solución / recubrimiento
	std::vector<int> NC ;													// lista de nodos recubiertos
	std::vector<int> LCU ;												// lista de candidatos utilizados
	int nodo ;


  while ( (!iguales(NC, nodos))  ) { 		// mientras no estén recubiertos todos los nodos
	
		nodo = getNodoMaxInc(m, LCU);								// obten el nodo con mayor nº de incidencias
	
		if (nodo != -1) {

			if ( !contains(NC,nodo) )
				NC.push_back(nodo);												// añadimos el nodo al recubrimiento
			adyacencias(nodo, NC, m);									// y sus adyacentes

			sol.push_back(nodo);											// añadimos el nodo a la solución

		}

	}

	return sol ;

}

int main (int argc, char* argv[]) {

	/* Entrada de argumentos y creación de variables */

	if (argc < 2) {
		std::cout << "Error en la entrada de parámetros. Recuerde: ./recubrimiento fichero_entrada" << std::endl ;
		return (-1);
	}

	char* archivo = (char*) argv[1];
	int dato ;
	std::vector<std::vector<int> > matriz ;
	std::ifstream flujo (archivo) ;

	/* Leemos la matriz de adyacencia del grafo */

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
	std::cout << "\n\n" << std::endl;
	}
	else {
		std::cout << "Error al abrir el fichero" << std::endl ;
		return (-2);
	}

	/* Aplicamos el algoritmo y devolvemos el resultado */

	std::vector<int> solucion = recubrimiento (matriz) ;
	std::cout << "Solución = Recubrimiento formado por los nodos " ;
	for (int i = 0; i < solucion.size(); ++i)
			std::cout << solucion[i] << " " ;

	std::cout << "\n" ;

}
