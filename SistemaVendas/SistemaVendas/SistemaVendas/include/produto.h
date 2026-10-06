#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100
#define TAM_NOME 50

typedef struct {
    int codigo;
    char nome[TAM_NOME];
    float preco;
    int estoque;
} Produto;

// Prototipos das funcoes de produto

// Cadastra um produto no vetor e RETORNA a nova quantidade de produtos
// (como nao usamos ponteiros, a main recebe o valor atualizado pelo return).
int cadastrarProduto(Produto produtos[], int quantidadeProdutos);

// Mostra todos os produtos cadastrados (codigo, nome, preco e estoque).
void listarProdutos(Produto produtos[], int quantidadeProdutos);

// Retorna o INDICE do produto no vetor, ou -1 se nao encontrar.
int buscarProduto(Produto produtos[], int quantidadeProdutos, int codigo);

// Diminui do estoque a quantidade vendida do produto no indice informado.
void atualizarEstoque(Produto produtos[], int indiceProduto, int quantidadeVendida);

#endif
