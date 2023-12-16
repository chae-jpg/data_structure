#include <stdio.h>

#define ROWS 6 
#define COLS 6
#define MAX_TERMS 10

typedef struct {
	int row;
	int col;
	int value;
} element;
typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} SparseMatrix;

int main() {
	//Define sparse matrix B
	SparseMatrix B = { {{0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}}, 6, 6, 7 };
	SparseMatrix Bt = B;

	for (int i = 0; i < Bt.terms; i++) {
		int t = 0;
		t = Bt.data[i].col;
		Bt.data[i].col = Bt.data[i].row;
		Bt.data[i].row = t;
	}
	
	for (int i = 1; i < Bt.terms; i++) {
		element key = Bt.data[i];
		int j;
		for (j = i - 1; j >= 0 && Bt.data[j].row > key.row; j--) {
			Bt.data[j + 1] = Bt.data[j];
		}
		Bt.data[j + 1] = key;
	}

	int b[ROWS][COLS] = {0};
	int bt[ROWS][COLS] = { 0 };

	for (int i = 0; i < B.terms; i++) {
		int key_row = B.data[i].row, key_col = B.data[i].col, key_val = B.data[i].value;
		b[key_row][key_col] = key_val;
	}
	for (int i = 0; i < Bt.terms; i++) {
		int key_row = Bt.data[i].row, key_col = Bt.data[i].col, key_val = Bt.data[i].value;
		bt[key_row][key_col] = key_val;
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d ", bt[i][j]);
		}
		printf("\n");
	}
}