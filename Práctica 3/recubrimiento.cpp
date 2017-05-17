#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > recubrimiento ( vector<vector<int> > m , int N) {

	vector<pair<int, int> > sol ;
	
	int nodo_actual = 0 ;

	for (int f = 0 ; f < N-1 ; ++f) {
		nodo_actual = f ; 
		for (int c = f+1 ; c < N ; ++c) {
			if (m[f][c] != 0) {
				pair<int, int> p (nodo_actual, c);
				sol.push_back(p);
			}
		}
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

	vector<pair<int, int> > solucion = recubrimiento ( matriz, tamanio ) ;

	cout << "Conjunto de aristas solución: " ;
	for (int i = 0; i < solucion.size(); ++i) 
			cout << "(" << solucion[i].first <<","<< solucion[i].second << ")";

	cout << "\n" ;	

}
