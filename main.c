#include <stdio.h>
#include <stdlib.h>
#include "Temperatura.h"
#include <time.h>
int main()
{
    srand(time(NULL));
    node *l=create_list_random();

    btn *n=NULL;
    add_tree(l,&n);

    cola* q=queue_new(btn_count(n));
    in_order_(n,enqueue,q);
    queue_print(q);

    if(testing(q)==1){
        printf("\nLos datos estan ordenados correctamente.");
    }else{
        printf("\nLos datos no estan ordenados.");
    }

    Temp_free(l,&n,q);

    return 0;
}


