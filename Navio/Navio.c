#include<stdio.h>
void main (void)
{
    float Navio[64];
    float Peso,PesoSetor1=0,PesoSetor2=0,PesoSetor3=0,PesoSetor4=0;
    int NumContainer=0,NumSetor1=0,NumSetor2=0,NumSetor3=0,NumSetor4=0;

    int i;
    for (i = 0;i<63;i++)
        Navio[i]=0;

    do
    {
        printf("Digite o Peso do container ou -1 para sair: ");
        scanf("%f", &Peso);

        if (Peso < 1 && Peso != -1)
        {
            printf("Peso do Container Invalido!\n");
        }
        if (Peso > 15)
        {
            printf("Peso do container invalido! limite de 15 toneladas\n");
        }

        if((PesoSetor1+Peso)-PesoSetor2<=15 & (PesoSetor1+Peso)-PesoSetor3<=15 & (PesoSetor1+Peso)-PesoSetor4<=15 & Peso >= 1 & Peso <=15 & NumSetor1<16)
        {
            Navio[NumContainer]=Peso;
            printf("Peso valido, container armazenado setor 1, na posicao %i \n",NumSetor1+1);
            NumContainer++;
            NumSetor1++;
            PesoSetor1+=Peso;

            if(NumSetor1==16)
            {
                printf("Setor 1 cheio! \n");
            }
        }
        else
        {
            if((PesoSetor2+Peso)-PesoSetor1<=15 & (PesoSetor2+Peso)-PesoSetor3<=15 & (PesoSetor2+Peso)-PesoSetor4<=15 & Peso >= 1 & Peso <=15 & NumSetor2<16)
            {
                Navio[NumContainer]=Peso;
                printf("Peso valido, container armazenado setor 2, na posicao %i \n",NumSetor2+1);
                NumContainer++;
                NumSetor2++;
                PesoSetor2+=Peso;

                if(NumSetor2==16)
                {
                    printf("Setor 2 cheio! \n");
                }
            }
            else
            {
                if((PesoSetor3+Peso)-PesoSetor1<=15 & (PesoSetor3+Peso)-PesoSetor2<=15 & (PesoSetor3+Peso)-PesoSetor4<=15 & Peso >= 1 & Peso <=15 & NumSetor3<16)
                {
                    Navio[NumContainer]=Peso;
                    printf("Peso valido, container armazenado setor 3, na posicao %i \n",NumSetor3+1);
                    NumContainer++;
                    NumSetor3++;
                    PesoSetor3+=Peso;

                    if(NumSetor3==16)
                    {
                        printf("Setor 3 cheio! \n");
                    }
                }
                else
                {
                    if((PesoSetor4+Peso)-PesoSetor1<=15 & (PesoSetor4+Peso)-PesoSetor2<=15 & (PesoSetor4+Peso)-PesoSetor3<=15 & Peso >= 1 & Peso <=15 & NumSetor4<16)
                    {
                        Navio[NumContainer]=Peso;
                        printf("Peso valido, container armazenado setor 4, na posicao %i \n",NumSetor4+1);
                        NumContainer++;
                        NumSetor4++;
                        PesoSetor4+=Peso;

                        if(NumSetor4==16)
                        {
                            printf("Setor 4 cheio! \n");
                        }
                    }
                    else
                    {
                        if(Peso>=1 && Peso <=15)
                            printf("Nao e possivel armazenar esse container neste navio !");
                    }
                }
            }
        }

        if(Peso >=1 && Peso <=15 )
            printf("\nPeso setor 1: %.3f ## Containers setor 1: %i ## Peso Setor 2: %.3f ## Containers setor 2: %i ## \nPeso setor 3: %.3f ## Containers setor 3: %i ## Peso setor 4: %.3f ## Containers setor 4: %i ##\n\n",PesoSetor1,NumSetor1,PesoSetor2,NumSetor2,PesoSetor3,NumSetor3,PesoSetor4,NumSetor4);

    }while(Peso != -1 && NumContainer < 64);

    if(Peso!=-1)
        printf("Navio Cheio! o programa sera encerrado");
}
