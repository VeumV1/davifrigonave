#include <stdio.h>
#include "produto.h"
#include "venda.h"

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidadeProdutos = 0;
    int opcao;

    do {
        printf("\n===== SISTEMA DE VENDAS =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Mostrar estoque\n");
        printf("3 - Realizar venda\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                quantidadeProdutos = cadastrarProduto(produtos, quantidadeProdutos);
                break;

            case 2:
                listarProdutos(produtos, quantidadeProdutos);
                break;

            case 3:
                realizarVenda(produtos, quantidadeProdutos);
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("ERRO: opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
