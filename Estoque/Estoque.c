#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct{
    int codigo;
    char nome[100];
    float quantidade;
}Produto;

Produto* abrirArquivo(int *n,int *cap);
void Cadastrar(Produto *estoque,int *n , int *cap);
void Entrada(Produto *estoque,int n);
void Baixa(Produto *estoque,int n);
void ListarCodigo(Produto *estoque,int n);
void ListarNome(Produto *estoque,int n);
void Pesquisar(Produto *estoque,int n);
void Alterar(Produto *estoque,int n);
void Remover(Produto *estoque,int *n);
void SalvarArquivo(Produto *Produtos,int n);
void flush_in();
int cmpfuncNome(const void * a,const void *b);
int cmpfuncCodigo(const void * a,const void *b );

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Produto *estoque;
    int cap;
    int n;
    int opc;

    estoque = abrirArquivo(&n,&cap);

    do
    {
        printf("*************MENU*************\n");
        printf("1- Cadastrar produto\n");
        printf("2- Fazer entrada\n");
        printf("3- Dar baixa\n");
        printf("4- Listar produto por c�digo\n");
        printf("5- Listar Produtos por nome\n");
        printf("6- Pesquisar produto\n");
        printf("7- Alterar produto\n");
        printf("8- Remover produto\n");
        printf("9- Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%i",&opc);

        switch(opc)
        {
            case 1: Cadastrar(estoque,&n,&cap); break;
            case 2: Entrada(estoque,n); break;
            case 3: Baixa(estoque,n); break;
            case 4: ListarCodigo(estoque,n); break;
            case 5: ListarNome(estoque,n); break;
            case 6: Pesquisar(estoque,n); break;
            case 7: Alterar(estoque,n); break;
            case 8: Remover(estoque,&n); break;
        }
    }while(opc != 9);

    SalvarArquivo(estoque,n);

    free(estoque);

    return 0;
}

