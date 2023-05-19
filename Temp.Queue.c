#include "Temperatura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


node* new_node_queue(t_elem value){
    node *n=(node*)malloc(sizeof(node));
    if(n!=NULL){
        n->value=value;
        n->next=NULL;
    }
    return n;
}

cola* queue_new (int maxsize){
    cola *q=(cola*)malloc(sizeof(cola));
    q->head=NULL;
    q->tail=NULL;
    q->max_size=maxsize;
    q->count=0;
    return q;
}
void queue_free(cola* q){
    node* current=q->head;
    node* next;
    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }
}
int queue_getmaxsize(cola *q){
    return q->count;
}

void enqueue (cola* q,t_elem elem){
    node* new_n=new_node_queue(elem);
    if(queue_getmaxsize(q)==0){
        q->head=new_n;
        q->tail=new_n;
    }else{
        node* prev=q->tail;
        q->tail=new_n;
        prev->next=q->tail;
    }
    q->count++;
}

t_elem dequeue(cola *q){
    node* aux;
    if(queue_getmaxsize(q)==1){
        aux=q->head;
        q->head=NULL;
        q->tail=NULL;
    }else{
        aux=q->head;
        q->head=aux->next;
    }
    q->count--;
    return aux->value;
}

t_elem peek(cola* q) {
  return q->head->value;
}

void queue_print(cola *q){
    node *act=q->head;
    while(act!=NULL){
        print_reading(&act->value);
        act=act->next;
   }
}

