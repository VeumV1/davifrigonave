#ifndef VENDA_H
#define VENDA_H

#include "produto.h"

/*
    REGRAS DA VENDA

    1. O sistema deve permitir vender MAIS DE UM produto na mesma compra.
    2. Para cada produto, solicitar a quantidade desejada.
    3. Verificar se a quantidade e valida.
    4. Verificar se existe estoque suficiente.
    5. Formas de pagamento:
       - Dinheiro
       - Cartao de credito
       - Cartao de debito

    DINHEIRO:
       - pedir o valor pago;
       - calcular o troco;
       - impedir valor pago menor que o total.

    CREDITO:
       - permitir de 1 a 6 parcelas;
       - parcelamento somente se a compra for maior que R$ 100,00.

    DEBITO:
       - finalizar diretamente.

    6. Atualizar o estoque automaticamente apos a venda.
    7. Mostrar mensagens de erro e alerta.
    8. Utilizar vetores e indices.
    9. NAO UTILIZAR PONTEIROS.
*/

// Prototipos das funcoes de venda

// Conduz a venda: escolhe produtos, quantidades, total, pagamento e estoque.
void realizarVenda(Produto produtos[], int quantidadeProdutos);

// Aplica as regras de pagamento (dinheiro, credito ou debito) ao total.
void processarPagamento(float total);

#endif
