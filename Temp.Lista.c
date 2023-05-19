#include "Temperatura.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

list* new_node_list(t_elem2 value){
    list *n=(list*)malloc(sizeof(list));
    if(n!=NULL){
        n->value=value;
        n->next=NULL;
    }
    return n;
}

void list_free(node* head){
    node* current=head;
    node* next;
    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }
}

int list_length(list *n){
    int cnt=0;
    while(n!=NULL){
        cnt++;
        n=n->next;
    }
    return cnt;
}

void node_add(list **head, t_elem2 value){
    list **aux=head;
    while(*aux!=NULL){
        aux=&(*aux)->next;
    }
    *aux=new_node_list(value);

}

bool list_is_empty(node *n){
    if(n==NULL){
        return 1;
    }else{
        return 0;
    }
}

t_elem2* list_get(list* head, int index){
    int i=0;
    list* current=head;
    while(i<index && &current->next!=NULL){
        current=current->next;
        i++;
    }
    if(i==index){
        return &current->value;
    }else{
        return NULL;
    }
}
