#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "AVL.h"
#define location 5
struct date{
    int month;
    int year;
};
struct marketplace{
    long int code;
    char *product;
    Date validity;
    float value;
    int h;
    struct marketplace *left;
    struct marketplace *right;
};

int menu(){
    int change=0;
    do{
        printf("________________________________\n");
        printf("|\t      MENU \t\t|\n");
        printf("| [1] Insert \t\t\t|\n");
        printf("| [2] Search \t\t\t|\n");
        printf("| [3] To edit \t\t\t|\n");
        printf("| [4] To remove \t\t|\n");
        printf("| [5] Print all \t\t|\n");
        printf("| [6] Number of Elements \t|\n");
        printf("| [7] Tree high \t\t|\n");
        printf("| [8] Tree Structure \t\t|\n");
        printf("| [9] Exit \t\t\t|\n");
        printf("|_______________________________|\n");
        printf("Enter your choice: ");
        scanf("%d", &change);
    }while ( (change < 1) || (change > 9) );
    getchar();
    return(change);
}

int maxx(int x, int y) { //retorna maior elemento entre x e y
    if(x>y) {
        return (x);
    }else
        return (y);
}

int h(Marketplace *no){ //retorna altura do nó
    //se arvore vazia, default(-1)
    if(no==NULL)
        return(-1);
    else
        return (no->h);
}

Marketplace *rotation_left(Marketplace *root){  //rot.esquerda
    Marketplace *aux=NULL;
    aux=root->right;
    root->right=aux->left;
    aux->left=root;
    //reestabelece altura dos nó esq de aux:
    root->h= maxx( h(root->left),
                  h(root->right))+1;
    //reestabelece altura do a nova raiz
    aux->h= maxx(h(aux->left),
                 h(aux->right))+1;
    return(aux);
}

Marketplace *rotation_right(Marketplace *root){
    Marketplace *aux=NULL;
    aux=root->left;
    root->left=aux->right;
    aux->right=root;
    //retorna maior valor entre a esquerda e a direita + 1:
    // +1 pois está um nível acima agora
    root->h = maxx(h(root->left), h(root->right)) +1;
    aux->h = maxx(h(aux->left), h(aux->right)) +1;
    return(aux);
}

Marketplace *left_right(Marketplace *root){
    root->left=rotation_left(root->left);
    return (rotation_right(root));
}

Marketplace *right_left(Marketplace *root){
    root->right=rotation_right(root->right);
    return(rotation_left(root));
}

Marketplace *create_nodo(long int key){
    Marketplace *root=NULL;
    root=(Marketplace*) malloc (sizeof(Marketplace));
    if (root==NULL)
        exit (1);
    //chave inserida na criação do nó
    root->code=key;
    root->product=NULL;
    root->validity.month=0;
    root->validity.year=0;
    root->value=0;
    root->left=NULL;
    root->right=NULL;
    return (root);
}

char *read_string(char*product) {
    product=NULL;
    getchar();
    product=(char*) malloc (25*sizeof(char));
	int i=0;
    char c = getchar();
	do {
        product[i++] = c;
		c = getchar();
	}while (c != '\n');
	product[i++] = '\0';
	product=(char*)realloc(product, i*sizeof(char));
    return (product);
}

Marketplace *balance(Marketplace *root, long int key,
                     char*product, int month, int year, float value){
    if (key < root->code) {
        root->left = insert_tree(root->left, key,
                                 product, month, year, value);
        if( (h(root->left) - h(root->right)) == 2 ){
            if(key < root->left->code){
                root=rotation_right(root);
            }else
                root=left_right(root);
        }
    }else
        if (key > root->code){
            root->right = insert_tree(root->right, key,
                                      product, month, year, value);

            if( (h(root->right) - h(root->left)) == 2 ){
                if(key > root->right->code){
                    root=rotation_left(root);
                }else
                    root=right_left(root);
            }
        }
    root->h= maxx(h(root->left), h(root->right))+1;
    return(root);
}

