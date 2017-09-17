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

void preOrder(bstN *root){
	if(root==NULL)
		return;
	printf("%d\n",root->data);
	preOrder(root->esq);
	preOrder(root->dir);
}
void inOrder(bstN *root){
	if(root==NULL)
		return;

	inOrder(root->esq);
	printf("%d\n",root->data);
	inOrder(root->dir);
}
void postOrder(bstN *root){
	if(root==NULL)
		return;
	postOrder(root->esq);
	postOrder(root->dir);
	printf("%d\n",root->data);
}
void insere(bstN **root){
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
void buscmin(bstN *subt, bstN **essa){
	bstN *essa2=*essa;
	if(subt!=NULL){
		if(essa2->data > subt->data){
			*essa=subt;
			return;
		}
		buscmin(subt->esq,essa);
		buscmin(subt->dir,essa);
	}
}
void busc(bstN *root,int data, bstN **essa){
	if(root!=NULL){
		if(root->data==data){
			*essa=root;
			printf("O nodo com o número %d esta na arvore e seu endereço é %d\n", root->data,&root);
			return;
		}
		busc(root->esq,data,essa);
		busc(root->dir,data,essa);
	}
}

bstN *deletar(bstN *root, int data){
	if(root==NULL)
		return root;
	else if(root->data>data)
		root->esq=deletar(root->esq,data);
	else if(root->data<data)
		root->dir=deletar(root->dir,data);
	else{
			if(root->esq == NULL && root->dir==NULL){
				free(root);
				root=NULL;
			}else if(root->esq==NULL){
				bstN *aux=root;
				root=root->dir;
				free(aux);
			}else{
				bstN *aux=root->dir;
				buscmin(root->dir, &aux);
				root->data=aux->data;
				root->dir=deletar(root->dir,aux->data);
			}
	}
	return root;
}

int main(){
	bstN *root=NULL;
	bstN *aux=NULL;
	int escolha;

	do {		
		printf("\n 1-Inserir nodo na Árvore\n 2-Deletar nodo da Árvore\n 3-Buscar\n 4-PreOrder\n 5-InOrder\n 6-PostOrder\n 0-Sair\nEscolha uma opção: ");
		scanf("%d", &escolha);
		aux=NULL;
		switch (escolha) {
			case 1:
				inserir(&root);
				break;
			case 2:
				if(root==NULL)
					printf("\nÁrvore está vazia\n");
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
					printf("Número não está na arvore\n");
				break;

			case 4:
				if(root==NULL)
					printf("\nÁrvore está vazia\n");
				else
					preOrder(root);
				break;
			case 5:
				if(root==NULL)
					printf("\nÁrvore está vazia\n");
				else
			 		inOrder(root);
				break;
			case 6:
				if(root==NULL)
					printf("\nÁrvore está vazia\n");
				else
				postOrder(root);
				break;
			default:
				break;

		}
	} while(escolha!=0);

	return 0;
}
