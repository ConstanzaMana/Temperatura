#include "Temperatura.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
reading *new_reading(int minute,int temp){
    reading *r=(reading*)malloc(sizeof(reading));
    r->minute=minute;
    r->temperature=temp;
    return r;
}
int get_min(reading *r){
    return r->minute;
}
int get_temp(reading *r){
    return r->temperature;
}
void print_reading(reading *r){
    printf("Minuto: %d Temperatura: %d\n",get_min(r),get_temp(r));
}

//Simula la creación de una pila con distintas lecturas (reading)
void add_reading_random(stack *s){
    for(int i=0;i<10;i++){
        int minute=rand()%1441;
        int temp=rand()%51-10;
        reading *r=new_reading(minute,temp);
        stack_push(s,*r);
    }
}

int cmp_min(reading *r1,reading *r2){
    if(get_min(r1)==get_min(r2)){
        return 0;
    }else if(get_min(r1)>get_min(r2)){
        return 1;
    }else{
        return -1;
    }
}

int cmp_temp(reading *r1,reading *r2){
    if(get_temp(r1)==get_temp(r2)){
        return 0;
    }else if(get_temp(r1)>get_temp(r2)){
        return 1;
    }else{
        return -1;
    }
}
int cmp(t_elem a,t_elem b){
    int result=0;
    result=cmp_min(&a,&b);
    if(result==0){
        result=cmp_temp(&a,&b);
    }
    return result;
}

//Simula el proceso de ensamblado de varias pilas en una lista dinámica enlazada SLL.
void add_stack_random(list **l){
    for(int i=0;i<5;i++){
        stack *s=stack_new();
        add_reading_random(s);
        node_add(l,*s);
    }
}

//Crea una lista
list *create_list_random(){
    stack *s=stack_new();
    add_reading_random(s);
    list *l=new_node_list(*s);
    add_stack_random(&l);
    return l;
}

//Funcion auxiliar de add_tree. Completa el arbol con los elementos de una pila
void insert_tree(stack *s,btn **n){
    if (stack_is_empty(s)!=1){
        t_elem e =stack_pop(s);
        sbt_insert_value(n,&e,cmp);
        insert_tree(s,n);
        stack_push(s,e);
    }
}
 //Crea un arbol cuyo elemento es la estructura “reading”  ordenando por minutos,
 //Si hay 2 lecturas en el mismo minuto desempatan por temperatura quedando primero la menor.
void add_tree(list *l,btn **n){
    stack *s=stack_new();
    int len=list_length(l);
    for(int i=0;i<len;i++){
       s=list_get(l,i);
       insert_tree(s,n);
    }

}

//Crear la Queue recorriendo el árbol in-orden.
void in_order_(btn *n,void btn_do(void* ctx,t_elem e),void* ctx){
    if(!is_empty(n)){
        in_order_(n->left,btn_do,ctx);
        btn_do(ctx,n->value);
        in_order_(n->right,btn_do,ctx);
    }
}

int testing(cola* q){
    t_elem a=dequeue(q);
    int flag=0;
    int i=0;
    while(i<q->count && flag==0){
        if(cmp(a,peek(q))<0){
            enqueue(q,a);
            a=dequeue(q);
            i++;
        }else{
            flag=1;
        }
    }
    if(flag==1){ //Si no esta ordenada tengo que seguir recorriendo la queue para dejar todos los datos como antes
        enqueue(q,a);
        while(i<q->count-1){
            enqueue(q,dequeue(q));
            i++;
        }
        return 0;
    }else{
        return 1;
    }
}

void Temp_free(btn **n,cola *q){
    btn_free(n);
    queue_free(q);
}
