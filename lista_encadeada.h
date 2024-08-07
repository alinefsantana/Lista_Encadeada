#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct Lista {
    No* cabeca;
    int tamanho;
} Lista;

Lista* criar_lista(int tamanho);
int lista_vazia(Lista* lista);
int obter_tamanho(Lista* lista);
int obter_elemento(Lista* lista, int posicao);
void modificar_elemento(Lista* lista, int posicao, int novo_valor);
void inserir_elemento(Lista* lista, int posicao, int valor);
void retirar_elemento(Lista* lista, int posicao);
void imprimir_lista(Lista* lista);
void destruir_lista(Lista* lista);

#endif
