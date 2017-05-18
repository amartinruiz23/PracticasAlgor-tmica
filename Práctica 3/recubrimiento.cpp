#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isIncluded (int a, vector<int> LC) {
	if(find(LC.begin(), LC.end(), a) != LC.end()) 
		return true ;
	else 
		return false ;
}

int getNodoMaxInc (vector<vector<int> > m, vector<int> LC) {

	int N = m.size();
	int max = 0 ;
	int contador = 0 ;

	for (int f = 0 ; f < N ; f++) {
		
		if (contador > max) 
			max = f ;

		contador = 0 ;

		if ( isIncluded(f, LC) ) {

			for (int c = f+1 ; c < N ; c++) {
				if ( m[f][c] == 1 ) 
					contador++;
			}

		}

	}

	return max ;

}

vector<int> recubrimiento (vector<vector<int> > m , int N) {

	vector<int> sol ;
	vector<int> LC ;
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
		cout << "Error en la entrada de parámetros. Recuerde: ./recubrimiento fichero_entrada" << endl ;
		return (-1);
	}

	char* archivo = (char*) argv[1];
	int tamanio ;
	int dato ;
	vector<vector<int> > matriz ; 
	ifstream flujo (archivo) ;
	
	if (flujo) {
		flujo >> tamanio ;
		matriz.resize(tamanio);
		for (int i = 0; i < tamanio; i++)
			matriz[i].resize(tamanio);
		cout <<"TAM: "<< tamanio << endl;
	
		for (int f = 0; (f < tamanio) && flujo; ++f) {
			cout << "\n" ;
			for (int c = 0; (c < tamanio) && flujo; ++c) {	
				flujo >> dato ; 
				cout << dato;
				matriz[f][c] = dato; 
			}
		}
		cout << "\n\n" ;
	
	}
	else {
		cout << "Error al abrir el fichero" << endl ;
		return (-2);
	}

	vector<int> solucion = recubrimiento ( matriz, tamanio ) ;

	cout << "Conjunto de aristas solución: " ;
	for (int i = 0; i < solucion.size(); ++i) 
			cout << solucion[i] << "," ;

	cout << "\n" ;	

}
