#include <stdio.h>
#include <stdlib.h>

#define texto "entrada e saida de dado."

int main(){

    printf("%s\n", texto);

    int age = 0;
    float altura = 0.0;
    char name[50] = "";

    printf("Digire a sua idade: \n");
    scanf("%d", &age);

    printf("Digite a sua altura: \n");
    scanf("%f", &altura);

    printf("Digite seu nome:\n");
    scanf("%s", name);

    system("cls"); //limpar tela

    printf("Dados informados são: \n");
    printf("Idade informada é: %d. \n", age);
    printf("Altura informada é: %.2f. \n", altura);
    printf("Nome informado é: %s. \n", name);
}