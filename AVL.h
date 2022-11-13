typedef struct date Date;                                                           //estrutura para data
typedef struct marketplace Marketplace;                                             //estrutura para mercado AVL

int menu();
int maxx(int x, int y);                                                             //return maior valor
int h(Marketplace *no);                                                             //retorna altura

Marketplace *rotation_left(Marketplace *root);                                      //rota��o esquerda
Marketplace *rotation_right(Marketplace *root);                                     //rota��o dreita
Marketplace *left_right(Marketplace *root);                                         //rota��o esqueda direita
Marketplace *right_left(Marketplace *no);                                           //rota��o direita esquerda

Marketplace *create_nodo(long int key);                                             //cria n�

char *read_string(char *product);                                                   // fun��o para armazenar palavra

Marketplace *balance(Marketplace *root, long int key,                               //fun��o de balanceamento
                    char*product, int month, int year, float value);
Marketplace *insert_tree(Marketplace *root, long int key,                           //cria folha e balanceia
                    char *product, int month, int year, float value);
Marketplace *removee(Marketplace *root, long int key);

int search_menu();                                                                  //menu do dados pedido do n�
Marketplace *search_nodo (Marketplace *root, long int code);                        //procura pela chave (codigo) recursivamente

void *edit_element(Marketplace *root);                                              //edita um elemento espec�fico do n�

void printer(Marketplace *root);                                                    //imprime de forma ordenada

int size_tree(Marketplace *no);                                                     //quantidade de elementos da arvore

void tree_startup(Marketplace *root);
void tree(Marketplace *root, int depth, char *way, int direita);

void free_root(Marketplace *root);
void free_tree (Marketplace *root);
