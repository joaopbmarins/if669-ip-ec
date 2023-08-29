#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
João Pedro Barbosa Marins
jpbm
EC 2023.1 MP 2
*/

typedef struct{
    char nome[50];
    char raca[50];
    int idade;
    float salario;
    char cpf[12];
} Pessoa;

typedef struct{
    char nome[50];
    int codigo;
    Pessoa* cidadaos;
    int capacidade;
} Cidade;

Cidade* NovaCidade(Cidade *censo, int *tam);
void InserirOuAtualizar(Cidade *censo, int tam);
void Remover(Cidade *censo,  int tam);
void Procura(Cidade *censo, int tam);
void ViewTable(Cidade *censo, int tam);
void Desaloca(Cidade *censo, int tam);


int main(){
    Cidade *censo=NULL;
    int tam=0, menu=1, opcao;

    do{//menu
        printf("\n\nDigite o número ao lado da função desejada:\n");
        printf("\t1.Cadastrar nova cidade\n\t2.Procurar CPF\n\t3.Ver todos os dados cadastrados\n\t4.Adicionar ou atualizar dados de uma pessoa\n\t5.Remover uma pessoa\n\t6.Encerra o programa\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1://cadastrar cidade
            censo = NovaCidade(censo, &tam);
            break;

        case 2://procurar informacoes de um cpf
            Procura(censo, tam);
            break;

        case 3://ver todos os dados registrados
            ViewTable(censo, tam);
            break;

        case 4://adicionar ou atualizar dados de uma pessoa
            InserirOuAtualizar(censo, tam);
            break;

        case 5://remove uma pessoa
            Remover(censo, tam);
            break;

        case 6://encerra o programa
            printf("Finalizando o programa.\n");
            menu = 0;
            break;
        
        default:
            printf("Opcao invalida tente novamente.\n");
            break;
        }

    }while(menu!=0);

    Desaloca(censo,tam);//free nos ponteiros

    return 0;
}

void Desaloca(Cidade *censo, int tam){
    for(int i=0;i<tam;i++){//pecorre todas as cidades dando free nos cidadaos
        free(censo[i].cidadaos);
    }
    free(censo);//free no censo
}

Cidade *NovaCidade(Cidade *censo, int *tam){
    char nome_cidade[50];
    int codigo_local;//indice pra cidade
    printf("Qual é o nome da cidade que vai ser cadastrada? ");
    scanf(" %49[^\n]", nome_cidade);
    printf("Digite o codigo único da cidade: ");
    scanf("%d", &codigo_local);

    Cidade *aux = censo;
    censo = (Cidade *) realloc(censo, (*tam+1)*sizeof(Cidade));//aumenta o tamanho do ponteiro censo para caber a nova cidade
    if(censo == NULL){//caso realloc falhe
        printf("problema na alocacao.\n");
        Desaloca(aux, *tam);
        exit(1);
    }
    strcpy(censo[*tam].nome, nome_cidade);//preenche a cidade nova 
    censo[*tam].codigo = codigo_local;
    censo[*tam].capacidade = 0;
    censo[*tam].cidadaos = NULL;
    (*tam)++;
    return censo;//retorna o novo ponteiro de censo
}

void InserirOuAtualizar(Cidade *censo, int tam){
    char cpf[12];
    int codigo_cidade, indice_cidade;
    printf("Qual é o codigo da cidade da pessoa que está sendo cadastrada ou atualizada? ");
    scanf("%d", &codigo_cidade);
    printf("Qual é o cpf da pessoa que vai ser cadastrada ou atualizada? ");
    scanf(" %s", cpf);

    for(int i=0;i<tam;i++){//procura o indice verdadeiro da cidade e armazena em indice_cidade
        if(censo[i].codigo == codigo_cidade){
            indice_cidade = i;
        }
    }
    int qtd_pessoas_na_cidade = censo[indice_cidade].capacidade;//variavel para deixar mais organizado o for
    int indice_cpf = -1;//declara indice_cpf como -1 para caso não ache a variavel ele identificar q nao foi encontrado pelo valor -1

    for(int i=0;i<qtd_pessoas_na_cidade && indice_cpf == -1;i++){//procura se ja existe o cpf e coloca o indice verdadeiro na variavel indice_cpf
        if(strcmp(cpf, censo[indice_cidade].cidadaos[i].cpf)==0){
            indice_cpf = i;
        }
    }
    if(indice_cpf== -1){//nao achou a pessoa
        Pessoa *aux1 = censo[indice_cidade].cidadaos;//FALTOU
        censo[indice_cidade].cidadaos = (Pessoa *) realloc(censo[indice_cidade].cidadaos, (qtd_pessoas_na_cidade+1) * sizeof(Pessoa));
        if(censo[indice_cidade].cidadaos == NULL){//caso realloc falhe
            printf("Erro na alocacao\n");
            free(aux1);//FALTOU
            Desaloca(censo, tam);
            exit(1);
        }
        indice_cpf = qtd_pessoas_na_cidade;// usa qtd_pessoas_na_cidade para ir pra ultima posicao(nova posicao criada recentemente) do vetor
        censo[indice_cidade].capacidade += 1;//incrementa a quantidade de pessoas na struct censo na respectiva cidade
    }
    Pessoa pessoa_add;
    strcpy(pessoa_add.cpf, cpf);
    printf("Qual é o nome da pessoa? ");
    scanf(" %49[^\n]", pessoa_add.nome);
    printf("Qual é a raca da pessoa? ");
    scanf(" %49[^\n]", pessoa_add.raca);
    printf("Qual é a idade da pessoa? ");
    scanf("%d", &pessoa_add.idade);
    printf("Qual é o salario da pessoa? ");
    scanf("%f", &pessoa_add.salario);//recebe as novas informacoes do usuario

    censo[indice_cidade].cidadaos[indice_cpf] = pessoa_add;
    printf("Pessoa adicionada/atualizada com sucesso\n");
}

