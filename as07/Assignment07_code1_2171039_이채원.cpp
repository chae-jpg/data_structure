// selection_sort.cpp : Defines the entry point for the console application.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct data {
	int* id;
	int* score;
} data;

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void selection_sort(data* list, int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
			if (list->score[j] < list->score[least]) least = j;
		SWAP(list->score[i], list->score[least], temp);
		SWAP(list->id[i], list->id[least], temp);
		for (int i = 0; i < 8; i++)
			printf("%d\t %d\n", list->id[i], list->score[i]);
		printf("\n");
	}
}

void selection_sort_stable(data* list, int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
			if (list->score[j] < list->score[least]) least = j;
		SWAP(list->score[i], list->score[least], temp);
		SWAP(list->id[i], list->id[least], temp);
		int idx = i;
		while (idx > 0 && list->score[idx] == list->score[idx - 1] && list->id[idx] < list->id[idx - 1]) {
			SWAP(list->score[idx], list->score[idx - 1], temp);
			SWAP(list->id[idx], list->id[idx - 1], temp);
			idx--;
		}
	}
}

int main()
{
	int data_id[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int data_score[] = { 30, 25, 10, 20, 80, 30, 25, 10 };

	int in_size = 8;
	data* input = (data*)malloc(sizeof(data));

	input->id = data_id;
	input->score = data_score;
	
	data* input_stable = (data*)malloc(sizeof(data));
	input_stable->id = data_id;
	input_stable->score = data_score;

	//Print out the input data
	printf("Input data\n");
	for (int i = 0; i < in_size; i++)
		printf("%d\t %d\n", input->id[i], input->score[i]);
	printf("\n");

	//default selection sort
	selection_sort(input, in_size);

	//Print out the sorted data with default selection sort function
	printf("Sorted data : default\n");
	for (int i = 0; i < in_size; i++)
		printf("%d\t %d\n", input->id[i], input->score[i]);
	printf("\n");

	//stable selection sort
	selection_sort_stable(input_stable, in_size);

	//Print out the sorted data with stable selection sort
	printf("Sorted data : stable\n");
	for (int i = 0; i < in_size; i++)
		printf("%d\t %d\n", input_stable->id[i], input_stable->score[i]);
	printf("\n");

	return 0;
}

