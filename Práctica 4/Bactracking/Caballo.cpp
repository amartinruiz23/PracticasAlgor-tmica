#include <stdio.h>
#include <stdlib.h>

#define N 8
#define ncuad N*N

void mover(int tablero[][N], int i, int pos_x, int pos_y,bool &encontrado);

const int ejex[8] = { -1,-2,-2,-1, 1, 2, 2, 1 },
          ejey[8] = { -2,-1, 1, 2, 2, 1,-1,-2 };

int main(int argc, char const *argv[]) {

  if(argc < 3 || atoi(argv[1]) < 0 || atoi(argv[1]) > N-1 || atoi(argv[2]) < 0 || atoi(argv[2]) > N-1 )    {
      fprintf(stderr, "ERROR: Faltan las posiciones de inicio o son incorrectas, el tablero es de %dx%d\n", N,N);
      exit(-1);
  }
  int tablero[N][N]; /* tablero del caballo. */
  int i,j,q;
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  bool encontrado = false;

   /* inicializa el tablero a cero */
  for (i = 0; i < N; i++)
   for (j = 0; j < N; j++)
    tablero[i][j] = 0;

   /* pone el primer movimiento */
  tablero[x][y] = 1;
  mover(tablero,2,x,y, encontrado);

  return 0;
}

void imprimir_solucion(int tablero[][N], bool &encontrado){
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%3d ", tablero[i][j]);
    putchar('\n');
  }
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  encontrado = true;
}


void mover(int tablero[][N],int i, int pos_x, int pos_y,bool &encontrado){
  int k, u, v;

  for (k = 0; k < 8 && !encontrado; k++) {
    u = pos_x + ejex[k]; v = pos_y + ejey[k];
    if (u >= 0 && u < N && v >= 0 && v < N) { /* esta dentro de los limites */
      if (tablero[u][v] == 0) {
        tablero[u][v] = i;
        if (i < ncuad)
          mover(tablero,i+1,u,v,encontrado);
        else imprimir_solucion(tablero,encontrado);
        tablero[u][v] = 0;
      }
    }
  }
}
