/*
    Instituto Federal de Minas Gerais
    Campus Formiga - Ciência da Computação
    Jonathan Arantes

    Arquivo: lista.c
*/

#include "lista.h"

// Cria uma nova lista
// retorna null se falhar na alocação da lista
Lista * lista_nova() {
    Lista * lst;
    if(!(lst = (Lista*)malloc(sizeof(Lista))))
        return NULL;
    lst->tam = 0;
    lst->inicio = NULL;
    lst->fim = NULL;
    return lst;
}

// Desaloca uma lista da memória
void lista_destruir(Lista * lst) {
    if(!(lst))
        return;
    unsigned int tam = lst->tam;
    Node * aux = lst->inicio->proximo;
    while(tam--) {
        Node * aux2 = aux->proximo;
        free(aux->valor);
        free(aux);
        aux = aux2;
    }
    free(lst);
    return;
}

// Insere um item no início da lista
// retorna null se falhar na alocação do node
Node * lista_ipush(Lista * lst, TIPO * item) {
    Node * node;
    if(!(node = (Node*)malloc(sizeof(Node))))
        return NULL;
    node->valor = item;
    node->anterior = NULL;
    node->proximo = lst->inicio;
    node->proximo->anterior = node;
    lst->inicio = node;
    return node;    
}

// Remove um item do início da lista
// retorna null caso a lista esteja vazia
Node * lista_ipop(Lista * lst) {
    if(!(lst->inicio))
        return NULL;
    Node * node = lst->inicio;
    lst->inicio = node->proximo;
    lst->inicio->anterior = NULL;
    node->proximo = NULL;
    return node;
}