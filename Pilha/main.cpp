#include <iostream>

using namespace std;

class NO{

private:
    int valor;
    NO *proximo;

public:
    NO(int valor){
        this->valor = valor;
        this->proximo = NULL;
    }

    int getValor() // obtém o valor
	{
		return valor;
	}

	NO* getProximo() // obtém o próximo No
	{
		return proximo;
	}

	void setproximo(NO* p) // seta o próximo No
	{
		proximo = p;
	}

};

class PILHA{

private:
    NO *topo;

public:
    PILHA(){
        topo = NULL;
    }

    PILHA(int valor){
        topo = new NO(valor);
    }

    bool estaVazia(){

        return ( topo == NULL );

    }

    void inserirElementoPilha(int valor){

		NO* aux = new NO(valor);

		aux->setproximo(topo);
        topo = aux;

        cout << "Valor:" << valor << " inserido na pilha" << endl;

	}

	void consultarTodaPilha(){

        if( estaVazia() ){

            cout << "A pilha esta vazia" << endl;

        }else{

            cout << "Consultando toda a pilha" << endl;

            NO* aux = topo;

            while( aux != NULL ){

                cout << aux->getValor() << endl;
                aux = aux->getProximo();

            }

        }
	}

    void removerElementoPilha(){

        if( estaVazia() ){

            cout << "A pilha esta vazia" << endl;

        }else{

            NO* aux = topo;

            cout << "Removendo o elemento: " << aux->getValor() << " do topo" << endl;
            topo = topo->getProximo();
            delete(aux);

        }

    }

    void esvaziarTodaPilha(){

        if( estaVazia() ){

            cout << "A pilha esta vazia" << endl;

        }else{

            NO* aux = topo;

            while( aux != NULL ){

                topo = topo->getProximo();
                delete(aux);
                aux = topo;

            }

            cout << "Pilha esta vazia" << endl;

        }

    }

    int ElementoTopo(){

        return topo->getValor();

    }

};

int main()
{
    PILHA p;

    p.inserirElementoPilha(5);
    p.inserirElementoPilha(4);
    p.inserirElementoPilha(3);
    p.inserirElementoPilha(2);
    p.inserirElementoPilha(1);

    cout << "Topo da pilha: " << p.ElementoTopo() << endl;

    cout << endl;

    p.consultarTodaPilha();

    cout << endl;

    p.removerElementoPilha();

    cout << endl;

    p.consultarTodaPilha();

    cout << endl;

    p.esvaziarTodaPilha();

    cout << endl;

    p.removerElementoPilha();

    return 0;
}
