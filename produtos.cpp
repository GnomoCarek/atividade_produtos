#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produtos.h"

void limparTela(){
    #ifdef _WIN324
        system("cls");
    #else 
         system("clear");
    #endif
}

void pausar(){
    printf("\n Pressione enter para continuar...");
    getchar();


}

void exibirMenu(){
    printf("\n======== Sistema de cadastro de produtos ========");

    printf ("1. Cadastrar produtos\n");
    printf ("2. Lista produtos\n");
    printf ("3. Buscar produto pelo codigo\n");
    printf ("4. Calcular o valor total em estoque\n");
    printf ("5. Sair\n");
    printf ("\n Escolha uma opcao: ");
}

void cadastrarProduto(struct Produto p[],int *qtd){

    if (*qtd >= MAX_PRODUTOS)
    {
       printf("\n Erro limite de estoque atingido\n");

       pausar();
       return;
    }
    limparTela();

    printf("\n======== Cadastrar produto ========\n");

    printf("Codigo: ");

    scanf("%d", &p[*qtd].codigo);

    getchar();

    printf("Nome: ");

    fgets(p[*qtd].nome, 50,stdin);

    p[*qtd].nome[strcspn(p[*qtd].nome,"\n")] ='\0';

    printf("Preco: ");

    scanf("%f", &p[*qtd].preco);

    printf(" Quantidade: ");

    scanf("%d", &p[*qtd].quantidade);

    getchar();

    (*qtd)++;

    printf(" Produto cadastrado com sucesso");

    pausar();
}

void listarProduto(struct Produto p[],int *qtd){

    limparTela();

    if (qtd == 0)
    {
        printf(" Nenhum produto Cadrastado\n");


    }else{

        printf("\n======== Lista produtos =======\N");


        printf("%-10D | %-20S | %-10.2f | %-10d\n",p[i].codigo,p[i].nome,p[i].preco,p[i].quantidade);

        pausar();


    }
    
}

void buscarProduto(struct Produto p[],int *qtd,int codigo){

    for ( i = 0; i < qtd; i++)
    {
        if (p[i].codigo == codigo)
        {
            return i;
        }
        
    }
    return -1;
} 

void calcularEstoque(struct Produto p[],int *qtd){

    float total = 0;

    for ( i = 0; i < qtd; i++)
    {
        total += p[i].preco * p[i].quantidade;


    }
    return total;
}