void Remover(Cidade *censo,  int tam){
    char cpf[12];
    int codigo_cidade, indice_cidade;
    printf("Digite o cpf da pessoa a ser removida: ");
    scanf(" %s", cpf);
    printf("Digite o codigo da cidade da pessoa a ser removida: ");
    scanf("%d", &codigo_cidade);

    for(int i=0;i<tam;i++){//procura o indice verdadeiro da cidade
        if(censo[i].codigo == codigo_cidade){
            indice_cidade = i;
        }
    }
    int qtd_pessoas_na_cidade = censo[indice_cidade].capacidade;
    int indice_cpf;
    for(int i=0;i<qtd_pessoas_na_cidade;i++){
        if(strcmp(cpf, censo[indice_cidade].cidadaos[i].cpf)==0){
            indice_cpf = i;
        }
    }

    if(indice_cpf != (qtd_pessoas_na_cidade-1)){
        Pessoa aux;//realiza um swap da pessoa na ultima posicao com a pessoa que vai ser removida
        aux = censo[indice_cidade].cidadaos[indice_cpf];
        censo[indice_cidade].cidadaos[indice_cpf] = censo[indice_cidade].cidadaos[qtd_pessoas_na_cidade-1];
        censo[indice_cidade].cidadaos[qtd_pessoas_na_cidade-1] = aux;
    }
    Pessoa *aux1 = censo[indice_cidade].cidadaos;//FALTOU
    censo[indice_cidade].cidadaos = (Pessoa *) realloc(censo[indice_cidade].cidadaos, (qtd_pessoas_na_cidade-1) * sizeof(Pessoa));//diminui o tamanho do vetor dinamico para remover a pessoa
    if(censo[indice_cidade].cidadaos == NULL){
        printf("problema de alocacao\n");
        free(aux1);//FALTOU
        Desaloca(censo, tam);
        exit(1);
    }
    censo[indice_cidade].capacidade -= 1;
    printf("Pessoa removida com sucesso");
}

void Procura(Cidade *censo, int tam){
    char cpf[12];
    int codigo_cidade, indice_cidade=-1;//declara indice_cidade como -1 para caso nao ache a cidade possa utilizar isso como referencia
    printf("Digite o cpf da pessoa que vai ser procurada: ");
    scanf(" %s", cpf);
    printf("Digite o codigo da cidade da pessoa que vai ser procurada: ");
    scanf("%d", &codigo_cidade);

    for(int i=0;i<tam;i++){
        if(censo[i].codigo == codigo_cidade){
            indice_cidade = i;
        }
    }
    int qtd_pessoas_na_cidade = censo[indice_cidade].capacidade;
    int indice_cpf = -1;//declara indice_cpf como -1 para caso não ache cpf no cidadaos da cidade possa utilizar isso como referencia
    for(int i=0;i<qtd_pessoas_na_cidade;i++){
        if(strcmp(cpf, censo[indice_cidade].cidadaos[i].cpf)==0){
            indice_cpf = i;
        }
    }

    if(indice_cidade == -1 || indice_cpf == -1){//testa se indice_cidade ou indice_cpf tem o valor -1 pois se tiver nao foi possivel achar a cidade ou a pessoa
        printf("\nErro: CPF não encontrado na cidade desejada ou cidade não encontrada\n");
    }
    else{//caso contrario printa as informacoes da pessoa
        printf("\nNome: %s\n", censo[indice_cidade].cidadaos[indice_cpf].nome);
        printf("Raca: %s\n", censo[indice_cidade].cidadaos[indice_cpf].raca);
        printf("Idade: %d\n", censo[indice_cidade].cidadaos[indice_cpf].idade);
        printf("Salario: %.2f\n", censo[indice_cidade].cidadaos[indice_cpf].salario);
        printf("CPF: %s\n", censo[indice_cidade].cidadaos[indice_cpf].cpf);
    }
}

void ViewTable(Cidade *censo, int tam){
    for(int i=0;i<tam;i++){
        printf("\nCidade: %s\n", censo[i].nome);
        printf("Capacidade: %d\n", censo[i].capacidade);
        printf("Codigo Unico: %d\n", censo[i].codigo);
        int qtd_pessoas_cidade = censo[i].capacidade;
        for(int j=0;j<qtd_pessoas_cidade;j++){
            printf("\n\tNome: %s\n", censo[i].cidadaos[j].nome);
            printf("\tRaca: %s\n", censo[i].cidadaos[j].raca);
            printf("\tIdade: %d\n", censo[i].cidadaos[j].idade);
            printf("\tSalario: %.2f\n", censo[i].cidadaos[j].salario);
            printf("\tCPF: %s\n", censo[i].cidadaos[j].cpf);
        }
        printf("--Final %s--\n", censo[i].nome);
    }
}