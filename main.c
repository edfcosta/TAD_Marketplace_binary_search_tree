#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL.h"

int main() {
    Marketplace *AVL=NULL;
    long int code;
    char *product;
    int month, year;
    float value;
    int choice=0;
    for(;;) {
        printf("ENTER");
        getchar();
        system("cls");
        choice=menu();
        if(choice==9) {
            break;
        }
        switch (choice) {
            case 1:
                printf("\t___________________\n");
                printf("\t|  Code:          |  ");
                scanf("%ld", &code);
                printf("\t|  Product:       |  ");
                product=read_string(product);
                printf("\t|  Validity:      |  \n");
                printf("\t|   __month:      |  ");
                scanf("%d", &month);
                printf("\t|   __year:       |  ");
                scanf("%d", &year);
                printf("\t|  Value:         |  ");
                scanf("%f", &value);
                printf("\t|_________________|\n");
                AVL=insert_tree(AVL, code, product, month, year, value);
                getchar();
                break;
            case 2:
                printf("\nCode: ");
                scanf("%ld", &code);
                if(search_nodo(AVL, code)==NULL){
                    printf("WARNING: code not exist!\n");
                    getchar();
                }else{
                    printer(search_nodo(AVL, code));
                    getchar();
                }
                break;
            case 3:
                printf("\nCode: ");
                scanf("%ld", &code);
                edit_element(search_nodo(AVL, code));
                getchar();
                break;
            case 4:
                printf("\nCode: ");
                scanf("%ld", &code);
                removee(AVL, code);
                getchar();
                break;
            case 5:
                printer(AVL);
                break;
            case 6:
                printf("[ Number Elements: %d ]\n", size_tree(AVL));
                break;
            case 7:
                printf("[ Height: %d ]\n", h(AVL)+1);
                break;
            case 8:
                tree_startup(AVL);
                break;
        }
    }
    product=NULL;
    free(product);
    AVL=NULL;
    printf("FINISH\n");
    printf("POINTER: [%p]", AVL);
    return(0);
}
