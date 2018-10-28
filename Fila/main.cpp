#include <iostream>

using namespace std;

// classe No
class No{

private:
	int valor;
	No* proximo;
public:
	No(int valor) // construtor
	{
		this->valor = valor;
		this->proximo = NULL;
	}

	int getValor() // obtém o valor
	{
		return valor;
	}

	No* getProximo() // obtém o próximo No
	{
		return proximo;
	}

	void setproximo(No* p) // seta o próximo No
	{
		proximo = p;
	}
};

// classe Lista
class Lista{
private:
	No* inicio; // primeiro elemento
	No* fim; // último elemento

public:
	Lista(){

		// se não passar um valor, então inicio e fim apontam NULL
		inicio = NULL;
		fim = NULL;
	}

	Lista(int valor){

		// se passar um valor, então cria novo Nó
		inicio = new No(valor);
		fim = inicio;
	}

	virtual ~Lista(){ // destrutor

		delete inicio;
	}

	void mostrar(){ // mostra todos os elementos da lista

		cout << "\nImprimindo todos os elementos...\n";
		No* aux = inicio;

		if(estaVazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(aux) // percorre a lista
			{
				cout << aux->getValor() << endl;
				aux = aux->getProximo();
			}
			cout << endl;
		}
	}

	bool estaVazia() // verifica se a lista está estaVazia
	{
		return (inicio == NULL);
	}

	// insere no final (semelhante a push_back da list)
	void inserir_final(int valor){

		No* aux = new No(valor);

		if(estaVazia())
		{
			inicio = aux;
			fim = aux;
		}
		else
		{
			fim->setproximo(aux);
			fim = aux;
		}
	}

	// retorna o tamanho da lista
	int tamanho(){
		if(estaVazia()) // se for estaVazia, entã retorna 0
			return 0;

		No* aux = inicio;
		int tam = 0;

		// percorre a lista
		do{
			aux = aux->getProximo();
			tam++;
		}
		while(aux);

		return tam;
	}

	// verifica se um elemento existe na lista
	bool existe(int valor)
	{
		No* aux = inicio;

		while(aux != NULL)
		{
			if(aux->getValor() == valor)
				return true;
			aux = aux->getProximo();
		}
		return false;
	}

	// remove da lista, remoção do final (semelhante a pop_back da list)
	void remover()
	{
		if(!estaVazia())
		{
			// se houver só 1 elemento
			if(inicio->getProximo() == NULL)
				inicio = NULL;
			else if(inicio->getProximo()->getProximo() == NULL) // 2 elementos
				inicio->setproximo(NULL);
			else // > 2 elementos
			{
				No* ant_ant = inicio;
				No* ant = inicio->getProximo();
				No* corrente = inicio->getProximo()->getProximo();

				while(corrente)
				{
					No* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->getProximo();
				}
				delete ant_ant->getProximo(); // libera memória
				ant_ant->setproximo(NULL); // seta o proximo como NULL
				fim = ant_ant; // atualiza a fim
			}
		}
	}

	void removerInicio(){

        if( estaVazia() ){
            cout << "Lista esta vazia" << endl;
        }else{
            No* aux = inicio;
            inicio = inicio->getProximo();
            delete(aux);
        }

	}


};

int main(int argc, char *argv[])
{
	Lista l;

	if(l.estaVazia())
		cout << "Lista estaVazia!!\n";
	else
		cout << "Lista NAO estaVazia!!\n";

	l.mostrar();

	if(l.existe(10))
		cout << "\nO elemento 10 existe na lista!!\n";
	else
		cout << "\nO elemento 10 NAO existe na lista!!\n";

	l.inserir_final(10);
	l.inserir_final(20);
	l.inserir_final(30);
	l.inserir_final(40);

	l.mostrar();

	if(l.estaVazia())
		cout << "Lista estaVazia!!\n";
	else
		cout << "Lista NAO estaVazia!!\n";

	if(l.existe(10))
		cout << "\nO elemento 10 existe na lista!!\n";
	else
		cout << "\nO elemento 10 NAO existe na lista!!\n";

	//l.remover();

	l.removerInicio();

	l.mostrar();

	cout << "Tamanho da lista: " << l.tamanho() << endl;

	return 0;
}
