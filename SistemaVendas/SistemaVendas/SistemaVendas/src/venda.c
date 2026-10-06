#include <stdio.h>
#include "venda.h"
#include "produto.h"

void processarPagamento(float total) {
    int formaPagamento;
    float valorPago, troco;

    printf("\n--- PAGAMENTO ---\n");
    printf("Total a pagar: R$ %.2f\n", total);
    printf("Escolha a forma de pagamento:\n");
    printf("1 - Dinheiro\n");
    printf("2 - Cartao de Debito\n");
    printf("3 - Cartao de Credito\n");
    printf("Opcao: ");
    scanf("%d", &formaPagamento);

    switch (formaPagamento) {
        case 1:
            printf("Digite o valor entregue pelo cliente: R$ ");
            scanf("%f", &valorPago);

            if (valorPago >= total) {
                troco = valorPago - total;
                printf("Pagamento em dinheiro confirmado!\n");
                printf("Troco: R$ %.2f\n", troco);
            } else {
                printf("ERRO: Valor insuficiente! Venda cancelada.\n");
            }
            break;

        case 2:
            printf("Processando cartao de debito...\n");
            printf("Pagamento aprovado com sucesso!\n");
            break;

        case 3:
            printf("Processando cartao de credito...\n");
            printf("Pagamento aprovado com sucesso!\n");
            break;

        default:
            printf("ERRO: forma de pagamento invalida! Venda cancelada.\n");
            break;
    }
}

void realizarVenda(Produto produtos[], int quantidadeProdutos) {
    if (quantidadeProdutos == 0) {
        printf("\nNenhum produto cadastrado para realizar vendas!\n");
        return;
    }

    float totalVenda = 0.0;
    int continuar = 1;

    printf("\n==== INICIO DA VENDA ====\n");

    while (continuar == 1) {
        int codigoDesejado, qtdDesejada;
        int indiceEncontrado = -1;
        printf("\n --- PRODUTOS DISPONIVEIS ---\n");
        printf("INDICE\tCODIGO\tNOME\t\tPRECO\t\tESTOQUE\n");
        for (int i = 0; i < quantidadeProdutos; i++) {
            printf("[%d]\t%d\t%-10s\tR$ %.2f\t%d un\n",
                   i, produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
        }

        printf("\nDigite o codigo do produto desejado: ");
        scanf("%d", &codigoDesejado);

        for (int i = 0; i < quantidadeProdutos; i++) {
            if (produtos[i].codigo == codigoDesejado) {
                indiceEncontrado = i;
                break;
            }
        }

        if (indiceEncontrado != -1) {
            printf("Digite a quantidade desejada de %s: ", produtos[indiceEncontrado].nome);

            if (qtdDesejada <= 0) {
                printf("ERRO: Quantidade deve ser maior que zero.\n");
            } else if (qtdDesejada <= produtos[indiceEncontrado].quantidade) {
                float subtotal = qtdDesejada * produtos[indiceEncontrado].preco;
                totalVenda += subtotal;
                produtos[indiceEncontrado].quantidade -= qtdDesejada;

                printf("-> %d unidade(s) de %s adicionada(s)! Subtotal: R$ %.2f\n",
                       qtdDesejada, produtos[indiceEncontrado].nome, subtotal);
            } else {
                printf("ERRO: Estoque insuficiente! Disponivel: %d un.\n", produtos[indiceEncontrado].quantidade);
            }
        } else {
            printf("ERRO: Produto com codigo %d nao encontrado.\n", codigoDesejado);
        }

        printf("\nDeseja adicionar outro produto? (1 - sim / 0 - nao): ");
        scanf("%d", &continuar);
    }

    if (totalVenda > 0) {
        processarPagamento(totalVenda);
    } else {
        printf("\nNenhum produto foi comprado. Venda finalizada.\n");
    }
}