Marketplace *insert_tree(Marketplace *root, long int key,
                         char*product, int month, int year, float value){
    if (root==NULL){
        root=create_nodo(key);
        root->product=product;
        root->validity.month=month;
        root->validity.year=year;
        root->value=value;
        root->h=maxx(h(root->left), h(root->right))+1;;
        root->left=NULL;
        root->right=NULL;
    }
    root=balance(root, key, product, month, year, value);
    return root;
}

Marketplace *removee(Marketplace *root, long int key){
    Marketplace *aux = root;
    if(root == NULL){
        return NULL;
    }
    else{
        if(root->code > key){
            root->left = removee(root->left, key);
        }
        else
            if (root->code < key){
                root->right = removee(root->right, key);
            }
            else
                if((root->left == NULL) && (root->right == NULL)){
                    free(root);
                    root=NULL;
                }
                else
                    if(root->right== NULL){
                        root=root->left;
                        free (aux);
                        aux=NULL;
                    }
                    else{
                        aux = root->left;
                        while(aux->right != NULL){
                            aux=aux->right;
                        }
                        root->code = aux->code;
                        aux->code = key;
                        root->left = removee(root->left, key);
                    }

    }

    return (root);
}


int search_menu() {
    int x=0;
        printf("\t_________________\n");
        printf("\t|     Edit:     |\n");
        printf("\t|   1.Name      |\n");
        printf("\t|   2.Validity  |\n");
        printf("\t|   3.Value     |\n");
        printf("\t|   4.Exit      |\n");
        printf("\t|_______________|\n");
        printf("\t Choice: ");
        scanf("%d", &x);
    return (x);

}

Marketplace *search_nodo(Marketplace *root, long int key){
    if(root==NULL){
        return (NULL);
    }else if (root->code > key){
        return search_nodo(root->left, key);
    }else if(root->code < key) {
            return search_nodo(root->right, key);
        }else
            return (root);
}

void *edit_element(Marketplace *root) {
    int choice=0;
    if(root==NULL)
        return(NULL);      //if retorna main
    while(choice!=5){
        choice=search_menu();
        if(choice==4)
            break;
        switch (choice){
            case 1:
                root->product=read_string(root->product);
                break;
            case 2:
                printf("\nMonth: ");
                scanf("%d", &root->validity.month);
                printf("Year: ");
                scanf("%d", &root->validity.year);
                break;
            case 3:
                scanf("%f", &root->value);
                break;
        }
    }
    return NULL;
}

void printer(Marketplace *root){
    if (root!=NULL) {
        printer(root->left);
        printf("\nCode: %ld", root->code);
        printf("\nProduct: %s", root->product);
        printf("\nValidity: %.2d/%.4d", root->validity.month, root->validity.year);
        printf("\nValue: %.2f", root->value);
        printf("\nHeight: %d\n", root->h);
        printer(root->right);
    }

}

int size_tree(Marketplace *no){
    if(no==NULL)
        return(0);
    else
        return 1+(size_tree(no->left)+size_tree(no->right));
}

void tree(Marketplace *root, int depth, char *way, int direita)
{
    if (root== NULL){
        return;
    }
    depth++;
    tree(root->right, depth, way, 1);
    way[depth-2] = 0;
    if(direita)
        way[depth-2] = 1;
    if(root->left)
        way[depth-1] = 1;
    printf("\n");
    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("*");
      else if(way[i])
          printf("|");
      else
          printf(" ");
      for(int j=1; j<location; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }
    printf("%ld\n", root->code);
    for(int i=0; i<depth; i++)
    {
      if(way[i])
          printf("|");
      else
          printf(" ");
      for(int j=1; j<location; j++)
          printf(" ");
    }
    tree(root->left, depth, way, 0);
}

void tree_startup(Marketplace *root)
{
    char way[255] = {};
    tree(root, 0, way, 0);
}

void free_tree(Marketplace *root){
    if(root==NULL)
    {
        return;
    }
    free_tree(root->right);
    free_tree(root->left);
    free (root);
    root = NULL;
}

void free_root(Marketplace* root){
    if(root==NULL)
    {
        return ;
    }
    free_tree(root);
}
