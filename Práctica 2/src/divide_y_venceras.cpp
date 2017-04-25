#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

//generador de ejemplos para el problema de la comparación de preferencias. Simplemente se genera una permutación aleatoria del vector 0,1,2,...,n-2,n-1

double uniforme() //Genera un número uniformemente distribuido en el
//intervalo [0,1) a partir de uno de los generadores
//disponibles en C.
{
  int t = rand();
  double f = ((double)RAND_MAX+1.0);
  return (double)t/f;
}


int contarInversiones( int * preferencias1, int * preferencias2, const int TAM) {

  int total = 0 ;
  for (int i = 0 ; i < TAM ; i++) {
    int j = 0 ;
    bool menor = true ;
    while (j < TAM && menor) {
      if (preferencias2 [i] < preferencias1 [j]) {
	j++;
	total++;
      }
      else
	menor = false;
    }
  }
  return total;
}

int comparaPreferencias(int * v , const int TAM ) {
  if (TAM == 0)
    return 0 ;

  const int MITAD = TAM /2 ;
  int * preferencias1 = new int [MITAD];
  int * preferencias2 = &v[MITAD];
  preferencias1 = v ;

  int pref1 = comparaPreferencias(preferencias1, MITAD);
  int pref2 = comparaPreferencias(preferencias2, MITAD);
  int total = pref1 + pref2 ;

  total += contarInversiones(preferencias1, preferencias2, MITAD);

  return total ;

}





int main(int argc, char * argv[]) {

  if (argc != 2) {
    cerr << "Formato " << argv[0] << " <num_elem>" << endl;
    return -1;
  }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

  srand(time(0));

  for (int j = 0; j < n; j++) T[j]=j; // Inicializamos

  for (int j = n-1; j > 0; j--) {
    double u = uniforme();
    int k = (int)(j*u);
    int tmp = T[j];
    T[j] = T[k];
    T[k] = tmp;
  }
	
  clock_t tantes;
  clock_t tdespues;
  int invertidos = 0 ;

  tantes = clock();
  invertidos = comparaPreferencias(T,n);
  tdespues = clock();

  cout << n << " " << (double)(tdespues-tantes)/CLOCKS_PER_SEC << endl ;
  delete [] T ;


}
