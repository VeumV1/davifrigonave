#include <stdio.h>
#include "produto.h"

int cadastrarProduto(Produto produtos[], int quantidadeProdutos){
if (quantidadeProdutos >= MAX_PRODUTOS) {
    printF ("\Nerro: Limite maximo de produtos atigindo (%d)!\n", MAX_PRODUTOS);
    return quantidadeProdutos;
}
int i = quantidadeProdutos:
    printf("\n--- CADASTRO DE PRODUTO [%d] ---\n", i + 1);

    printf("Codigo: ");
    scanf("%d", &produtos[i].codigo);

    printf("Nome: ");
    scanf(" %29[^\n]", produtos[i].nome);

    printf("Preco: ");
    scanf("%f", &produtos[i].preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &produtos[i].quantidade);

    printf(">> Produto cadastrado com sucesso!\n");
    return quantidadeProdutos + 1;
    }
void listarProdutos(Produto produtos[], int quantidadeProdutos) {
    printf("\n===== LISTA DE PRODUTOS / ESTOQUE =====\n");
    if (quantidadeProdutos == 0) {
        printf("Nenhum produto cadastrado ate o momento.\n");
        return;
    }
    printf("INDICE\tCODIGO\tNOME\t\tPRECO\t\tESTOQUE\n");
    for (int i = 0; i < quantidadeProdutos; i ++) {
        printf("[%d]\t%d\t%-10s\tR% %.2f\t%d un\n",
               i,
               produtos[i].codigo
               produtos[i].nome
               produtos[i].preco
               produtos[i].quantidade);
               }
}

int buscarProduto(Produto produtos[], int quantidadeProdutos, int codigo) {
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void atualizarEstoque(Produto produtos[], int indiceProduto, int quantidadeVendida) {
    if (indiceProduto >= 0) {
        produtos[indiceProduto].quantidade -= quantidadeVendida;
    }
}
