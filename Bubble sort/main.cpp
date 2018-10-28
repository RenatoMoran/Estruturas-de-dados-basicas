#include <iostream>

using namespace std;

int main()
{
    int X[5], n, i, aux;

    // Carregando os números no vetor X:

    cout << "Digite 5 numeros" << endl;

    for( i = 0 ; i < 5 ; i++ ){
        cin >> X[i];
    }

    cout << "\nVetor antes da ordenacao com o bubble sort!" << endl;

    for( i = 0 ; i < 5 ; i++ ){
        cout << X[i] << " ";
    }

    for( n = 1 ; n <= 5 ; n++ ){
        for( i =0 ; i <= 3 ; i++ ){
            if( X[i] > X[i+1] ){
                aux = X[i];
                X[i] = X[i+1];
                X[i+1] = aux;
            }
        }
    }

    cout << "\nVetor ordenado com o bubble sort!" << endl;

    for( i = 0 ; i < 5 ; i++ ){
        cout << X[i] << " ";
    }

    return 0;
}
