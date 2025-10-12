/* pascal_pyramid.c
   Build Pascal's Triangle in a 2D array and print in a centered pyramid.
   Compile: gcc -std=c11 -O2 pascal_pyramid.c -o pascal_pyramid
   Run:     ./pascal_pyramid 5     -> 5 rows
            ./pascal_pyramid       -> defaults to 10 rows
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50  // max rows
#define DEFAULT_ROWS 10

int main(int argc, char *argv[]) {
    int rows = DEFAULT_ROWS;  // default value

    if (argc == 2) {
        rows = atoi(argv[1]);
        if (rows <= 0 || rows > MAX) {
            fprintf(stderr, "Please enter a positive integer (1–%d).\n", MAX);
            return 1;
        }
    } else if (argc > 2) {
        fprintf(stderr, "Usage: %s [rows]\n", argv[0]);
        return 1;
    }

    long long pascal[MAX][MAX] = {0};

    // Build Pascal’s Triangle
    for (int i = 0; i < rows; i++) {
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    // Print as pyramid
    for (int i = 0; i < rows; i++) {
        // Center alignment: spaces
        for (int s = 0; s < rows - i - 1; s++) {
            printf("   ");
        }

        // Print row values
        for (int j = 0; j <= i; j++) {
            printf("%3lld   ", pascal[i][j]);
        }
        printf("\n");
    }

    return 0;
}
