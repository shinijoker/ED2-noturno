#include <stdio.h>
#include <stdlib.h>
#define BLACK true
#define RED false

typedef struct no{
	struct no *esq;
	struct no *dir;
	struct no *pai;
	int valor;	
	bool cor;
}no;

typedef struct tree{
	struct no* raiz;
	struct no* nill;
}tree;

tree* criarArvore();
no *buscar (tree *arvore, no *nodo, int elemento);
void inserirArvore (tree *arvore, int elemento);
void inserirNo (tree *arvore, no **raiz, int elemento);
void arrumarArvore (tree *arvore, no *nodo);
void preorder(no *nodo, no *nill);
void inorder(no *nodo, no *nill);
void posorder(no *nodo, no *nill);
no* removerNo(tree *arvore, no *raiz, int elemento);
void arrumarArvoreRemocao(tree *arvore, no *nodo);
no* minimo (tree *arvore, no *nodo);
no* sucessor(tree *arvore, no *nodo);
void rotacaoEsquerda(tree *arvore, no *nodo);
void rotacaoDireita(tree *arvore, no *nodo);

int main(){
	tree *arvore = criarArvore();
	tree *aux = arvore;
	no* nodo;
	int x=1,y;
	while(x!=0){
		printf("-------ARVORE VERMELHA E PRETA----------------\n");
		printf("0 SAIR\n");
		printf("1 INSERIR\n");
		printf("2 DELETAR\n");
		printf("3 BUSCAR\n");
		printf("4 IMPRIMIR\n");	
		printf("---------------------------------------------\n");
		scanf("%d",&x);
		
		if(x==0){
			break;
		}
		if(x==1){
			printf("Informe o elemento para Insercao: \n");
			scanf("%d",&y);
			inserirArvore (arvore, y);
		}
		if(x==2){
			printf("Informe o elemento para Delecao: \n");
			scanf("%d",&y);
			nodo = removerNo(arvore, arvore->raiz, y);
		}
		if(x==3){
			if(arvore == aux){
				printf("\nArvore Vazia! \n\n");
			}else{
				printf("Informe o elemento para Busca: \n");
				scanf("%d",&y);
				nodo = buscar(arvore,arvore->raiz, y);
				printf("Elemento: %d \n", nodo->valor);
				if(nodo->cor == BLACK){
					printf("Cor: Preto \n");
				}else{
					printf("Cor: Vermelho \n");
				}
			}			
		}
		if(x==4){
			printf("-------INFORME FORMA DE IMPRESSAO------------\n");
			printf("0 SAIR\n");
			printf("1 PRE ORDER\n");
			printf("2 IN ORDER\n");
			printf("3 POS ORDER\n");	
			printf("---------------------------------------------\n");
			scanf("%d",&x);
			if(x==1){
				preorder(arvore->raiz, arvore->nill);	
			}
			if(x==2){
				inorder(arvore->raiz, arvore->nill);
			}
			if(x==3){
				posorder(arvore->raiz, arvore->nill);
			}
		}	
	}
	return 0;	
}

tree* criarArvore(){
	tree *arvore = (tree*) malloc (sizeof(tree));
	arvore->nill = (no*) malloc (sizeof(no));
	arvore->nill->dir = NULL;
	arvore->nill->esq = NULL;
	arvore->nill->pai = NULL;
	arvore->nill->cor = BLACK;
	arvore->raiz = arvore->nill;
	return arvore;
}

no *buscar (tree *arvore, no *nodo, int elemento){
	if(nodo == arvore->nill || nodo->valor== elemento){
		return nodo;
	}
	if(elemento <= nodo->valor){
		return buscar (arvore, nodo->esq, elemento);
	}
	return buscar(arvore, nodo->dir, elemento);
}

void inserirArvore (tree *arvore, int elemento){
	no *aux = (no*)malloc(sizeof(no));
	aux->valor = elemento;
	aux->cor = false;
	aux->dir = arvore->nill;
	aux->esq = arvore->nill;
	aux->pai = arvore->nill;
	
	if(arvore->raiz == arvore->nill){
		aux->cor=true;
		arvore->raiz = aux;
		return;
	}else{
		inserirNo(arvore, &arvore->raiz, elemento);
		return;
	}
}

