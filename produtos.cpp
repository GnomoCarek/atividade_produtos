#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produtos.h"

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else 
         system("clear");
    #endif
}

void pausar(){
    printf("\nPressione enter para continuar...");
    getchar();

}

void exibirMenu(){
    printf("\n======== Sistema de cadastro de produtos ========");

    printf ("1. Cadastrar produtos\n");
    printf ("2. Lista produtos\n");
    printf ("3. Buscar produto pelo codigo\n");
    printf ("4. Calcular o valor total em estoque\n");
    printf ("5. Sair\n");
    printf ("Escolha uma opcao: ");
}

void cadastrarProduto(struct Produto p[],int *qtd){

    if (*qtd >= MAX_PRODUTOS){

       printf("\nErro limite de estoque atingido\n");
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

    printf("Produto cadastrado com sucesso");

    pausar();
}

void listarProduto(struct Produto p[],int *qtd){

    int i;

    limparTela();

    if (*qtd == 0)
    {
        printf("Nenhum produto Cadrastado\n");


    }else{

        printf("\n======== Lista produtos =======\n");


        printf("%-10d | %-20s | %-10.2f | %-10d\n", p[i].codigo,p[i].nome,p[i].preco,p[i].quantidade);

        pausar();


    }
    
}

int buscarProduto(struct Produto p[],int *qtd,int codigo){

    for (int i = 0; i < *qtd; i++)
    {
        if (p[i].codigo == codigo)
        {
            return i;
        }   
    }
    return -1;
} 

float calcularEstoque(struct Produto p[],int *qtd){

    float total = 0;

    for (int i = 0; i < *qtd; i++)
    {
        total += p[i].preco * p[i].quantidade;
    }
    return total;
}
