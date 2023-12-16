#include <stdio.h>
#include <stdlib.h>

#define n 3

//Return double*** == 3D array
double*** mem_alloc_3D_double() {
	//Reset the matrix to NULL
	double*** mat = NULL;

	//alloc n double** to double***
	mat = (double***)malloc(sizeof(double**) * n);
	for (int i = 0; i < n; i++) {
		//alloc n double* to each double**
		(mat[i]) = (double**)malloc(sizeof(double*) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//alloc n double to each double*
			(mat[i][j]) = (double*)malloc(sizeof(double) * n);
		}
	}

	//return the matrix
	return mat;
}

void addition_3D(double*** A, double*** B) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				//Add value of A to B			
				(B)[i][j][k] += (A)[i][j][k];
			}
		}
	}
}

int main() {
	int cnt = 1;

	//Define two matrices A and B using 'mem_alloc_3D_double'
	double*** A = mem_alloc_3D_double();
	double*** B = mem_alloc_3D_double();

	//Set the amount inside the matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				A[i][j][k] = cnt;
				B[i][j][k] = cnt++;
				//the number inside the matrix increases by the row and the column of the matrix increase
			}
		}
	}

	//Add A to B with the function
	addition_3D(A, B);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				printf("%f ", B[i][j][k]);
			}
			printf("\n");
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//Free the each *double first
			free(A[i][j]);
			free(B[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		//Free **double
		free(A[i]);
		free(B[i]);
	}
	//Free ***double
	free(A);
	free(B);

	//Set A, B NULL.
	A = NULL;
	B = NULL;
}