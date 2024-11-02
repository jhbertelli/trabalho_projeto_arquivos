#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n = 10000;  // Numero de numeros aleatorios a serem gerados
    char filename[20];
    
    // Semente para numeros aleatórios
    srand(time(0));
    
    for (j = 0; j < 10; j++) {
        // Gerar nome do arquivo
        sprintf(filename, "numberList%d.csv", j + 1);
        
        FILE *fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("Erro ao abrir o arquivo %s!\n", filename);
            return 1;
        }
        
        // Gerar numeros aleatorios e escrever no arquivo .csv
        for (i = 0; i < n; i++) {
            int num = rand() % 10000;  // Gera um numero aleatorio entre 0 e 9999
            if (i != 0) {
                fprintf(fp, ",");  // Adicionar virgula antes dos numeros, exceto o primeiro
            }
            fprintf(fp, "%d", num);
        }
        
        // Fechar o arquivo
        fclose(fp);
        
        printf("Numeros aleatorios foram salvos em %s\n", filename);
    }
    
    return 0;
}