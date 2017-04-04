#include <iostream>
using namespace std;

void swap (int &a, int &b) {
	int c ;
	c = a ;
	a = b ;
	b = c ;
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

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			if ( i < j && v2[i] > v2[j] )
				swap (&v2[i],&v2[j]);
			}
	}

}


