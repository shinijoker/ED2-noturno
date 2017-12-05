#include <stdio.h>
#include<stdlib.h>
typedef struct bstN{
	int data;
	struct bstN *dir, *esq;
}bstN;

bstN *novoNodo(int data){
	bstN *novo = malloc(sizeof(bstN));
	novo->data=data;
	novo->dir=NULL;
	novo->esq=NULL;
	return novo;
}
void inserir(bstN **root){
	int data;
	printf("\nDigite o número que você quer inserir: ");
	scanf("%d", &data);
	if(*root==NULL){
		*root=novoNodo(data);
	}else{
		bstN *aux=malloc(sizeof(bstN));
		for(aux=*root;aux!=NULL;){
			if(aux->data>=data){
				if(aux->esq!=NULL)
					aux=aux->esq;
				else{
					aux->esq=novoNodo(data);
					break;
				}
			}else{
				if(aux->dir!=NULL)
					aux=aux->dir;
				else{
					aux->dir=novoNodo(data);
					break;
				}
			}
		}
	}
}
void preOr(bstN *raiz){
	if(raiz==NULL)
		return;
	printf("%d\n",raiz->data);
	preOr(raiz->esq);
	preOr(raiz->dir);
}
void inOr(bstN *raiz){
	if(raiz==NULL)
		return;

	inOr(raiz->esq);
	printf("%d\n",raiz->data);
	inOr(raiz->dir);
}
void postOr(bstN *raiz){
	if(raiz==NULL)
		return;
	postOr(raiz->esq);
	postOr(raiz->dir);
	printf("%d\n",raiz->data);
}
void buscmin(bstN *subt, bstN **achei){
	bstN *achei2=*achei;
	if(subt!=NULL){
		if(achei2->data > subt->data){
			*achei=subt;
			return;
		}
		buscmin(subt->esq,achei);
		buscmin(subt->dir,achei);
	}
}
void busc(bstN *raiz,int data, bstN **achei){
	if(raiz!=NULL){
		if(raiz->data==data){
			*achei=raiz;
			printf("O nodo com o número %d esta na arvore e seu endereço é %d\n", raiz->data,&raiz);
			return;
		}
		busc(raiz->esq,data,achei);
		busc(raiz->dir,data,achei);
}
}


bstN *deletar(bstN *raiz, int data){
	if(raiz==NULL)
		return raiz;
	else if(raiz->data>data)
		raiz->esq=deletar(raiz->esq,data);
	else if(raiz->data<data)
		raiz->dir=deletar(raiz->dir,data);
	else{
			if(raiz->esq == NULL && raiz->dir==NULL){
				free(raiz);
				raiz=NULL;
			}else if(raiz->esq==NULL){
				bstN *aux=raiz;
				raiz=raiz->dir;
				free(aux);
			}else{
				bstN *aux=raiz->dir;
				buscmin(raiz->dir, &aux);
				raiz->data=aux->data;
				raiz->dir=deletar(raiz->dir,aux->data);
			}
	}
	return raiz;
}
int main(){
	bstN *root=NULL;
	bstN *aux=NULL;
	int escolha;

	do {		
		printf("\n 1-Inserir nodo na Árvore\n 2-Deletar nodo da Árvore\n 3-Buscar\n 4-PreOrder\n 5-InOrder\n 6-PostOrder\n 0-Sair\nEscolha sua opção: ");
		scanf("%d",&escolha );
		aux=NULL;
		switch (escolha) {
			case 1:
				inserir(&root);
				break;
			case 2:
				if(root==NULL)
					printf("\nÁrvore vazia\n");
				else{
					printf("\nDigite o conteúdo do nodo que vai ser deletar: ");
					int del;
					scanf("%d",&del);
					deletar(root,del);
				}
				break;

			case 3:
				printf("Digite o número que deseja buscar: ");
				int buscar;
				scanf("%d",&buscar );
				busc(root,buscar,&aux);
				if(aux==NULL)
					printf("Número não esta na arvore\n");
				break;

			case 4:
				if(root==NULL)
					printf("\nÁrvore vazia\n");
				else
					preOr(root);
				break;
			case 5:
				if(root==NULL)
					printf("\nÁrvore vazia\n");
				else
			 		inOr(root);
				break;
			case 6:
				if(root==NULL)
					printf("\nÁrvore vazia\n");
				else
				postOr(root);
				break;
			default:
				break;

		}
	} while(escolha!=0);

	return 0;
}
