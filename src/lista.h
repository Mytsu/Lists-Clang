/*
    Instituto Federal de Minas Gerais
    Campus Formiga - Ciência da Computação
    Jonathan Arantes

    Arquivo: lista.h
*/

#ifndef LISTA_H
#define LISTA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#define VERSAO_LISTA "0.1"

typedef struct node {
    void * valor;
    struct node * anterior;
    struct node * proximo;
} Node;

typedef struct lista {
    unsigned int tam;
    struct node * inicio;
    struct node * fim;
} Lista;

// Prototipos de node

Node * lista_novo_node(void * valor);

// Prototipos de lista

Lista * lista_nova();

void lista_destruir(Lista * lst);

Node * lista_ipush(Lista * lst, Node * node);

Node * lista_ipop(Lista * lst);

Node * lista_fpush(Lista * lst, Node * node);

Node * lista_fpop(Lista * lst);

Node * lista_buscar(Lista * lst, void * node);

Node * lista_encontrar(Lista * lst, int index);

void lista_remover(Lista * lst, Node * node);

#ifdef __cplusplus
}
#endif

#endif /* LISTA_H */