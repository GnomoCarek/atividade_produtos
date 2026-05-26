#ifndef PRODUTOS_H
#define PRODUTOS_H
#define MAX_PRODUTOS 100

struct Produto
{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

void limparTela();
void pausar();
void exibirMenu();
void cadastrarProduto(struct Produto p[],int *qtd);
void listarProduto(struct Produto p[],int *qtd);
float calcularEstoque(struct Produto p[],int *qtd);
int buscarProduto(struct Produto p[],int *qtd,int codigo);

#endif
