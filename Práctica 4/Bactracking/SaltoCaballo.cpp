#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NO_CASILLAS_DISPONIBLES 0
#define MAX_SOLUCIONES 10

void inicializarTablero(char **tablero,int n);
int insertarCaballos(char **tablero,int fila,int columna,int casillasDisponibles,int numCaballos,int n);
int verificarMovimientos(char **tablero,int fila,int columna,int casillasDisponibles,int n);
void imprimirTablero(char **tablero,int n);

int main()
{
    int n,i,j,fila,columna,numCaballos = 0,totalCaballos,casillasDisponibles;
    char **tablero;
    srand(time(NULL));
    do
    {
        printf("Dame tamanio de tablero: ");
        scanf("%d",&n);
    }while(n < 2 || n > 20);
    tablero = (char**)malloc(n*sizeof(char*));
    for(i = 0;i < n;i++)
        tablero[i] = (char*)malloc(n*sizeof(char));
    casillasDisponibles = n*n;
    fila = rand() % n;
    columna = rand() % n;
    printf("(%d,%d)\n",fila,columna);
    inicializarTablero(tablero,n);
    totalCaballos = insertarCaballos(tablero,fila,columna,casillasDisponibles,numCaballos,n);
    printf("\n\nEl numero maximo de caballos en esta solucion es de %d",totalCaballos);
    return 0;
}

void inicializarTablero(char **tablero,int n)
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
           tablero[i][j] = '0';
    }
}

int insertarCaballos(char **tablero,int fila,int columna,int casillasDisponibles,int numCaballos,int n)
{
    if(casillasDisponibles > NO_CASILLAS_DISPONIBLES)
    {
        if(tablero[fila][columna] == '0')
        {
            tablero[fila][columna] = 'C';
            casillasDisponibles = verificarMovimientos(tablero,fila,columna,casillasDisponibles,n);
            imprimirTablero(tablero,n);
            numCaballos++;
            fila = rand() % n;
            columna = rand() %n;
            insertarCaballos(tablero,fila,columna,casillasDisponibles,numCaballos,n);
        }
        else
        {
            fila = rand() % n;
            columna = rand() %n;
            insertarCaballos(tablero,fila,columna,casillasDisponibles,numCaballos,n);
        }
    }
    else
       return numCaballos;
}

int verificarMovimientos(char **tablero,int fila,int columna,int casillasDisponibles,int n)
{
    int i,j,nuevaFila,nuevaColumna,eliminadas;
    eliminadas = casillasDisponibles-1;
    nuevaFila = fila + 2;
    nuevaColumna = columna -1;
    if((nuevaFila>=0&&nuevaFila<n)&&(nuevaColumna>=0&&nuevaColumna<n)&&(tablero[nuevaFila][nuevaColumna]=='0'))
    {
        tablero[nuevaFila][nuevaColumna] = 'x';
        eliminadas--;
    }
    nuevaFila = fila + 2;
    nuevaColumna = columna + 1;
    if((nuevaFila>=0&&nuevaFila<n)&&(nuevaColumna>=0&&nuevaColumna<n)&&(tablero[nuevaFila][nuevaColumna]=='0'))
    {
        tablero[nuevaFila][nuevaColumna] = 'x';
        eliminadas--;
    }
    nuevaFila = fila + 1;
    nuevaColumna = columna - 2;
    if((nuevaFila>=0&&nuevaFila<n)&&(nuevaColumna>=0&&nuevaColumna<n)&&(tablero[nuevaFila][nuevaColumna]=='0'))
    {
        tablero[nuevaFila][nuevaColumna] = 'x';
        eliminadas--;
    }
    nuevaFila = fila + 1;
    nuevaColumna = columna + 2;
    if((nuevaFila>=0&&nuevaFila<n)&&(nuevaColumna>=0&&nuevaColumna<n)&&(tablero[nuevaFila][nuevaColumna]=='0'))
    {
        tablero[nuevaFila][nuevaColumna] = 'x';
        eliminadas--;
    }
    nuevaFila = fila - 2;
    nuevaColumna = columna - 1;
    if((nuevaFila>=0&&nuevaFila<n)&&(nuevaColumna>=0&&nuevaColumna<n)&&(tablero[nuevaFila][nuevaColumna]=='0'))
    {
        tablero[nuevaFila][nuevaColumna] = 'x';
        eliminadas--;
    }
    nuevaFila = fila - 2;
    nuevaColumna = columna + 1;
    if((nuevaFila>=0&&nuevaFila<n)&&(nuevaColumna>=0&&nuevaColumna<n)&&(tablero[nuevaFila][nuevaColumna]=='0'))
    {
        tablero[nuevaFila][nuevaColumna] = 'x';
        eliminadas--;
    }
    nuevaFila = fila - 1;
    nuevaColumna = columna - 2;
    if((nuevaFila>=0&&nuevaFila<n)&&(nuevaColumna>=0&&nuevaColumna<n)&&(tablero[nuevaFila][nuevaColumna]=='0'))
    {
        tablero[nuevaFila][nuevaColumna] = 'x';
        eliminadas--;
    }
    nuevaFila = fila - 1;
    nuevaColumna = columna + 2;
    if((nuevaFila>=0&&nuevaFila<n)&&(nuevaColumna>=0&&nuevaColumna<n)&&(tablero[nuevaFila][nuevaColumna]=='0'))
    {
        tablero[nuevaFila][nuevaColumna] = 'x';
        eliminadas--;
    }
    return eliminadas;
 }

 void imprimirTablero(char **tablero,int n)
 {
     int i,j;
     for(i = 0;i < n;i++)
     {
         printf("\n");
         for(j = 0;j < n;j++)
            printf("[%c]",tablero[i][j]);
     }
     printf("\n");
 }
