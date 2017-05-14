#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Par {

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

	friend std::ostream& operator<<(std::ostream &s , const Par &p) {
		s << '(' << p.getPrimerE() << "," << p.getSegundoE() << ")" << "\t" ;
		return s ;
	}	

};


vector<Par> recubrimiento ( vector<vector<int> > m ) {

	vector<Par> sol ;
	int nodo_actual = 0 ;

	for (int f = 0 ; f < N ; ++f) { 
		for (int c = i+1 ; c < N ; ++c) {
			if (m[f][c] != 0) {
				Par p (nodo_actual, c);
				sol.push_back(p);				
				nodo_actual = c ; // Se actualiza el nodo_inicial a la "etiqueta del nodo"
			}
		}
	}

	return sol ;
}
		

int main (int argc, char* argv[]) {

	if (argc < 2) {
		cout << "Error en la entrada de parámetros. Recuerde: ./recubrimiento fichero_entrada" << endln ;
		return (-1);
	}

	char archivo[20] = argv[1];
	int tamanio ;
	int dato ;

	ifstream flujo (archivo) ;

	if (flujo) {
		flujo >> tamanio ;

		char[2] salto_linea ;

		vector<vector<int> > matriz ; // Se puede optimizar 

		for (int f = 0; f < tamanio && flujo; ++f) {
			flujo >> salto_linea ;
			for (int c = 0; c < tamanio && flujo; ++c) {		// Se puede optimizar
				flujo >> dato ;
				matriz.push_back(dato); 
			}
		}

	}
	else {
		cout << "Error al abrir el fichero" << endln ;
		return (-2);
	}


	vector<Par> solucion = recubrimiento ( matriz ) ;

	for (int i = 0; f < tamanio; ++f) 
			cout << solucion[i] ;
		 

}

