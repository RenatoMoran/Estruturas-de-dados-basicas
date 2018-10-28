#include <iostream>

using namespace std;

class No{

private:
    No *esquerda, *direita;
    int chave;

public:
    No(int chave){
        this->chave = chave;
        esquerda = NULL;
        direita = NULL;
    }

    int getChave(){
        return chave;
    }

    No* getEsquerda(){
        return esquerda;
    }

    No* getDireita(){
        return direita;
    }

    void setEsquerda( No* no ){
        esquerda = no;
    }

    void setDireita( No* no ){
        direita = no;
    }

};

class arvore{

private:
    No* raiz;

public:
    arvore(){
        raiz = NULL;
    }

    void inserir(int chave){
        if( raiz == NULL ){
            raiz = new No(chave);
        }else{
            inserirAux(raiz,chave);
        }
    }

    void inserirAux(No* no, int chave){
        if( chave < no->getChave() ){
            if( no->getEsquerda() == NULL ){
                No* novo_no = new No(chave);
                no->setEsquerda(novo_no);
            }else{
                inserirAux(no->getEsquerda(),chave);
            }
        }else if( chave > no->getChave() ){
            if( no->getDireita() == NULL ){
                No* novo_no = new No(chave);
                no->setDireita(novo_no);
            }else{
                inserirAux(no->getDireita(),chave);
            }
        }
    }

    No* getRaiz(){
        return raiz;
    }

    void emOrdem(No* no){
        if( no != NULL ){
            emOrdem(no->getEsquerda());
            cout << no->getChave() << endl;
            emOrdem(no->getDireita());
        }
    }

};

int main()
{
    arvore arv;

    arv.inserir(8);
    arv.inserir(10);
    arv.inserir(14);
    arv.inserir(13);
    arv.inserir(3);
    arv.inserir(1);
    arv.inserir(6);
    arv.inserir(4);
    arv.inserir(7);

    cout << "Vamos percorrer em ordem crescente..." << endl;

    arv.emOrdem(arv.getRaiz());


    return 0;
}
