#include <stdio.h>
#include <string.h>
typedef int inteiro;//cria um apelido para um tipo (novo tipo)
typedef struct {
    char conteudo[200];
} String;

typedef struct  {
        String nome;
        int idade;
        float altura;
       char sexo;
    } Pessoa;



int main(){

    Pessoa daniel, alexandre;
    scanf(" %199[^\n]", alexandre.nome.conteudo);
    alexandre.sexo = 'M';
    alexandre.idade = 52;
    alexandre.altura = 1.82;
    daniel = alexandre;
    printf("Sexo: %c\n", alexandre.sexo);


    return 0;
}
