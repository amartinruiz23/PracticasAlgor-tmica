#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*class Par {

	int primer_elemento ;
	int segundo_elemento ;

	public:

	Par (int p_e, int s_e) {
		primer_elemento = p_e;
		segundo_elemento = s_e;
	}

	Par () {
		primer_elemento = 0 ;
		segundo_elemento = 0 ;
	}

	int getPrimerE () {
		return primer_elemento;
	}

	int getSegundoE () {
		return segundo_elemento;
	}

	friend std::ostream& operator<<(std::ostream &s , Par &p) {
		s << "(" << p.getPrimerE() << "," << p.getSegundoE() << ")" << "\t" ;
		return s ;
	}

};*/


vector<pair<int, int> > recubrimiento ( vector<vector<int> > m , int N) {

	cout << "dentro de recubrimiento" << endl ;
	vector<pair<int, int> > sol ;
	
	int nodo_actual = 0 ;

	for (int f = 0 ; f < N ; ++f) {
		nodo_actual = f ; // Se actualiza el nodo_inicial a la "etiqueta del nodo"
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
	vector<vector<int> > matriz ; // Se puede optimizar
	ifstream flujo (archivo) ;
	
	if (flujo) {
		flujo >> tamanio ;
		matriz.resize(tamanio);
		for (int i = 0; i < tamanio; i++)
			matriz[i].resize(tamanio);
		cout <<"TAM: "<< tamanio << endl;
	
		for (int f = 0; (f < tamanio) && flujo; ++f) {
			cout << "\n" ;
			for (int c = 0; (c < tamanio) && flujo; ++c) {		// Se puede optimizar
				flujo >> dato ; 
				cout << dato;
				matriz[f][c] = dato; 
			}
		}
		cout << "\n" ;
	
	}
	else {
		cout << "Error al abrir el fichero" << endl ;
		return (-2);
	}

	vector<pair<int, int> > solucion = recubrimiento ( matriz, tamanio ) ;

	
	for (int i = 0; i < tamanio; ++i)
			cout << "(" << solucion[i].first <<", "<<solucion[i].second << ")\t";
	

}
