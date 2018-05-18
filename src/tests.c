#include "lista.h"
#include <stdio.h>
typedef struct {
    int id;
} test_struct;

test_struct * new_test(int id) {
    test_struct * ts = (test_struct*)malloc(sizeof(test_struct));
    ts->id = id;
    return ts;
}

int main(void) {
    int max_it = 100;
    int it = 0;
    Lista * lst = lista_nova();
    do {
        lista_fpush(lst, new_test(it));
    } while(++it < max_it);

    /*
    for (int i = 0; i < 10; i++) {
        if(i % 2 == 0)
            free(lista_ipop(lst));
        else
            free(lista_fpop(lst));
    }
    */
    
        Node * n = lista_inicio(lst);
        printf("lista: \n");
        while(n != NULL) {
            test_struct * ts = lista_valor(n);
            printf("%d ", ts->id);
            n = lista_iterador(n, LISTA_FIM);
        }
        printf("\n");

    lista_destruir(lst);

    return 0;
}