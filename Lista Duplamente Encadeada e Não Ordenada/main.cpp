#include <iostream>

using namespace std;

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

    void inserirInicioLista(int valor){

        No* aux = new No(valor);

        if( estaVazia() ){

            inicio = aux;
            fim = aux;
            aux->setProximo(NULL);
            aux->setAnterior(NULL);

        }else{

            aux->setProximo(inicio);
            inicio->setAnterior(aux);
            aux->setAnterior(NULL);
            inicio = aux;

        }

    }

    void inserirFimLista(int valor){

        No* aux = new No(valor);

        if( estaVazia() ){

            inicio = aux;
            fim = aux;
            aux->setProximo(NULL);
            aux->setAnterior(NULL);

        }else{

            fim->setProximo(aux);
            aux->setAnterior(fim);
            aux->setProximo(NULL);
            fim->setProximo(aux);

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

    l.inserirInicioLista(3);
    l.inserirInicioLista(4);
    l.inserirInicioLista(1);
    l.inserirInicioLista(2);

    l.consultarTodaListaInicioParaFim();

    l.consultarTodaListaFimParaInicio();

    l.removerElementoLista(4);

    l.consultarTodaListaInicioParaFim();

    return 0;
}
