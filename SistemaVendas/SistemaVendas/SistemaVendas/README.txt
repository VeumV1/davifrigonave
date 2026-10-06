ESQUELETO - SISTEMA DE VENDAS EM C
VERSAO SEM PONTEIROS

ESTRUTURA DO PROJETO

SistemaVendas/v
|-- SistemaVendas.cbp    Projeto do Code::Blocks (abrir este arquivo)
|-- main.c               Menu principal e controle do sistema.
|-- include/             HEADERS (.h)
|   |-- produto.h        Struct Produto, constantes e prototipos.
|   `-- venda.h          Regras e prototipos relacionados a venda.
|-- src/                 SOURCES (.c)
|   |-- produto.c        Cadastro, busca, estoque e listagem.
|   `-- venda.c          Venda e pagamento.
`-- README.txt

COMO ABRIR NO CODE::BLOCKS

1. Extraia o .zip inteiro (nao abra de dentro do zip).
2. De dois cliques em SistemaVendas.cbp
   (ou: File > Open... e escolha SistemaVendas.cbp).
3. Build > Build and run   (ou tecla F9).

Se aparecer o erro "produto.h: No such file or directory":
   Project > Build options > Search directories > Compiler
   e confira se a pasta "include" esta na lista.

Se o Code::Blocks nao encontrar o compilador:
   Settings > Compiler > Toolchain executables
   (recomendado instalar a versao "codeblocks-mingw" no Windows).

IMPORTANTE:
O projeto foi preparado para trabalhar com VETORES/ARRAYS e INDICES.
NAO UTILIZAR PONTEIROS.

REGRAS PRINCIPAIS:

1. Cadastrar MAIS DE UM produto.
2. Mostrar todos os produtos cadastrados.
3. Mostrar o estoque.
4. Permitir vender MAIS DE UM produto na mesma compra.
5. Solicitar a quantidade desejada.
6. Impedir quantidade 0 ou negativa.
7. Impedir venda maior que o estoque.
8. Pagamento em dinheiro:
   - solicitar valor pago;
   - calcular troco;
   - impedir pagamento menor que o total.
9. Cartao de credito:
   - permitir 1 a 6 parcelas;
   - somente permitir parcelamento se a compra for maior que R$ 100,00.
10. Cartao de debito:
   - finalizar diretamente.
11. Atualizar estoque automaticamente depois da venda.
12. Exibir mensagens de erro e alerta.
13. Organizar o projeto em main, source (.c) e header (.h).
14. NAO UTILIZAR PONTEIROS.

EXEMPLO DE COMPILACAO (fora do Code::Blocks):

gcc main.c src/produto.c src/venda.c -Iinclude -o sistema_vendas

No Windows:
sistema_vendas.exe

No Linux/macOS:
./sistema_vendas

OBSERVACOES:
As funcoes estao propositalmente incompletas e possuem TODO.
O objetivo e que o grupo desenvolva a implementacao durante as aulas.

Ajuste feito na estrutura: como nao se usa ponteiros, uma funcao nao
consegue alterar a variavel quantidadeProdutos da main. Por isso
cadastrarProduto() agora RETORNA a nova quantidade, e a main faz:

    quantidadeProdutos = cadastrarProduto(produtos, quantidadeProdutos);