void inserirNo (tree *arvore, no **raiz, int elemento){
	if((*raiz)->dir == arvore->nill && (*raiz)->dir == arvore->nill){
		no *aux = (no*)malloc(sizeof(no));
		aux->valor = elemento;
		aux->cor = false;
		aux->dir = arvore->nill;
		aux->esq = arvore->nill;
		aux->pai = *raiz;
		if(elemento < (*raiz)->valor){
			(*raiz)->esq = aux;
		}else{
			(*raiz)->dir = aux;
		}
		arrumarArvore(arvore, aux);
		return;
	}
	if(elemento < (*raiz)->valor){
		inserirNo(arvore, &(*raiz)->esq,elemento);
		return;
	}
	if(elemento > (*raiz)->valor){
		inserirNo(arvore, &(*raiz)->dir,elemento);
		return;
	}	
	printf("Elemento %d já existe. \n",elemento);
	return;
}

void arrumarArvore (tree *arvore, no *nodo){
	no *aux = (no*)malloc(sizeof(no));
	
	while(nodo->pai->cor == RED){
		if(nodo->pai == nodo->pai->pai->esq){
			aux = nodo->pai->pai->dir;
			if(aux->cor == RED){
				nodo->pai->cor = BLACK;
				aux->cor = BLACK;
				nodo->pai->pai->cor = RED;
				nodo = nodo->pai->pai;
			}else{
				if(nodo == nodo->pai->dir){
					nodo = nodo->pai;
					rotacaoEsquerda(arvore,nodo);
					nodo->pai->cor = BLACK;
					nodo->pai->pai->cor = RED;
					rotacaoDireita(arvore,nodo->pai->pai);
				}else{
					nodo = nodo->pai;
					rotacaoDireita(arvore, nodo);
				}
			}
		}else{
			aux = nodo->pai->pai->esq;
			if(aux->cor == RED){
				nodo->pai->cor = BLACK;
				aux->cor = BLACK;
				nodo->pai->pai->cor = RED;
				nodo = nodo->pai->pai;
			}else{
				if(nodo == nodo->pai->esq){
					nodo = nodo->pai;
					rotacaoDireita(arvore, nodo);
					nodo->pai->cor = BLACK;
					nodo->pai->pai->cor = RED;
					rotacaoEsquerda(arvore,nodo->pai->pai);
				}else{
					nodo = nodo->pai;
					rotacaoEsquerda(arvore,nodo);
				}
			}	
		}		
	}
	arvore->raiz->cor = BLACK;
	return;
}

void preorder(no *nodo, no *nill){
	if(nodo != nill){
		if(nodo->cor == RED){
			printf("VERMELHO - ");
		}else{
			printf("PRETO - ");
		}
		printf("%d \n",nodo->valor);
		preorder(nodo->esq, nill);
		preorder(nodo->dir, nill);
		return;
	}
}

void inorder(no *nodo, no *nill){
	if(nodo != nill){
		inorder(nodo->esq, nill);
		if(nodo->cor == RED){
			printf("VERMELHO - ");
		}else{
			printf("PRETO - ");
		}
		printf("%d \n",nodo->valor);
		inorder(nodo->dir, nill);
	}
}

void posorder(no *nodo, no *nill){
	if(nodo != nill){
		posorder(nodo->esq, nill);
		posorder(nodo->dir, nill);
		if(nodo->cor == RED){
			printf("VERMELHO - ");
		}else{
			printf("PRETO - ");
		}
		printf("%d \n",nodo->valor);
	}
}

