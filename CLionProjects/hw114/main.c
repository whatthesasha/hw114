#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define N 255

int main() {
    int W, H, j, i, n = 0;
        int a[N][N];
    int HAR[N] = {0}; // массив характеристик столбцов//
    int MAXHAR = INT_MIN;
    int MINHAR = 0;
    int fixm = 0;
    FILE *input, *output;
    input = fopen("C:\\Users\\1087235\\CLionProjects\\hw114\\input.txt", "r");
    if (input == NULL) {
        printf("Can't open file input.txt");
        return 1;
    }
    fscanf(input, "%d %d", &W, &H);

    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            fscanf(input, "%d", &a[i][j]);
        }
    }
    for (j = 0; j < W; j++) {
        for (i = 0; i < H; i++) {
            if (a[i][j] < 0 & a[i][j] % 2 != 0)
                HAR[j] += a[i][j];
        } //считаем характеристики всех столбцов//
    }
    fclose(input);
    output = fopen("C:\\Users\\1087235\\CLionProjects\\hw114\\output.txt", "w");

    if (output == NULL) {
        printf("Cant open output");
        return 1;
    }

    for (j = 0; j < W; j++) {
        if (HAR[j] > MAXHAR) {
            MAXHAR = HAR[j];
        }
        if (HAR[j] < MINHAR) {
            MINHAR = HAR[j];
        }
    } //выбираем из всех характеристик максимльную и минимальную//
        for (j = 0; j < W; j++) {
        for (i = 0; i < H; i++) {
            for (n = 0; n < W; n++) {
                if (HAR[j] > HAR[j + n]) {
                    fixm = a[i][j + n];
                    a[i][j + n] = a[i][j];
                    a[i][j] = fixm;
                }
            }
        }
    } // красиво входим в грешную жизнь и сортируем матрицу//

    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            fprintf(output, "%d ", a[i][j]);
        }
        fprintf(output, "\n");
    }
    fprintf(output, "%d %d \n", MINHAR, MAXHAR);
        fclose(output);
        return 0;
}