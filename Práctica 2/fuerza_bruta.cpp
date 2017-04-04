#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char * argv[]) {

	int invertidos = 0 ;

	if (argc != 2) {
		cerr << "Formato " << argv[0] << " <num_elem>" << endl;
		return -1;
	}

	srand(time(NULL));

	int n = atoi(argv[1]);

	int * v1 = new int[n];
	int * v2 = new int[n];
	assert(v1);
	assert(v2);

	for (int i = 0 ; i < n ; i++)
		v1[i] = i+1 ; // En el enunciado pone desde 1 a n

	for (int i = 0 ; i < n ; i++)
		v2[i] = rand()%n ; 


	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			if ( i < j && v2[i] > v2[j]) 
				invertidos++;
		}
	}

}


