#include <stdio.h>
#include "produtos.h"

int main(){
    struct Produto produtos[MAX_PRODUTOS];
    int qtdProdutos = 0;
    int opcao = 0;

    do
    {
        limparTela();
        exibirMenu();

        if(scanf("%d", &opcao) != 1){
            printf("Entrada inválida, digite um número\n");
            while (getchar() != '\n');
            pausar();
            continue;
        }
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrarProduto(produtos, &qtdProdutos);
            break;
        case 2:
            listarProduto(produtos, &qtdProdutos);
            break;
        case 3:{
            int cod;
            printf("\nDigite o código do produto para buscar: ");
            scanf("%d", &cod);
            getchar();
            
            int idx = buscarProduto(produtos, &qtdProdutos, cod);
            
            if (idx != -1) {
                printf("\nProduto encontrado:\n");
                printf("Codigo: %d\n", produtos[idx].codigo);
                printf("Nome: %s\n", produtos[idx].nome);
                printf("Preco: R$ %.2f\n", produtos[idx].preco);
                printf("Quantidade: %d\n", produtos[idx].quantidade);
            } else {
                printf("Produto não encontrado!\n");
            }
            pausar();
            break;
        }
        case 4: {
            float total = calcularEstoque(produtos, &qtdProdutos);
            printf("\nValor total em estoque: R$ %.2f\n", total);
            pausar();
            break;
        }
        case 5:
            printf("\nSaindo do sistema...\n");
            break;
        default:
            printf("Opção inválida, tente novamente!\n");
            pausar();
        }
    } while (opcao != 5);

    return 0;
}
