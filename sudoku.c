
#include <stdio.h>

int main() {
    int a[9][9], i, j, k, valid = 1;

    printf("Enter the Sudoku board (9x9):\n");

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < 9; i++) {
        int row[10] = {0};
        int col[10] = {0};

        for (j = 0; j < 9; j++) {
            if (a[i][j] < 1 || a[i][j] > 9 ||
                row[a[i][j]] == 1) {
                valid = 0;
                break;
            }
            row[a[i][j]] = 1;

            if (a[j][i] < 1 || a[j][i] > 9 ||
                col[a[j][i]] == 1) {
                valid = 0;
                break;
            }
            col[a[j][i]] = 1;
        }
    }

    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            int box[10] = {0};

            for (k = 0; k < 9; k++) {
                int r = i + k / 3;
                int c = j + k % 3;

                if (a[r][c] < 1 || a[r][c] > 9 ||
                    box[a[r][c]] == 1) {
                    valid = 0;
                    break;
                }

                box[a[r][c]] = 1;
            }
        }
    }

    if (valid)
        printf("Valid Sudoku Board");
    else
        printf("Invalid Sudoku Board");

    return 0;
}

