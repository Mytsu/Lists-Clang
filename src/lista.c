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
    if(!lst)
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
    if(lst->tam) {
        node->proximo = lst->inicio;        
        node->anterior = NULL;
        lst->inicio->anterior = node;
        lst->inicio = node;
    } else {
        lst->inicio = lst->fim = node;
    }
    lst->tam++;
    return node;    
}

// Remove um item do início da lista
// retorna null caso a lista esteja vazia
Node * lista_ipop(Lista * lst) {
    if(!lst->tam)
        return NULL;
    Node * node = lst->inicio;
    if(--lst->tam) {
        (lst->inicio = node->proximo)->anterior = NULL;
    } else {
        lst->inicio = lst->fim = NULL;
    }
    node->anterior = node->proximo = NULL;
    return node;
}

// Insere um item no fim da lista
// retorna NULL se falhar na alocação do node
Node * lista_fpush(Lista * lst, TIPO * item) {
    Node * node;
    if(!(node = (Node*)malloc(sizeof(Node))))
        return NULL;
    node->valor = item;
    if(lst->tam) {
        node->anterior = lst->fim;        
        node->proximo = NULL;
        lst->fim->proximo = node;
        lst->fim = node;
    } else {
        lst->fim = lst->inicio = node;
    }
    lst->tam++;
    return node;   
}

// Remove um item do fim da lista
// retorna null caso a lista esteja vazia
Node * lista_fpop(Lista * lst) {
    if(!lst->tam)
        return NULL;
    Node * node = lst->fim;
    if(--lst->tam) {
        (lst->fim = node->anterior)->proximo = NULL;
    } else {
        lst->inicio = lst->fim = NULL;
    }
    node->anterior = node->proximo = NULL;
    return node;
}

// Busca um item na lista
// retorna null caso seja uma lista vazia ou
// item não encontrado
Node * lista_buscar(Lista * lst, TIPO * item) {
    if(!lst->tam)
        return NULL;
    unsigned int tam = lst->tam;
    Node * aux = lst->inicio;
    while(--tam) {
        if(aux->valor == item)
            return aux;
        else
            aux = aux->proximo;
    }
    return NULL;
}

// Busca um node na lista baseado no index entregue
// retorna null caso seja uma lista vazia ou
// index de valor maior que o tamanho da lista
Node * lista_encontrar(Lista * lst, unsigned int index) {
    if(!lst->tam)
        return NULL;
    unsigned int tam = lst->tam;
    Node * aux = lst->inicio;
    if(index < tam) {
        while(index--) aux = aux->proximo;
        return aux;
    }
    return NULL;
}

// Busca um node na lista baseado no index entregue e
// altera seu valor usando o item entregue,
// retorna null caso seja uma lista vazia ou index
// de valor maior que o tamanho da lista
Node * lista_alterar(Lista * lst, unsigned int index,
     TIPO * item) {
    if(!lst->tam)
        return NULL;
    unsigned int tam = lst->tam;
    Node * aux = lst->inicio;
    if(index < tam) {
        while(index--) aux = aux->proximo;
        free(aux->valor);
        aux->valor = item;
        return aux;
    }
    return NULL;
}

// Busca um node na lista baseado no index entregue e
// insere um novo node em seu lugar, movendo o node de 
// index antigo para frente, retorna null caso seja uma
// lista vazia ou index de valor maior que a lista
Node * lista_inserir(Lista * lst, unsigned int index,
     TIPO * item) {
    if(!lst->tam)
        return NULL;
    Node * novo = (Node*)malloc(sizeof(Node));
    novo->valor = item;
    novo->anterior = novo->proximo = NULL;
    unsigned int tam = lst->tam;
    Node * aux = lst->inicio;
    if(index < tam) {
        while(index--) aux = aux->proximo;
        novo->proximo = aux;
        novo->anterior = aux->anterior;
        aux->anterior = novo;
        lst->tam++;
        return novo;
    }
    return NULL;
}

// Remove um node da lista baseado no ponteiro do node
// entregue, o node removido tem seus valores de anterior
// e proximo nulos mas não é liberado da memoria
// retorna null caso seja uma lista vazia
Node * lista_remover(Lista * lst, Node * node) {
    if(!lst->tam) 
        return NULL;
    unsigned int tam = lst->tam;
    Node * aux = lst->inicio;
    while(--tam) {
        if(!(aux == node))
            aux = aux->proximo;
        else {
            Node * rm = aux;
            (aux = aux->anterior)->proximo = rm->proximo;
            rm->anterior = rm->proximo = NULL;
            lst->tam--;
            return rm;
        }
    }
    return NULL;
}