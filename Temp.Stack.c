#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "Temperatura.h"

stack* stack_new(){
    stack* s=(stack*)malloc(sizeof(stack));
    if(s!=NULL){
        s->cnt=0;
    }
    return s;
}

void node_free(node *n){
    node *aux=NULL;
    while(n!=NULL){
        aux=n->next;
        free(n);
        n=aux;
    }
}

void stack_free(stack *s){
    node_free(s->n);
    free(s);
}

node* new_node(t_elem value){
    node *n=(node*)malloc(sizeof(node));
    if(n!=NULL){
        n->value=value;
        n->next=NULL;
    }
    return n;
}

void stack_push(stack *s,t_elem value){
    node *new_n=new_node(value);
    if(s->cnt==0){
        s->n=new_n;
    }else{
        node *aux=s->n;
        s->n=new_n;
        s->n->next=aux;
    }
    s->cnt++;
}

bool stack_is_empty(stack *s){
    return list_is_empty(s->n);
}

t_elem stack_pop(stack *s){
    t_elem val=s->n->value;
    if(s->cnt==0){
        s->n=NULL;
    }else{
        s->n=s->n->next;
    }
    s->cnt--;
    return val;
}

t_elem stack_top(stack* s){
    return s->n->value;
}

void stack_print(stack *s,void prt(t_elem*)){
    if (stack_is_empty(s)!=1){
        t_elem e =stack_pop(s);
        prt(&e);
        stack_print(s,prt);
        stack_push(s,e);
    }
}

void list_print(list *n){
    if(n==NULL){
        printf("\n");
    }else{
        printf("Lista: \n");
        stack_print(&n->value,print_reading);
        list_print(n->next);
    }
}

