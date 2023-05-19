#include "Temperatura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

btn* btn_new(t_elem value){
    btn *b=(btn*)malloc(sizeof(btn));
    b->value=value;
    b->left=NULL;
    b->right=NULL;

    return b;
}

void btn_free(btn **n){
    if(n!=NULL){
        if(*n!=NULL){
            btn_free(&(*n)->left);
            btn_free(&(*n)->right);
            free(*n);
            *n=NULL;
        }
    }
}

int is_empty(btn *b){
    if(b==NULL){
        return 1;
    }else{
        return 0;
    }
}

int sbt_insert_node(btn **node, btn *newNode, int cmp(t_elem,t_elem)){
    if(node==NULL){
        return 0;
    }
    if(newNode==NULL){
        return 1;
    }
    if((*node)==NULL){
        *node=newNode;
        return 1;
    }else if(cmp(newNode->value,(*node)->value)<0){
        return sbt_insert_node(&(*node)->left,newNode,cmp);
    }else if(cmp(newNode->value,(*node)->value)>0){
        return sbt_insert_node(&(*node)->right,newNode,cmp);
    }else{
        return 0;
    }
}

int sbt_insert_value(btn **node, t_elem *value, int cmp (t_elem, t_elem)) {
    btn *new_Node=btn_new(*value);
    return sbt_insert_node(node,new_Node,cmp);
}

int btn_count(btn *node){
    if(node!=NULL){
        return 1+btn_count(node->left)+btn_count(node->right);
    }
}

// Imprime un nodo con contexto (para utilizar en recorridos)
void btn_do_print_ctx (btn* node, void* ctx){
    if (!node) return;
    char str[100];
    btn_intToStr(node,str);
    printf("%s ", str);
}

void btn_intToStr(btn* node, char* str){
    if (!node) return;
    reading *r=&node->value;
    sprintf(str, "Minutos:%d  Temperatura:%d\t",r->minute,r->temperature);
}

int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*)){
    char b[200];
    int width = 5;

    if (!tree) return 0;
    toStr(tree, b);
    //sprintf(b, "%s", str);


    int left = _btn_print(tree->left, 1, offset, depth + 1, s, toStr);
    int right = _btn_print(tree->right, 0, offset + left + width, depth + 1, s, toStr);

    // for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++) s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {
        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    } else if (depth && !is_left) {
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }

    return left + width + right;
}

void btn_print(btn *tree, void toStr (btn*, char*)){
    char s[20][255];
    for (int i = 0; i < 20; i++) sprintf(s[i], "%80s", " ");

    _btn_print(tree, 0, 0, 0, s, toStr);

    for (int i = 0; i < 20; i++) {
        int j = 0;
        while (s[i][j] != '\0' && s[i][j] == ' ') {
            j++;
        }
        if (s[i][j] != '\0') {
            printf("%s\n", s[i]);
        }
    }
}
