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

// Versão do código
#define VERSAO_LISTA "0.1"
// Tipo de dado armazenado na lista
#define TIPO int

typedef struct node {
    TIPO * valor;
    struct node * anterior;
    struct node * proximo;
} Node;

typedef struct lista {
    unsigned int tam;
    struct node * inicio;
    struct node * fim;
} Lista;

// Prototipos de node

Node * lista_novo_node(TIPO * valor);

void lista_destruir_node(Node * node);

// Prototipos de lista

Lista * lista_nova();

void lista_destruir(Lista * lst);

Node * lista_ipush(Lista * lst, TIPO * item);

Node * lista_ipop(Lista * lst);

Node * lista_fpush(Lista * lst, TIPO * item);

Node * lista_fpop(Lista * lst);

Node * lista_buscar(Lista * lst, TIPO * item);

Node * lista_encontrar(Lista * lst, unsigned int index);

Node * lista_alterar(Lista * lst, unsigned int index,
    TIPO * item);

Node * lista_inserir(Lista * lst, TIPO * item);

Node * lista_remover(Lista * lst, Node * node);

#ifdef __cplusplus
}
#endif

#endif /* LISTA_H */