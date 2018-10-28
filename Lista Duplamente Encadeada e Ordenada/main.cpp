#include <iostream>

using namespace std;

// Erro testar de novo

class No{

private:
    int valor;
    No* proximo;
    No* anterior;

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

     No* getAnterior(){
        return anterior;
    }

    void setAnterior( No* a ){
        anterior = a;
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

    void inserirElementoLista(int valor){

        No* novo = new No(valor);

        if( estaVazia() ){

            novo->setProximo(NULL);
            novo->setAnterior(NULL);
            inicio = novo;
            fim = novo;

        }else{

            // A lista j� cont�m elementos ent�o faremos uma busca para saber onde vamos incluir ele

            No* aux = inicio;

            while( aux != NULL && novo->getValor() > aux->getValor() ){

                aux = aux->getProximo();

            }

            if( aux == inicio ){

                // N�mero � menor que todos da lista
                // Ser� inserido no inicio

                novo->setProximo(inicio);
                novo->setAnterior(NULL);
                inicio->setAnterior(novo);
                inicio = novo;

            }else if( aux == NULL ){

                // N�mero � maior que todos da lista
                // Ser� inserido no final

                fim->setProximo(novo);
                novo->setAnterior(fim);
                fim = novo;
                fim->setProximo(NULL);

            }else{

                // N�mero est� entre dois valores da lista
                // Ser� inserido entre eles

                novo->setProximo(aux);
                aux->setProximo(novo);
                aux->setAnterior(novo);
                novo->setAnterior(aux->getAnterior());
                aux->setAnterior(novo);

            }

        }

    }

    void consultarTodaListaInicioParaFim(){

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

    void consultarTodaListaFimParaInicio(){

        if( estaVazia() ){

            cout << "Lista vazia" << endl;

        }else{

            cout << "Consultando toda a lista" << endl;

            No* aux = fim;

            while( aux != NULL ){

                cout << aux->getValor() << endl;

                aux = aux->getAnterior();

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

    l.inserirElementoLista(3);
    l.inserirElementoLista(4);
    l.inserirElementoLista(1);
    l.inserirElementoLista(2);

    l.consultarTodaListaInicioParaFim();

    /*
    l.consultarTodaListaInicioParaFim();

    l.consultarTodaListaFimParaInicio();

    l.removerElementoLista(4);

    l.consultarTodaListaInicioParaFim();
    */

    return 0;
}
