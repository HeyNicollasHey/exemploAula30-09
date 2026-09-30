#include <iostream>
using namespace std;

struct No{
    int dado;
    No *proximo;
    No *anterior;
};

void inserirNaListaNoInicio(No *&head, int data){

    No *novoNo = new No;

    novoNo -> dado = data;
    novoNo -> anterior = NULL;
    novoNo -> proximo = head;

    if(head != NULL){
        head -> anterior = novoNo;
    }

    head = novoNo;
}


void inserirNaListaNoFinal(No *&head, int data){

    No *novoNo = new No;

    novoNo -> dado = data;
    novoNo -> proximo = NULL;
    novoNo -> anterior = NULL;

    if(head == NULL){
        head = novoNo;
        return;
    }

    No *aux = head;

    while(aux -> proximo != NULL){
        aux = aux -> proximo;
    }

    aux -> proximo = novoNo;
    novoNo -> anterior = aux;
}


void inserirNaPosicao(No *&head, int data, int posicao){

    No *novoNo = new No;

    novoNo -> dado = data;
    novoNo -> proximo = NULL;
    novoNo -> anterior = NULL;

    if(head == NULL){
        head = novoNo;
        return;
    }

    if(posicao == 0){
        novoNo -> proximo = head;
        head -> anterior = novoNo;
        head = novoNo;
        return;
    }

    No *aux = head;

    for(int i = 0; i < posicao - 1; i++){

        if(aux -> proximo != NULL){
            aux = aux -> proximo;
        }
    }

    novoNo -> proximo = aux -> proximo;
    novoNo -> anterior = aux;

    if(aux -> proximo != NULL){
        aux -> proximo -> anterior = novoNo;
    }

    aux -> proximo = novoNo;
}


void removerNoComeco(No *&head){

    if(head == NULL){
        cout << "Nada pra deletar aqui";
        return;
    }

    No *temp = head;

    head = head -> proximo;

    if(head != NULL){
        head -> anterior = NULL;
    }

    delete temp;
}

void printarLista(No *&head){
	
	No * aux = head;
	while(aux -> proximo != NULL){
		cout << " " << aux -> proximo -> dado;
		aux = aux -> proximo;
	}
	cout << " " << endl;
	while(aux -> anterior != NULL){
		cout << " " << aux -> anterior -> dado;
		aux = aux -> anterior;
	}
}

void imprimirListaPerony(No*& head){
	cout << "Imprimindo lista do inicio ao fim" << endl;
	cout << "[" << head -> dado << "]";
	No* atual = head -> proximo;
	while(atual -> proximo != NULL){
		cout << "[" << atual -> dado << "]";
		atual = atual -> proximo;
	}
	cout << "[" << atual -> dado << "]" << endl;
	
	cout << "Imprimindo lista do fim ao inicio" << endl;
	cout << "[" << atual -> dado << "]";
	atual = atual -> anterior;
	while(atual -> anterior != NULL){
		cout << "[" << atual -> dado << "]";
		atual = atual -> anterior;
	}
	cout << "[" << atual -> dado << "]" << endl;
}

void removerNoFinal(No *&head){

    if(head == NULL){
        cout << "Nao tem nada aqui para remover";
        return;
    }

    No *noTemp = head;

    while(noTemp -> proximo != NULL){
        noTemp = noTemp -> proximo;
    }

    if(noTemp -> anterior != NULL){
        noTemp -> anterior -> proximo = NULL;
    }
    else{
        head = NULL;
    }

    delete noTemp;
}

int main(){

    No *head = new No;
    head -> dado = 1;
    head -> proximo = NULL;
    
    inserirNaListaNoInicio(head, 2);

	printarLista(head);
	
	imprimirListaPerony(head);
    return 0;
}