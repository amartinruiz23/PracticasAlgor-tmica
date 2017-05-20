#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

/**
 * @brief Resolución del problema del caballo
 * @param k Nivel del árbol que se resuelve
 * @param T Estado del árbol que se genera
 * @param Mejor Mejor solución encontrada
 * @param benMejor Beneficion de la mejor solución encontrada
 * @param N Tam. del problema
 * @param B Vector de beneficios de objetos
 * @param W Vector de pesos
 * @param M Capacidad de la mochila
 */
void BTMochila(int k, bool *T, bool *Mejor, int &benMejor,
                int N, int *B, int *W, int M) {


    if (k>=N) {

        int benActual= 0; // Beneficio de la solución actual
        for (int i= 0; i<N; i++)
            benActual+= B[i]*( T[i]? 1:0 );

        if (benActual > benMejor) {

            // Copiamos T en Mejor
            memcpy(Mejor, T, N*sizeof(bool));

            // ACtualizar Coste
            benMejor= benActual;
        }
    } else {

        for (int i= 0; i<=1; i++) {

            T[k]= i; // Llevarnos/ no llevarnos objeto k


            // Calculamos Poda
            int peso= 0;
            for (int j= 0; j<=k; j++)
                peso+= W[j]*( T[j]? 1:0 );
            if (peso <= M) {
                BTMochila(k+1, T, Mejor, benMejor, N, B, W, M);
            } else {
                T[k]= 0;
            }
        }
    }

}


int main()
{
    const int N= 5;
    bool T[N];
    bool Mejor[N];
    int benMejor = 0;
    int B[N], W[N];
    int M= 10;


    srand(time(0));
    for (int i= 0; i<N; i++) {
        B[i]= rand()%N;
        W[i]= rand()%N;
    }

    // Inicializo a nodo raíz
    for (int i= 0; i<N; i++) {
        T[i]= 0;
        Mejor[i]= 0;
    }

    // Mostramos beneficios
    cout <<"B: ";
    for (int i= 0; i<N; i++) {
        cout <<B[i]<< " ";
    }
    cout <<endl;

    // Mostrar Pesos
    cout <<"W: ";
    for (int i= 0; i<N; i++) {
        cout <<W[i]<< " ";
    }
    cout <<endl;



    // Resolverlo
    BTMochila(0, T, Mejor, benMejor, N, B, W, M);


    // Mostrar solucin
    cout << "La mejor solución es: "<<endl;
    for (int i= 0; i<N; i++)
        cout << Mejor[i]<<" ";
    cout <<endl;
    cout << "Beneficio: "<<benMejor<<endl;

    return 0;
}
