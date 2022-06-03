#include <stdio.h>
//PROTOTIPOS DAS FUNCOES UTILIZADAS
void swap(const int i, const int j, int *array);
int partition(const int inicio, const int fim, int *array);
void quicksort(const int inicio, const int fim, int *array);
void array_valors(int *array, int size);
void PrintarArray(int *array, int n);

//STRUCT PRODUTO(APENAS UM EXEMPLO)
struct Produto{
    int cod[100];

};



int main() {
    //DEFININDO O STRUCT NA MEMORIA E A VARIAVEL SIZE(TAMANHO DO ARRAY)
    struct Produto produtos_atacadao;
    int size = 0;

    printf("Digite quantos produtos voce comprou(os codigos dos produtos sao diretamente proporcionais a quantidade de produtos comprados, EX: 2 produtos e igual a 2 codigos de produto\n");
    scanf("%d",&size); // DEFININDO TAMANHO DO ARRAY
    array_valors(produtos_atacadao.cod,size);
    // CHAMANDO A FUNCAO QUICKSORT PARA ORDENAR OS VALORES DO ARRAY
    quicksort(0,size-1,produtos_atacadao.cod);
    //PRINTANDO OS VALORES ORDENADOS DO ARRAY
    PrintarArray(produtos_atacadao.cod, size);

    return 0;
}

// PROCEDIMENTO SWAP, QUE TROCA O VALOR I COM J E VICE-VERSA
void swap(const int i, const int j, int *array)
{
    int aux = array[i];
    array[i] = array[j];
    array[j] = aux;


}
// FUNCAO PARTITION, QUE BASICAMENTE SEPARA UMA LISTA EM SUB LISTAS, UTILIZANDO SEMPRE UM PIVO PARA ORDENAR E DEFININDO SUA LOCALIZACAO
int partition(const int inicio, const int fim, int *array){

    int i = inicio;


    for(int j = inicio; j<fim;j++)
    {

        if(array[j]<=array[fim])
        {

            swap(i,j,array);
            i++;

        }

    }

    swap(i,fim,array);



    return i;

}
// ALGORITMO QUICKSORT, QUE UTILIZA A POSICAO DO PRIMEIRO PIVO PARA FAZER A FUNCAO RECURSIVA CRIANDO NOVOS PIVOS PARA AS SUBLISTAS ATE FICAR TUDO ORDENADO
void quicksort(const int inicio, const int fim, int *array){



    if (inicio < fim) {

        int pivo = partition(inicio, fim, array);

        quicksort(inicio, pivo - 1, array);
        quicksort(pivo + 1, fim, array);
    }


}

void array_valors(int *array,int size){
    // DEFININDO VALORES NO ARRAY
    for (int i=0; i<size; i++)
    {
        printf("\nDigite o numero do codigo de produto %d: ",i+1);
        scanf ("%d", &array[i]);
    }
}

// PRINTA O ARRAY ORDENADO
void PrintarArray(int *array, int n) {
    printf("Numeros ordenados: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}