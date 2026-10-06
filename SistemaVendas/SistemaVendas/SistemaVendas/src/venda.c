#include <stdio.h>
#include "venda.h"

// TODO: implementar a venda utilizando vetores e indices.
// Nao utilizar ponteiros.
//
// Uma possibilidade:
// - percorrer o vetor de produtos;
// - perguntar qual produto o cliente deseja;
// - perguntar a quantidade;
// - somar o valor ao total;
// - diminuir a quantidade do estoque;
// - repetir enquanto o cliente desejar adicionar produtos.
//
// Depois:
// - mostrar o total;
// - escolher a forma de pagamento;
// - aplicar as regras de dinheiro, credito ou debito.

void realizarVenda(Produto produtos[], int quantidadeProdutos) {
    // TODO
}

void processarPagamento(float total) {
int formadepagamento;
float valorpago, troco;
printf("\n--- PAGAMENTO ---\n");
printf("Total a pagar: R$ %.2f\n", total);
printf("Escolha a forma de pagamento:\n");
printf("1 - Dinheiro\n");
printf("2 - Cartao de Debito\n");
printf("3 - Cartao de Credito\n");
printf("Opcao: ");
scanf("%d", &formaPagamento);


switch (formadepagamento) {
case 1:
    printf("Digite o valor entregue pelo cliente: R$ ");
    scanf("%f", &valorpago);

    if (valorPago >= total) {
    troco = valorPago - total;
    printf("Pagamento em dinheiro confirmado!\n");
    printf("Troco: R$ %.2f\n", troco);
    } else {
    printf("ERRO: Valor insuficiente! Venda cancelada.\n");
    }
break;

case 2 :
    printd("Processando cartão de debito...\n")
    printf("Pagamento aprovado com sucesso!\n")
    break;

case 3:
   printf("Processando cartao de credito...\n");
   printf("Pagamento aprovado com sucesso!\n");
   break;


   default:printf("ERRO: forma de pagamento invalida! Venda cancelada.\n")
break;


}
}

void realizarVenda(produto produtos [] int quantidadeProdutos){
if(quantidadeProdutos == 0)
    printf("\nNenhum produto cadastrado para realizar vendas!\n");
    return;
}

float totalVenda = 0.0;
int continuar = 1;

printf("\n==== INICIO DA VENDA====\n");

while (continuar == 1) {
    int codigoDesejado, qtdDesejada;
    int indiceEncotrado = -1;

    printf("\n --- PRODUTOS DISPONIVEIS ---\n");
    printf("INDICE\tCODIGO\tNOME\t\tPRECO\t\tESTOQUE\n");
    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("[%d]\t%d\t%-10s\tR$ %.2f\t%d un\n",
               i, produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
    printf("\nDigite o codigo do produto desejado: ");
    scanf("&d", &codigoDesejado);
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (produtos [i].codigo == codigoDesejado) {
            indiceEncontrado = i;
            break;
        }
    }
    if (indiceEncontrado != -1) {
        printf("Digite a quantidade desejada de %s:  ", produtos[indiceEncontrado].quantidade);
        scanf("d%", &qtdDesejada);

        if (qtdDesejada <= 0) {
            printf("ERRO: Quantidade deve ser maior que zero. \n");

        } else if (qntDesejada <= produtos[indicesEncontrado].quantidade) {

        float subtotal = qtdDesejada * produtos[indiceEncontrado].preco;
        totalVenda += subtotal;
        produtos[indiceEncontrado].quantidade -= qtdDesejada;
        printf("-> %d unidade(s) de %ss adicionada(s)! Subtotal: R$ %.2f\n",
               qtdDesejada, produtos[indicesEncotrado].nome, subtotal);

    } else {
    printf("ERRO: Estoque insuficiente! Disponivel: %d un.\n", produtos [indiceEncotrado].quantidade);
    }
    else {
printf("ERRO: Produto com codigo %d nao encotrado. \n", codigoDesejado);
}
printf("\nDeseja adicionar outro produto? (1 - sim / 0 - nao): ");
scanf("%d", &continuar);
}

if (totalVenda > 0) {
    processarPagamento(totalVenda);
} else {
printf("\nNenhum produto foi comprado. Venda finalizada. \n");
}

}


