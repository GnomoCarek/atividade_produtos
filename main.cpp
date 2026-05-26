#include <stdio.h>
#include "produtos.h"

int main(){
    struct Produto produtos[MAX_PRODUTOS];
    int qtdProdutos =0;
    int opcao =0;

    do
    {
        limpaTela();
        exibirMenu();

        if(scanf("%d",&opcao) != 1){
            printf(" Entrada inválida digite um numero\n");

            while (getchar() != '\n');
            pausar();
            continue;
          
        }
        getchar();

        switch (opcao)
        {
        case 1:
            caderastaProduto(produtos, &qtdProdutos);

            break;
        case  2:

            listarProdutos(produtos, &qtdProdutos);

            break;

        case 3:{

            
            int cod;
            
            printf("\n Digite o código do produto para buscar: ");
            
            scanf("%d", &cod);
            
            getchar();
            
            int idx = buscarProduto(produtos, &qtdProdutos,cod);
            
            if (idx !=  -1 ) {
                printf("\n Produto encontrado\n");
                
                printf("codigo: %d\n",predutos[idx].codigo);
                printf("nome): %s\n",predutos[idx].nome);
                printf("preco: %.2f\n",predutos[idx].preco);
                printf("Quantidade: %d\n",predutos[idx].quantidade);
                
            }else{
                
                printf(" Produto não encontrado");
            }
            pausar();
            
            break;
        }

        case 4: {

            float total = calcularEstoque(produtos, &qtdProdutos);

            printf(" Valor total em estoque R$ %.2f\n",total);

            pausar();
            
            break;
        }

        case 5:

            printf(" Saindo do sistema...");

            break;
        default:

            printf(" Opção inválida tente novamente");
            pausar();
        }
    } while (opcao != 5);

    return 0;
    
}
