
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define RAWS 3
#define COLS 5
#define RANGE_UP 20

int mat[RAWS][COLS];
int transposed[COLS][RAWS];

void init_matrix(int rows, int cols, int matrix[rows][cols]);
void print_matrix_generic(int rows, int cols, int matrix[rows][cols]);
void* transpose_row(void* arg);
void validate_transpose();

typedef struct {
    int row;
} thread_arg;

// Initialize the matrix with random numbers
void init_matrix(int rows, int cols, int matrix[rows][cols]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % RANGE_UP + 1;
        }
    }
}

// Print the matrix with generic dimensions
void print_matrix_generic(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Thread function to transpose a row into a column
void* transpose_row(void* arg) {
    thread_arg* args = (thread_arg*)arg;
    int row = args->row;

    for (int i = 0; i < COLS; i++) {
        transposed[i][row] = mat[row][i];
    }
    pthread_exit(NULL);
}

// Validate that the transposed matrix is correct
void validate_transpose() {
    for (int i = 0; i < RAWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mat[i][j] != transposed[j][i]) {
                printf("Error: Transpose failed at [%d][%d]\n", i, j);
                return;
            }
        }
    }
    printf("Transpose validation passed!\n");
}

int main() {
    pthread_t threads[RAWS];
    thread_arg args[RAWS];

    // Initialize the matrix
    init_matrix(RAWS, COLS, mat);
    printf("Original Matrix:\n");
    print_matrix_generic(RAWS, COLS, mat);

    // Create threads to transpose rows
    for (int i = 0; i < RAWS; i++) {
        args[i].row = i;
        if (pthread_create(&threads[i], NULL, transpose_row, (void*)&args[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < RAWS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Print the transposed matrix
    printf("Transposed Matrix:\n");
    print_matrix_generic(COLS, RAWS, transposed);

    // Validate the result
    validate_transpose();

    return 0;
}
