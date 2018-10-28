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

    void inserirInicioLista(int valor){

        No* aux = new No(valor);

        if( estaVazia() ){

            inicio = aux;
            fim = aux;
            fim->setProximo(NULL);

        }else{

            aux->setProximo(inicio);
            inicio = aux;

        }

    }

    void inserirFimLista(int valor){

        No* aux = new No(valor);

        if( estaVazia() ){

            inicio = aux;
            fim = aux;
            fim->setProximo(NULL);

        }else{

            fim->setProximo(aux);
            fim = aux;
            fim->setProximo(NULL);

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

    l.inserirInicioLista(1);
    l.inserirFimLista(2);
    l.inserirInicioLista(3);
    l.inserirFimLista(4);
    l.inserirFimLista(4);

    l.consultarTodaLista();

    l.removerElementoLista(4);

    l.consultarTodaLista();

    return 0;
}
