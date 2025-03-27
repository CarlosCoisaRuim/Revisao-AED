#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dado;
    char color;
    struct node *parent;
}node;

struct node *grandparent(struct node *n);
struct node *uncle(struct node *n);
void insertCase1(struct node *n);
void insertCase2(struct node *n);
void insertCase3(struct node *n);
void insertCase4(struct node *n);
void insertCase5(struct node *n);


int main(){
char control;
int dado=0;
while(control!='s'){
    printf("Adicione um número na árvore ou insira s para encerrar./n");
    scanf("%d", &dado);

    struct node *n = (struct node)malloc(sizeof(node));

    struct node n->dado = dado;

}

}

rotate_left();

rotate_right();

struct node *grandparent(struct node *n){
    if((n!=NULL)&&(n->parent!=NULL))
        return n->parent->parent;
    else
        return NULL;
}

struct node *uncle(struct node *n){
    struct node *g = grandparent(n);
    if(g==NULL)
        return NULL; //sem avô não pode ter tio
    if(n->parent==g->left)
        return g->right;
    else
        return g->left;
}

void insertCase1(struct node *n){
    if(n->parent==NULL) //Se não tem pai, é a raíz. 
    n->color='b';       //Se é a raíz, é preto.
 else
    insertCase2(n);
}

void insertCase2(struct node *n){
    if(n->parent->color=='b')
    return; //Não precisa corrigir, pois esse elemento é uma folha filha de um nodo Preto.
    else
        insertCase3(n); //Se cair aqui, já quebrou uma regra, resta ver qual e tratar de acordo.
}

void insertCase3(struct node *n){
    struct node *u = uncle(n), *g;

    if((u!=NULL)&&(u->color=='r')){ //checa se o tio do elemento inserido é vermelho.
        n->parent->color='b';
        u->color='b';
        g = grandparent(n);
        g->color='r';
        insertCase1(g); //chama só pra garantir que não coloriu a raiz de vermelho
    } else{
        insertCase4(n);
    }
}

void insertCase4(struct node *n){
    struct node *g = grandparent(n);

    if((n==n->parent->right)&&(n->parent==g->left)){
        rotate_left(n->parent);
        n = n->left;
    }else if ((n == n->parent->left)&&(n->parent==g->right)){
        rotate_right(n->parent);
        n = n->right;
    }
    insertCase5(n); //função que checa se as cores estão certas. É chamada de qualquer jeito.
}

void insertCase5(struct node *n){
    struct node *g = grandparent(n);

    if((n == n->parent->left)&&(n->parent==g->left)){
        rotate_right(g);
    }else{
        rotate_left(g);
    }
    n->parent->color='b';   //recoloração fixa pra evitar a raíz ficar vermelha.
    g->color='r';
}