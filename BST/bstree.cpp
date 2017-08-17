#include <stdlib.h>
#include <stdio.h>


struct node{
	int key;  					//chave de identificação do nodo	
	node * left, * right;		//ponteiros para os filhos
};




//busca por uma chave k na árvore com raiz r
//caso a chave não estiver na árvore retorna NULL

node * search (node * r, int key);

//mostra todas as chaves da árvore

void * print (node * r);

//insere um nodo com chave key na árvore com raiz r
//retorna um ponteiro para a raiz da árvore

node * insert (node * r, int key);

//remove o nodo da árvore com raiz r que possui chave igual a key
//(lembra que tem que dar free no nodo)
void remove (node * r, int key);



int main ( void ){
	return 0;
}





