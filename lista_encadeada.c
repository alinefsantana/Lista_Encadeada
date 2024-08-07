#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

Lista* criar_lista(int tamanho) {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeca = NULL;
    lista->tamanho = 0;

    for (int i = 0; i < tamanho; i++) {
        int valor;
        printf("Digite o valor do elemento %d: ", i + 1);
        scanf("%d", &valor);
        inserir_elemento(lista, i + 1, valor);
    }

    return lista;
}

int lista_vazia(Lista* lista) {
    return lista->tamanho == 0;
}

int obter_tamanho(Lista* lista) {
    return lista->tamanho;
}

int obter_elemento(Lista* lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return -1;
    }
    No* atual = lista->cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    return atual->valor;
}

void modificar_elemento(Lista* lista, int posicao, int novo_valor) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    No* atual = lista->cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    atual->valor = novo_valor;
}

void inserir_elemento(Lista* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("Posição inválida!\n");
        return;
    }

    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (posicao == 1) {
        novo_no->proximo = lista->cabeca;
        lista->cabeca = novo_no;
    } else {
        No* atual = lista->cabeca;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        novo_no->proximo = atual->proximo;
        atual->proximo = novo_no;
    }
    lista->tamanho++;
}

void retirar_elemento(Lista* lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return;
    }

    No* removido;
    if (posicao == 1) {
        removido = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
    } else {
        No* atual = lista->cabeca;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        removido = atual->proximo;
        atual->proximo = removido->proximo;
    }

    free(removido);
    lista->tamanho--;
}

void imprimir_lista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void destruir_lista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}
