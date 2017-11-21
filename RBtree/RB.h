#ifndef RB_H_INCLUDED
#define RB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>




struct RBnodo {
  int key;
  int red; /* se red=0 então o nodo é preto */
  struct RBnodo* esq;
  struct RBnodo* dir;
  struct RBnodo* pai;
};

typedef struct  RBnodo RBtree;

// declarar o nodo NULL
static RBtree* NodoNULL = NULL;



// Definições das Funções
RBtree* RotacaoSimplesEsq(RBtree* t);
RBtree* RotacaoSimplesDir(RBtree* t);
RBtree* VerificaRB(RBtree* t, int key);
RBtree* Insere(RBtree* t, int key);
int Consulta(int X, RBtree* T );
RBtree* Maior(RBtree* t);
RBtree* Menor(RBtree* t);
RBtree* Remove(RBtree* t, int key);
//void Destroi(RBtree* t);
void Desenha(RBtree* t , int nivel);




#endif // RB_H_INCLUDED
