typedef struct date Date;                                                           //estrutura para data
typedef struct marketplace Marketplace;                                             //estrutura para mercado AVL

int menu();
int maxx(int x, int y);                                                             //return maior valor
int h(Marketplace *no);                                                             //retorna altura

Marketplace *rotation_left(Marketplace *root);                                      //rotação esquerda
Marketplace *rotation_right(Marketplace *root);                                     //rotação dreita
Marketplace *left_right(Marketplace *root);                                         //rotação esqueda direita
Marketplace *right_left(Marketplace *no);                                           //rotação direita esquerda

Marketplace *create_nodo(long int key);                                             //cria nó

char *read_string(char *product);                                                   // função para armazenar palavra

Marketplace *balance(Marketplace *root, long int key,                               //função de balanceamento
                    char*product, int month, int year, float value);
Marketplace *insert_tree(Marketplace *root, long int key,                           //cria folha e balanceia
                    char *product, int month, int year, float value);
Marketplace *removee(Marketplace *root, long int key);

int search_menu();                                                                  //menu do dados pedido do nó
Marketplace *search_nodo (Marketplace *root, long int code);                        //procura pela chave (codigo) recursivamente

void *edit_element(Marketplace *root);                                              //edita um elemento específico do nó

void printer(Marketplace *root);                                                    //imprime de forma ordenada

int size_tree(Marketplace *no);                                                     //quantidade de elementos da arvore

void tree_startup(Marketplace *root);
void tree(Marketplace *root, int depth, char *way, int direita);

void free_root(Marketplace *root);
void free_tree (Marketplace *root);
