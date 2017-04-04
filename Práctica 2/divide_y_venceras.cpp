#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getInvertidos (int * v1, int * v2) {

	int invertidos = 0 ;

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			if ( i < j && v2[i] > v2[j]) 
				invertidos++;
		}
	}

	return invertidos ;
} 

void inicializaV1 (int * v1) {

	for (int i = 0 ; i < n ; i++)
		v1[i] = i+1 ; // En el enunciado pone desde 1 a n
}

void inicializaV2 (int * v2) {

	srand(time(NULL));
	for (int i = 0 ; i < n ; i++)
		v2[i] = rand()%n ; 
}


int main(int argc, char * argv[]) {
	
	if (argc != 2) {
		cerr << "Formato " << argv[0] << " <num_elem>" << endl;
		return -1;
	}

	int n = atoi(argv[1]);

	int * v1 = new int[n];
	int * v2 = new int[n];
	assert(v1);
	assert(v2);

	inicializaV1(&v1);
	inicializaV2(&v2);
	cout << n << " " << getInvertidos(&v1,&v2) << endl ;	
}

