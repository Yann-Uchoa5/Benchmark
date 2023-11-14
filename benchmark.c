#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Função para realizar a operação de merge em duas partes ordenadas do array

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    
// Copia os dados para arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
        
// Combina os arrays temporários de volta ao arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

// Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
// Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal para realizar o merge sort em um array
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Função recursiva para calcular o fatorial de um número
int fatorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fatorial(n - 1);
}

// Função recursiva para calcular o somatório de 1 até n
int somatorio(int n) {
    if (n == 0)
        return 0;
    else
        return n + somatorio(n - 1);
}

// Função recursiva para calcular o termo da sequência de Fibonacci

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Função para gerar um arquivo com números aleatórios
void gerarArquivo(const char *nomeArquivo, int quantidade) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");
    if (arquivo != NULL) {
        for (int i = 0; i < quantidade; i++) {
            int numero = rand() % 1000;
            fprintf(arquivo, "%d ", numero);
        }
        fclose(arquivo);
        printf("Arquivo gerado com sucesso!\n");
    } else {
        perror("Erro ao abrir o arquivo");
    }
}

// Função de ordenação usando o algoritmo Insertion Sort
void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// Função auxiliar para o algoritmo Quick Sort: particiona o array e retorna o índice do pivô
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Função auxiliar para o algoritmo Quick Sort: particiona o array e retorna o índice do pivô
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para realizar uma busca linear em um arquivo de números
int buscaLinear(const char *nomeArquivo, int alvo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo != NULL) {
        int numero;
        int posicao = 0;
        while (fscanf(arquivo, "%d", &numero) != EOF) {
            posicao++;
            if (numero == alvo) {
                fclose(arquivo);
                return posicao;
            }
        }
        fclose(arquivo);
    } else {
        perror("Erro ao abrir o arquivo");
    }
    return -1;
}

// Função para realizar uma busca com sentinela em um arquivo de números
int buscaSentinela(const char *nomeArquivo, int alvo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo != NULL) {
        int numero;
        int posicao = 0;
        while (fscanf(arquivo, "%d", &numero) != EOF) {
            posicao++;
            if (numero == alvo) {
                fclose(arquivo);
                return posicao;
            }
        }
        fclose(arquivo);
    } else {
        perror("Erro ao abrir o arquivo");
    }
    return -1;
}

// Função para realizar uma busca binária em um arquivo de números
int buscaBinaria(const char *nomeArquivo, int alvo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo != NULL) {
        int numero;
        int posicao = 0;
        int *numeros = NULL;
        int tamanho = 0;

        while (fscanf(arquivo, "%d", &numero) != EOF) {
            tamanho++;
            numeros = (int *)realloc(numeros, tamanho * sizeof(int));
            numeros[tamanho - 1] = numero;
        }

        fclose(arquivo);

        int esquerda = 0, direita = tamanho - 1;
        int meio;

        while (esquerda <= direita) {
            posicao++;
            meio = esquerda + (direita - esquerda) / 2;

            if (numeros[meio] == alvo) {
                free(numeros);
                return posicao;
            }

            if (numeros[meio] < alvo)
                esquerda = meio + 1;
            else
                direita = meio - 1;
        }

        free(numeros);
    } else {
        perror("Erro ao abrir o arquivo");
    }
    return -1;
}