void arrumarArvoreRemocao(tree *arvore, no *nodo){    //Pego funcao pronta, somente adaptado (até fazer a minha)
	no* aux;
	while(nodo != arvore->raiz && nodo->cor == BLACK){
		if (nodo == nodo->pai->esq){
			aux = nodo->pai->dir;
			if(aux->cor == RED){
				aux->cor = BLACK;
				nodo->pai->cor = RED;
				rotacaoEsquerda(arvore, nodo->pai);
				aux = nodo->pai->dir;
			}
			if(aux->esq->cor == BLACK && aux->dir->cor == BLACK){
				aux->cor = RED;
				nodo = nodo->pai;
			}else{
				if(aux->dir->cor == BLACK){
					aux->esq->cor = BLACK;
					aux->cor = RED;
					rotacaoDireita(arvore, aux);
					aux = nodo->pai->dir;
				}else{
					aux->cor = aux->pai->cor;
					nodo->pai->cor = BLACK;
					aux->dir->cor = BLACK;
					rotacaoEsquerda(arvore, nodo->pai);
					nodo = arvore->raiz;
				}	
			}	
		}else{
			aux = nodo->pai->esq;
			if(aux->cor == RED){
				aux->cor = BLACK;
				nodo->pai->cor = RED;
				rotacaoDireita(arvore, nodo->pai);
				aux = nodo->pai->esq;				
			}
			if(aux->dir->cor == BLACK && aux->esq->cor == BLACK){
				aux->cor = RED;
				nodo = nodo->pai;
			}else{
				if(aux->esq->cor == BLACK){
					aux->dir->cor = BLACK;
					aux->cor = RED;
					rotacaoEsquerda(arvore, aux);
					aux = nodo->pai->esq;
				}else{
					aux->cor = aux->pai->cor;
					nodo->pai->cor = BLACK;
					aux->esq->cor = BLACK;
					rotacaoDireita(arvore,nodo->pai);
					nodo = arvore->raiz;
				}
			}
		}
	}
	nodo->cor = BLACK;
	return;
}


no* removerNo(tree *arvore, no *raiz, int elemento){   //Pego funcao pronta, somente adaptado (até fazer a minha)
	no* nodo = buscar(arvore, arvore->raiz, elemento);
	no* y, *x;
	if(nodo == arvore->nill){
		return nodo;
	}
	if(nodo->esq == arvore->nill || nodo->dir == arvore->nill){
		y = nodo;
	}else{
			y = sucessor(arvore, nodo);
	}
	if(y->esq != arvore->nill){
		x = y->esq;
	}else{
		x = y->dir;
	}
	x->pai = y->pai;
	if(y->pai == arvore->nill){
		arvore->raiz = x;
	}else{
		if(y == y->pai->esq){
			y->pai->esq = x;
		}else{
			y->pai->dir = x;
		}
	}
	if(y != nodo){
		nodo->valor = y->valor;
	}
	if(y->cor == BLACK){
		arrumarArvoreRemocao(arvore, x);
	}
	return nodo;
}

no* minimo (tree *arvore, no *nodo){
	no *aux = nodo;
	while (aux->esq != arvore->nill){
		aux = aux->esq;
	}
	return aux;
}

no* sucessor(tree *arvore, no *nodo){
	if(nodo->dir != arvore->nill){
		return minimo(arvore, nodo->dir);
	}
	no* pai = nodo->pai;
	while(pai != arvore->nill && nodo == pai->dir){
		nodo = pai;
		pai = pai->pai;
	}
	return pai;
}

void rotacaoEsquerda(tree *arvore, no *nodo){
	no *aux;
	aux = nodo->dir;
	nodo->dir = aux->esq;
	if(aux->esq != arvore->nill){
		aux->esq->pai = nodo;
	}
	aux->pai = nodo->pai;
	if(nodo->pai == arvore->nill){
		arvore->raiz = aux;
	}else{
		if(nodo == nodo->pai->esq){
			nodo->pai->esq = aux;
		}else{
			nodo->pai->dir = aux;
		}
	}
	aux->esq = nodo;
	nodo->pai = aux;
	return;
}

void rotacaoDireita(tree *arvore, no *nodo){
	no *aux;
	aux = nodo->esq;
	nodo->esq = aux->dir;
	if(aux->dir != arvore->nill){
		aux->dir->pai = nodo;
	}
	aux->pai = nodo->pai;
	if(nodo->pai == arvore->nill){
		arvore->raiz = aux;
	}else{
		if(nodo == nodo->pai->dir){
			nodo->pai->dir = aux;
		}else{
			nodo->pai->esq = aux;
		}
	}
	aux->dir = nodo;
	nodo->pai = aux;
	return;
}
