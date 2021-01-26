#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct{char nome[100];int telefone;char email[100];char endereco[100];}Contato;

void flush_in(){
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main ()
{
    setlocale(LC_ALL,"Portuguese");
    int opcao, cont=0, tam = 10;
    Contato *contatos;
    contatos = (Contato *)malloc(tam*sizeof(Contato));

    int cmpfuncNome(const void * a, const void *b)
    {
        Contato	*c1 = (Contato*) a;
        Contato	*c2 = (Contato*) b;

        return strcmp(c1->nome, c2->nome);
    }

    int cmpfuncEmail(const void * a, const void *b)
    {
        Contato	*c1 = (Contato*) a;
        Contato	*c2 = (Contato*) b;

        return strcmp(c1->email, c2->email);
    }

    int cadastrar(int cont)
    {
        printf("Digite o nome do contato: ");
        flush_in();
        gets(contatos[cont].nome);

        printf("Digite o Telefone: ");
        scanf("%i", &contatos[cont].telefone);

        printf("Digite o Email do contato: ");
        flush_in();
        gets(contatos[cont].email);

        printf("Digite o Endereço do contato: ");
        gets(contatos[cont].endereco);

        printf("Contato salvo com sucesso!\n\n");
        cont++;

        return cont;
    }

    void pesquisarEmail()
    {
        char pesquisa[100];
        int i;
        printf("Digite o E-Mail: ");
        scanf("%s",&pesquisa);
        for(i=0;i<tam;i++)
        {
            if(strstr(contatos[i].email,pesquisa) != NULL)
                printf("\nNome: %s\nTelefone: %i\nE-Mail: %s\nEndereço: %s\n",contatos[i].nome,contatos[i].telefone,contatos[i].email,contatos[i].endereco);
        }
    }

    void pesquisarNome()
    {
        char pesquisa[100];
        int i;
        printf("Digite o Nome: ");
        scanf("%s",&pesquisa);
        for(i=0;i<tam;i++)
        {
            if(strstr(contatos[i].nome,pesquisa) != NULL)
                printf("\nNome: %s\nTelefone: %i\nE-Mail: %s\nEndereço: %s\n",contatos[i].nome,contatos[i].telefone,contatos[i].email,contatos[i].endereco);
        }
    }

    void ListarNome(int cont)
    {
        int i;
        qsort(contatos,cont,sizeof(Contato), cmpfuncNome);
        for(i=0;i<cont;i++)
        {
            printf("\n%i- Nome: %s",i+1, contatos[i].nome);
            printf("\nTelefone: %i",contatos[i].telefone);
            printf("\nE-Mail: %s",contatos[i].email);
            printf("\nEndereço: %s\n",contatos[i].endereco);
        }
    }

    void ListarEmail(int cont)
    {
        int i=0;
        qsort(contatos,cont,sizeof(Contato), cmpfuncEmail);
        for(i=0;i<cont;i++)
        {
            printf("\n%i- Nome: %s",i+1, contatos[i].nome);
            printf("\nTelefone: %i",contatos[i].telefone);
            printf("\nE-Mail: %s",contatos[i].email);
            printf("\nEndereço: %s\n\n",contatos[i].endereco);
        }
    }

    void Alterar()
    {
        char escolha[100];

        printf("Qual contato deseja alterar? ");
        flush_in();
        gets(escolha);

        int i;
        for(i=0;i<cont;i++)
        {
            if(strcmp(escolha,contatos[i].nome)== 0)
            {
                printf("\nContato Encontrado\n");
                printf("Qual campo deseja alterar?\n");
                printf("1- Nome\n");
                printf("2- Telefone\n");
                printf("3- E-Mail\n");
                printf("4- Endereço\n");
                int campo;
                char altera[100];
                scanf("%i",&campo);
                switch(campo)
                {
                    case 1:
                    printf("Escreva o Nome: ");
                    flush_in();
                    gets(contatos[i].nome);
                    break;

                    case 2:
                    printf("Escreva o Telefone: ");
                    flush_in();
                    scanf("%i",contatos[i].telefone);
                    break;

                    case 3:
                    printf("Escreva o E-Mail: ");
                    flush_in();
                    gets(contatos[i].email);
                    break;

                    case 4:
                    printf("Escreva o Endereço: ");
                    flush_in();
                    gets(contatos[i].endereco);
                    break;
                }
            }
        }
    }

    do
    {
        printf("########################MENU########################\n");
        printf("1- Cadastrar Contato\n");
        printf("2- Pesquisar contato pelo E-Mail\n");
        printf("3- Pesquisar contato pelo nome\n");
        printf("4- Listar todos os contatos ordenados pelo nome\n");
        printf("5- Listar todos os contatos ordenados pelo E-Mail\n");
        printf("6- Alterar dados de um contato\n");
        printf("7- Sair\n");
        printf("Selecione uma opção: ");
        scanf("%i",&opcao);
        switch(opcao)
        {
            case 1:
            cont = cadastrar(cont);
            if(cont == tam-1)
            {
                contatos = (Contato *)realloc(contatos, sizeof(contatos)+10);
                tam+=10;
            }
            break;

            case 2:
            pesquisarEmail();
            break;

            case 3:
            pesquisarNome();
            break;

            case 4:
            ListarNome(cont);
            break;

            case 5:
            ListarEmail(cont);

            case 6:
            Alterar();
        }
    }while(opcao != 7);
    free(contatos);
    return 0;
}
