#ifndef TEMPERATURA_H_INCLUDED
#define TEMPERATURA_H_INCLUDED
#include <stdbool.h>
#define t_elem reading

typedef struct{
    int minute;
	int temperature;
} reading;

reading *new_reading(int minute,int temp);
int get_min(reading *r);
int get_temp(reading *r);
void print_reading(reading *r);

typedef struct __node{
    t_elem value;
    struct __node *next;
}node;

typedef struct{
    node* n;
    int cnt;
}stack;

stack* stack_new();
void node_free(node *n);
void stack_free(stack *s);
node* new_node(t_elem value);
void add_reading_random(stack *s);
void stack_push(stack *s,t_elem value);
bool stack_is_empty(stack *s);
t_elem stack_pop(stack *s);
t_elem stack_top(stack* s);
void stack_print(stack *s,void prt(t_elem*));

typedef struct cola{
    node *head; //primero en agregarse->primero en sacarse
    node *tail;
    int max_size;
    int count;
}cola;

node* new_node_queue(t_elem value);
cola* queue_new (int maxsize);
void queue_free(cola* q);
int queue_getmaxsize(cola *q);
void enqueue (cola* q,t_elem elem);
t_elem dequeue(cola *q);
t_elem peek(cola* q);
void add_random(stack *s);
void queue_print(cola *q);

#define t_elem2 stack
typedef struct _list{
    t_elem2 value;
    struct _list* next;
}list;

list* new_node_list(t_elem2 value);
void list_free(node* head);
int list_length(list *n);
void node_add(list **head, t_elem2 value);
bool list_is_empty(node *n);
t_elem2* list_get(list* head, int index);
list *create_list_random();

typedef struct _btn{
    t_elem value;
    struct _btn *left;
    struct _btn *right;
}btn;

btn* btn_new(t_elem value);
void btn_free(btn **n);
int is_empty(btn *b);
int sbt_insert_node(btn **node, btn *newNode, int cmp(t_elem,t_elem));
int sbt_insert_value(btn **node, t_elem *value, int cmp (t_elem, t_elem));
int btn_count(btn *node);
int cmp(t_elem a,t_elem b);
void btn_intToStr(btn* node, char* str);
int is_empty(btn *b);

void add_tree(list *l,btn **n);
void in_order_(btn *n,void btn_do(void* ctx,t_elem e),void* ctx);

void enqueue (cola* q,t_elem elem);
void insert_tree(stack *s,btn **n);
int sbt_insert_value(btn **node, t_elem *value, int cmp (t_elem, t_elem));

#endif // TEMPERATURA_H_INCLUDED
