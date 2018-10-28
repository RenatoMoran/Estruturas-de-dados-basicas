#include <iostream>

using namespace std;

int main()
{
    int X[5], n, i, aux, troca;

    // Carregando os números no vetor X:

    cout << "Digite 5 numeros" << endl;

    for( i = 0 ; i < 5 ; i++ ){
        cin >> X[i];
    }

    cout << "\nVetor antes da ordenacao com o bubble sort!" << endl;

    for( i = 0 ; i < 5 ; i++ ){
        cout << X[i] << " ";
    }

    n = 1;

    troca = 1;

    while( n <= 5 && troca == 1 ){

        troca = 0;

        for( i = 0 ; i <= 3 ; i++ ){

            if( X[i] > X[i+1] ){

                troca = 1;
                aux = X[i];
                X[i] = X[i+1];
                X[i+1] = aux;

            }

        }

        n = n + 1;

    }

    cout << "\nVetor ordenado com o bubble sort!" << endl;

    for( i = 0 ; i < 5 ; i++ ){
        cout << X[i] << " ";
    }

    return 0;
}
