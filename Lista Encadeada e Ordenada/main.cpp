#include <iostream>

using namespace std;

class No{

private:
    int valor;
    No* proximo;

public:
    No(int valor){
        this->valor = valor;
        this->proximo = NULL;
    }

    int getValor(){
        return valor;
    }

    No* getProximo(){
        return proximo;
    }

    void setProximo( No* p ){
        proximo = p;
    }

};

class Lista{

private:
    No* inicio;
    No* fim;
    No* anterior;

public:
    Lista(){

		inicio = NULL;
		fim = NULL;
		anterior = NULL;
	}

    bool estaVazia(){

        return (inicio == NULL);

    }

    void inserirLista(int valor){

        No* novo = new No(valor);

        if( estaVazia() ){

            // Esse será o primeiro elemento da lista

            inicio = novo;
            fim = novo;
            novo->setProximo(NULL);

        }else{

            // Lista já contém elementos
            // Será inserido na ordem crescente

            anterior = NULL;
            No* aux2 = inicio;

            while( aux2 != NULL && novo->getValor() > aux2->getValor() ){

                anterior = aux2;
                aux2 = aux2->getProximo();

            }

            if( anterior == NULL ){

                // O número que será inserido é menor que todos os elementos
                novo->setProximo(inicio);
                inicio = novo;

            }else if( aux2 == NULL ){

                // O número é maior que todos os elementos da lista
                fim->setProximo(novo);
                fim = novo;
                fim->setProximo(NULL);

            }else{

                // O número a ser inserido está entre dois outros
                anterior->setProximo(novo);
                novo->setProximo(aux2);

            }

            cout << "Numero inserido na lista" << endl;

        }

    }

    void consultarTodaLista(){

        if( estaVazia() ){

            cout << "Lista vazia" << endl;

        }else{

            cout << "Consultando toda a lista" << endl;

            No* aux = inicio;

            while( aux != NULL ){

                cout << aux->getValor() << endl;

                aux = aux->getProximo();

            }

        }

    }

    void removerElementoLista(int numero){

        if( estaVazia() ){

            cout << "Lista vazia" << endl;

        }else{

            No* aux = inicio;

            anterior = NULL;

            int achou = 0;

            while( aux != NULL ){
                if( aux->getValor() == numero ){
                    achou = achou + 1;

                    if( aux == inicio ){

                        inicio = aux->getProximo();
                        delete(aux);
                        aux = inicio;

                    }else if( aux == fim ){

                        anterior->setProximo(NULL);
                        fim = anterior;
                        delete(aux);
                        aux = NULL;

                    }else{

                        anterior->setProximo(aux->getProximo());
                        delete(aux);
                        aux = anterior->getProximo();

                    }

                }else{

                    anterior = aux;
                    aux = aux->getProximo();

                }
            }

            if( achou == 0 ){
                    cout << "Numero nao encontrado" << endl;
                }else if( achou == 1 ){
                    cout << "Numero removido 1 vez" << endl;
                }else{
                    cout << "Numero removido " << achou << " vezes" << endl;
                }

        }

    }

    void esvaziarLista(){

        if( inicio == NULL ){
            cout << "Lista vazia" << endl;
        }else{

            No* aux = inicio;

            while( aux != NULL ){

                inicio = inicio->getProximo();
                delete(aux);
                aux = inicio;

            }

            cout << "Lista foi esvaziada" << endl;

        }

    }

};

int main()
{
    Lista l;

    l.inserirLista(3);
    l.inserirLista(1);
    l.inserirLista(2);
    l.inserirLista(6);

    l.consultarTodaLista();

    l.removerElementoLista(3);

    l.consultarTodaLista();

    return 0;
}