// Início da função principal
int main() {
    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));

    // Declaração de variáveis para armazenar a opção do usuário, quantidade de números e alvo de busca
    int opcao, quantidade, alvo;
    char nomeArquivo[] = "numeros.txt"; // Nome do arquivo

    // Variáveis para medir o tempo de execução
    clock_t inicio, fim;
    double tempo;

    // Solicita ao usuário a quantidade de números a serem gerados
    printf("Digite a quantidade de números a serem gerados:   \n");
    scanf("%d", &quantidade);

    // Gera e grava números aleatórios no arquivo
    gerarArquivo(nomeArquivo, quantidade);

    // Apresenta o menu de opções
    printf("\nEscolha uma opção:\n");
    printf("1- Busca de elemento\n");
    printf("2- Classificação de Elementos (Bubble Sort, Insertion Sort, Quick Sort)\n");
    printf("3- Operações extras (Merge Sort, Fatorial, Somatório, Fibonacci)\n");
    printf("4- Sair\n");
    scanf("%d", &opcao);

    // Estrutura de controle para cada opção do menu
    if (opcao == 1) {
        // Busca por elemento
        printf("Digite o número que deseja buscar: ");
        scanf("%d", &alvo);

        // Busca Linear
        inicio = clock();
        int posicaoLinear = buscaLinear(nomeArquivo, alvo);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Exibe os resultados da Busca Linear
        if (posicaoLinear != -1) {
            printf("Elemento encontrado na posição %d (Busca Linear)\n", posicaoLinear);
        } else {
            printf("Elemento não encontrado (Busca Linear)\n");
        }
        printf("Tempo de execução da Busca Linear: %f segundos\n", tempo);

        // Busca Sentinela
        inicio = clock();
        int posicaoSentinela = buscaSentinela(nomeArquivo, alvo);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Exibe os resultados da Busca Sentinela
        if (posicaoSentinela != -1) {
            printf("Elemento encontrado na posição %d (Busca Sentinela)\n", posicaoSentinela);
        } else {
            printf("Elemento não encontrado (Busca Sentinela)\n");
        }
        printf("Tempo de execução da Busca Sentinela: %f segundos\n", tempo);

        // Busca Binária
        inicio = clock();
        int posicaoBinaria = buscaBinaria(nomeArquivo, alvo);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Exibe os resultados da Busca Binária
        if (posicaoBinaria != -1) {
            printf("Elemento encontrado na posição %d (Busca Binária)\n", posicaoBinaria);
        } else {
            printf("Elemento não encontrado (Busca Binária)\n");
        }
        printf("Tempo de execução da Busca Binária: %f segundos\n", tempo);
    } else if (opcao == 2) {
        // Classificação de elementos
        int *numeros = malloc(quantidade * sizeof(int));
        FILE *arquivo = fopen(nomeArquivo, "r");

        // Lê os números do arquivo
        if (arquivo != NULL) {
            for (int i = 0; i < quantidade; i++) {
                if (fscanf(arquivo, "%d", &numeros[i]) == EOF) {
                    break;
                }
            }
            fclose(arquivo);

            // Cópias dos arrays para os algoritmos de ordenação
            int *copiaInsertionSort = malloc(quantidade * sizeof(int));
            for (int i = 0; i < quantidade; i++) {
                copiaInsertionSort[i] = numeros[i];
            }

            // Insertion Sort
            inicio = clock();
            insertionSort(copiaInsertionSort, quantidade);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo de execução do Insertion Sort: %f segundos\n", tempo);
            free(copiaInsertionSort);

            // Cópia para o Bubble Sort
            int *copiaBubbleSort = malloc(quantidade * sizeof(int));
            for (int i = 0; i < quantidade; i++) {
                copiaBubbleSort[i] = numeros[i];
            }

            // Bubble Sort
            inicio = clock();
            bubbleSort(copiaBubbleSort, quantidade);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo de execução do Bubble Sort: %f segundos\n", tempo);
            free(copiaBubbleSort);

            // Cópia para o Quick Sort
            int *copiaQuickSort = malloc(quantidade * sizeof(int));
            for (int i = 0; i < quantidade; i++) {
                copiaQuickSort[i] = numeros[i];
            }

            // Quick Sort
            inicio = clock();
            quickSort(copiaQuickSort, 0, quantidade - 1);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo de execução do Quick Sort: %f segundos\n", tempo);
            free(copiaQuickSort);
        } else {
            perror("Erro ao abrir o arquivo");
        }
        free(numeros);
    } else if (opcao == 3) {
        // Operações extras
        int *numeros = malloc(quantidade * sizeof(int));
        FILE *arquivo = fopen(nomeArquivo, "r");

        // Lê os números do arquivo
        if (arquivo != NULL) {
            for (int i = 0; i < quantidade; i++) {
                if (fscanf(arquivo, "%d", &numeros[i]) == EOF) {
                    break;
                }
            }
            fclose(arquivo);

            // Cópia para o Merge Sort
            int *copiaMergeSort = malloc(quantidade * sizeof(int));
            for (int i = 0; i < quantidade; i++) {
                copiaMergeSort[i] = numeros[i];
            }

            // Merge Sort
            inicio = clock();
            mergeSort(copiaMergeSort, 0, quantidade - 1);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo de execução do Merge Sort: %f segundos\n", tempo);
            free(copiaMergeSort);

            // Cálculo do fatorial
            printf("Digite um número para calcular o fatorial: ");
            int numFatorial;
            scanf("%d", &numFatorial);
            int resultadoFatorial = fatorial(numFatorial);
            printf("Fatorial de %d: %d\n", numFatorial, resultadoFatorial);

            // Cálculo do somatório
            printf("Digite um número para calcular o somatório até n: ");
            int numSomatorio;
            scanf("%d", &numSomatorio);
            int resultadoSomatorio = somatorio(numSomatorio);
            printf("Somatório de 1 até %d: %d\n", numSomatorio, resultadoSomatorio);

            // Cálculo do termo da sequência de Fibonacci
            printf("Digite um número para calcular o termo da sequência de Fibonacci: ");
            int numFibonacci;
            scanf("%d", &numFibonacci);
            int resultadoFibonacci = fibonacci(numFibonacci);
            printf("Termo %d da sequência de Fibonacci: %d\n", numFibonacci, resultadoFibonacci);
        } else {
            perror("Erro ao abrir o arquivo");
        }
        free(numeros);
    } else if (opcao == 4) {
        // Mensagem de encerramento do programa
        printf("Encerrando o programa. Obrigado!\n");
    } else {
        // Mensagem para opção inválida
        printf("Opção inválida!\n");
    }

    // Pausa a execução para visualização dos resultados
    system("pause");

    // Retorna 0 indicando término bem-sucedido do programa
    return 0;
}

