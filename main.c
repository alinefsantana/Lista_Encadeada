#include <stdio.h>
#include "lista_encadeada.h"

int main() {
    int tamanho;
    printf("Digite o tamanho inicial da lista: ");
    scanf("%d", &tamanho);

    Lista* lista = criar_lista(tamanho);

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Verificar se a lista está vazia\n");
        printf("2. Obter tamanho da lista\n");
        printf("3. Obter valor de um elemento\n");
        printf("4. Modificar valor de um elemento\n");
        printf("5. Inserir um elemento\n");
        printf("6. Retirar um elemento\n");
        printf("7. Imprimir a lista\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (lista_vazia(lista)) {
                    printf("A lista está vazia.\n");
                } else {
                    printf("A lista não está vazia.\n");
                }
                break;
            case 2:
                printf("Tamanho da lista: %d\n", obter_tamanho(lista));
                break;
            case 3:
                {
                    int posicao;
                    printf("Digite a posição do elemento: ");
                    scanf("%d", &posicao);
                    int valor = obter_elemento(lista, posicao);
                    if (valor != -1) {
                        printf("Valor na posição %d: %d\n", posicao, valor);
                    }
                }
                break;
            case 4:
                {
                    int posicao, novo_valor;
                    printf("Digite a posição do elemento: ");
                    scanf("%d", &posicao);
                    printf("Digite o novo valor: ");
                    scanf("%d", &novo_valor);
                    modificar_elemento(lista, posicao, novo_valor);
                }
                break;
            case 5:
                {
                    int posicao, valor;
                    printf("Digite a posição para inserir o elemento: ");
                    scanf("%d", &posicao);
                    printf("Digite o valor do elemento: ");
                    scanf("%d", &valor);
                    inserir_elemento(lista, posicao, valor);
                }
                break;
            case 6:
                {
                    int posicao;
                    printf("Digite a posição do elemento a ser removido: ");
                    scanf("%d", &posicao);
                    retirar_elemento(lista, posicao);
                }
                break;
            case 7:
                imprimir_lista(lista);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 8);

    destruir_lista(lista);
    return 0;
}
