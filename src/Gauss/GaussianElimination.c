#include "../../lib/log_common.h"

int control(int **matrix, int column, int row) {
    if (column != row) return EXIT_FAILURE;

    for (int i = 0; i < row; i++) {
        int zeros = 0;
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] != 0)break;
            zeros++;
        }
        if (zeros == column) {
            write_on_log("GaussianElimination/control", "row equal zero", sizeof("row equal zero"));
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int elimination(int **matrix, int column, int row) {

    if (control(matrix, column, row) == EXIT_FAILURE)return EXIT_FAILURE;

    return EXIT_SUCCESS;
}