Produto * abrirArquivo (int *n,int *cap)
{
    Produto *estoque;

    FILE *fp = fopen("estoque.dat","r");

    if(fp == NULL)
    {
        *n   = 0;
        *cap = 20;

        estoque = (Produto *)malloc(sizeof(Produto) * (*cap));
    }
    else
    {
        fread(n, sizeof(int), 1, fp);

        *cap = (*n) * 2;

        estoque = (Produto *)malloc(sizeof(Produto) * (*cap));

        fread(estoque,sizeof(Produto),*n,fp);

        fclose(fp);
  }

  return estoque;
}
void Cadastrar(Produto *estoque,int *n,int *cap)
{
    float qtde;

    if(*n == *cap)
    {
        *cap = *cap * 2;
        estoque = (Produto *)realloc(estoque, sizeof(Produto) * (*cap));
    }

    estoque[*n].codigo = *n;
    printf("Digite o nome: ");
    flush_in();
    gets(estoque[*n].nome);
    printf("Digite a quantidade: ");
    scanf("%f",&qtde);
    if(qtde >= 0) //CADASTRAR PRODUTO COM QUANTIDADE ZERO?
    {
        estoque[*n].quantidade  = qtde;
    }
    else // Caso qtde negativa
    {
        printf("\nATEN��O! QAUNTIDADE NEGATIVA.\nPRODUTO CADASTRADO COM QUANTIDADE ZERO.\nPara alterar isso fa�a uma entrada desse produto.");
        estoque[*n].quantidade = 0;
    }

    (*n) ++;
}
void Entrada(Produto *estoque,int n)
{
    int cod , i;
    float qtde;
    printf("\nDigite o código do produto que deseja fazer entrada: ");
    scanf("%i",&cod);
    for(i = 0;i < n;i++)
    {
        if(cod == estoque[i].codigo)
        {
            printf("Produto encontrado! digite a quantidade da entrada: ");
            scanf("%f",&qtde);
            if(qtde > 0)
            {
                estoque[i].quantidade += qtde;
                printf("\nEntrada registrada!\n\n");
            }
            else
            {
                printf("\nN�mero inv�lido. Digitou valor negativo\nDigite novamente: ");
                do
                {
                    scanf("%f",&qtde);
                    if(qtde <= 0)
                    {
                        printf("\nQuntidade inv�lida, Digitou n�mero negativo. Digite novamento: ");
                    }

                }while(qtde <= 0);
            }
            i = n;
        }
        else
        {
            if(i == (n-1))
            {
                printf("\nProduto n�o encontrado. Tente novamente: ");
                Entrada(estoque,n);
            }
        }
    }
}
void Baixa(Produto *estoque,int n)
{
    int cod,i;
    float qtde;
    printf("\nDigite o c�digo do produto que deseja fazer baixa: ");
    scanf("%i",&cod);
    for(i = 0;i < n;i++)
    {
        if(cod == estoque[i].codigo)
        {
            printf("Produto encontrado! digite a quantidade da baixa: ");
            scanf("%f",&qtde);
            if(qtde < 0 || qtde <= estoque[i].quantidade)
            {
                if(qtde < 0)
                {
                    estoque[i].quantidade += qtde;
                    printf("\nBaixa no estoque feita!\n\n");
                }

                if(qtde <= estoque[i].quantidade && qtde > 0)
                {
                    estoque[i].quantidade -= qtde;
                    printf("\nBaixa no estoque feita!\n\n");

                }

                if(estoque[i].quantidade == 0)
                {
                    printf("ATEN��O! ESTOQUE DO PRODUTO %i ACABOU!a\n\n",estoque[i].codigo);
                }
            }
            else
            {
                if(qtde == 0)
                {
                    printf("\nVoc� digitou zero.");
                }
                if(qtde > estoque[i].quantidade)
                {
                    printf("\nESTOQUE INSUFICIENTE\nOpera��o de baixa n�o foi feita!\n\n");
                }
            }
            i = n;
        }
        else
        {
            if(i == (n-1))
            {
                printf("\nProduto n�o encontrado. Tente novamente: ");
                Baixa(estoque,n);
            }
        }
    }
}
void ListarCodigo(Produto *estoque, int n)
{
    int i;

    qsort(estoque,n,sizeof(Produto), cmpfuncCodigo);
    for(i=0; i<n; i++)
    {
        printf("\n*** Produto %i ***\n",estoque[i].codigo);
        printf("Nome: %s\n",estoque[i].nome);
	    printf("Quantidade: %.1f\n",estoque[i].quantidade);
    }
}
void ListarNome(Produto *estoque, int n)
{
    int i;

    qsort(estoque,n,sizeof(Produto), cmpfuncNome);
    for(i=0; i<n; i++)
    {
        printf("\n*** Produto %i ***\n",estoque[i].codigo);
        printf("Nome: %s\n",estoque[i].nome);
	    printf("Quantidade: %.1f\n",estoque[i].quantidade);
    }
}
void Pesquisar(Produto *estoque, int n)
{
    char nome[100];
    int i,cod,opc;
    printf("####Deseja pesquisar por####\n1- Nome\n2- C�digo\n");
    scanf("%i",&opc);
    switch(opc)
    {
        case 1:

            printf("\nDigite o nome: ");
            flush_in();
            gets(nome);
            for(i=0;i<n;i++)
            {
                if(strstr(estoque[i].nome,nome) != NULL)
                {
                    printf("***Produto %i***\n",estoque[i].codigo);
                    printf("Nome: %s\n",estoque[i].nome);
                    printf("Quantidade: %.1f\n\n",estoque[i].quantidade);
                }
                else
                {
                    //imprimir uma mensagem de erro caso n�o encontre
                }
            }
        break;

        case 2:

            printf("\nDigite o c�digo: "); // ele s� imprime se for um c�digo exato
            scanf("%i",&cod);

            for(i=0;i<n;i++)
            {
                if(estoque[i].codigo == cod)
                {
                    printf("***Produto %i***\n",estoque[i].codigo);
                    printf("Nome: %s\n",estoque[i].nome);
                    printf("Quantidade: %.1f\n\n",estoque[i].quantidade);

                    i = n;
                }
                else
                {
                    if(i = n-1)
                    {
                        printf("\nC�digo n�o encontrado\n\n");
                    }
                }
            }
        break;
    }
}
void Alterar(Produto *estoque, int n)
{
    int i,cod;
    printf("Digite o c�digo do produto que deseja alterar: ");
    scanf("%i",&cod);
    for(i=0;i < n;i++)
    {
        if(cod == estoque[i].codigo)
        {
            printf("Produto encontrado!\n");
            printf("\nDigite o novo nome para o produto %s: ",estoque[i].nome);
            flush_in();
            gets(estoque[i].nome);
            printf("Nome do produto alterado!\n\n");

            i = n;
        }
        else
        {
            if(i == n-1)
            {
                printf("Produto n�o encontrado.Tente novamente\n\n");
                Alterar(estoque,n);
            }
        }
    }
}
void Remover(Produto *estoque,int *n)
{
    int cod,j, i;
    printf("Digite o c�digo do produto a ser removido: ");
    scanf("%i",&cod);
    for(i=0; i < *n; i++)
    {
        if (estoque[i].codigo == cod)
        {
            for(j=i+1; j < *n; j++)
            {
                strcpy(estoque[j-1].nome,estoque[j].nome);
                estoque[j-1].quantidade = estoque[j].quantidade;
                estoque[j-1].codigo = estoque[j].codigo;
            }
            (*n) --;
            i  = *n;
            printf("Produto removido\n\n");
        }
        else
        {
            if(i == (*n-1))
            {
                printf("\nProduto n�o encontrado.Tente novamente\n");
                Remover(estoque,n);
            }
        }
    }
}
void SalvarArquivo(Produto *estoque, int n)
{
    FILE *fp = fopen("estoque.dat","w");

    fwrite(&n, sizeof(int), 1, fp);

    if(n>0)
    {
    	fwrite(estoque, sizeof(Produto), n, fp);
	}

    fclose(fp);
}
void flush_in()
{
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
int cmpfuncNome(const void *a, const void *b)
{
    Produto *p1 = (Produto*) a;
    Produto *p2 = (Produto*) b;

    return strcmp(p1->nome, p2->nome);
}
int cmpfuncCodigo(const void *a, const void *b)
{
    Produto *p1 = (Produto*) a;
    Produto *p2 = (Produto*) b;

    return (p1->codigo - p2->codigo );
}
