#include <iostream>

using namespace std;

/*
    Merge sort

    Nesse algoritmo de ordenação é usada a técnica de divisão e conquista.
    É dividido o problema em subproblemas.
    São resolvidos os subproblemas.
    Combinamos as soluções para chegar na solução do problema original.

*/

void intercala(int X[], int inicio, int fim, int meio){

    int poslivre, inicio_vetor1, inicio_vetor2, i;
    int aux[10];
    inicio_vetor1 = inicio;
    inicio_vetor2 = meio+1;
    poslivre = inicio;

    while( inicio_vetor1 <= meio && inicio_vetor2 <= fim ){

        if( X[inicio_vetor1] <= X[inicio_vetor2] ){
            aux[poslivre] = X[inicio_vetor1];
            inicio_vetor1 = inicio_vetor1 + 1;
        }else{
            aux[poslivre] = X[inicio_vetor2];
            inicio_vetor2 = inicio_vetor2 + 1;
        }

        poslivre = poslivre + 1;

    }

    for( i = inicio_vetor1 ; i <= meio ; i++ ){
        aux[poslivre] = X[i];
        poslivre = poslivre + 1;
    }

    for( i = inicio_vetor2 ; i <= fim ; i++ ){
        aux[poslivre] = X[i];
        poslivre = poslivre + 1;
    }

    for( i = inicio ; i <= fim ; i++ ){
        X[i] = aux[i];
    }

}

void mergeAlgoritmo( int X[], int inicio, int fim){

    int meio;

    if( inicio < fim ){
        meio = ( inicio + fim ) / 2;
        mergeAlgoritmo(X,inicio,meio);
        mergeAlgoritmo(X,meio+1,fim);
        intercala(X,inicio,fim,meio);
    }

}

int main()
{

    int X[10];
    int i;

    cout << "Digite 10 numeros" << endl;
    for( i = 0 ; i <= 9 ; i++ ){
        cin >> X[i];
    }

    mergeAlgoritmo(X,0,9);

    cout << "\nVetor ordenado com o merge sort!" << endl;

    for( i = 0 ; i <= 9 ; i++ ){
        cout << X[i] << " ";
    }

    return 0;
}
