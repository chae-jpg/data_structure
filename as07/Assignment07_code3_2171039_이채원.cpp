#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int DIGIT = 1<<6, ARR_SIZE = 1000;

int arr1[ARR_SIZE], arr2[ARR_SIZE], cnt[DIGIT];

//generates random integer from 0 to 2e24-1
int randomNum() {
	int num1 = rand() % DIGIT;
	int num2 = rand() % DIGIT;
	int num3 = rand() % DIGIT;
	int num4 = rand() % DIGIT;
	return num1 << 18 | num2 << 12 | num3 << 6 | num4;
}

int main() {
	srand(time(NULL));
	
	//constructs an array with integers
	for (int i = 0; i < ARR_SIZE; i++) {
		arr1[i] = randomNum();
	}

	memset(cnt, 0, DIGIT * sizeof(int));

	//0~5
	for (int i = 0; i < ARR_SIZE; i++) {
		unsigned long long num = arr1[i];
		num &= 63;
		cnt[num]++;
	}
	for (int i = 1; i < DIGIT; i++) {
		cnt[i] = cnt[i] + cnt[i - 1];
	}
	for (int i = ARR_SIZE - 1; i >= 0; i--) {
		unsigned long long num = arr1[i];
		num &= 63;
		arr2[cnt[num] - 1] = arr1[i];
		cnt[num]--;
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		arr1[i] = arr2[i];
	}

	memset(cnt, 0, DIGIT * sizeof(int));

	//6~11
	for (int i = 0; i < ARR_SIZE; i++) {
		unsigned long long num = arr1[i];
		num = num >> 6;
		num &= 63;

		cnt[num]++;
	}
	for (int i = 1; i < DIGIT; i++) {
		cnt[i] = cnt[i] + cnt[i - 1];
	}
	for (int i = ARR_SIZE - 1; i >= 0; i--) {
		unsigned long long num = arr1[i];
		num = num >> 6;
		num &= 63;
		arr2[cnt[num] - 1] = arr1[i];
		cnt[num]--;
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		arr1[i] = arr2[i];
	}

	//12~17
	memset(cnt, 0, DIGIT * sizeof(int));

	for (int i = 0; i < ARR_SIZE; i++) {
		unsigned long long num = arr1[i];
		num = num >> 12;
		num &= 63;

		cnt[num]++;
	}
	for (int i = 1; i < DIGIT; i++) {
		cnt[i] = cnt[i] + cnt[i - 1];
	}
	for (int i = ARR_SIZE - 1; i >= 0; i--) {
		unsigned long long num = arr1[i];
		num = num >> 12;
		num &= 63;
		arr2[cnt[num] - 1] = arr1[i];
		cnt[num]--;
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		arr1[i] = arr2[i];
	}

	//17~23
	memset(cnt, 0, DIGIT * sizeof(int));

	for (int i = 0; i < ARR_SIZE; i++) {
		unsigned long long num = arr1[i];
		num = num >> 18;

		cnt[num]++;
	}
	for (int i = 1; i < DIGIT; i++) {
		cnt[i] = cnt[i] + cnt[i - 1];
	}
	for (int i = ARR_SIZE - 1; i >= 0; i--) {
		unsigned long long num = arr1[i];
		num = num >> 18;
		arr2[cnt[num] - 1] = arr1[i];
		cnt[num]--;
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		arr1[i] = arr2[i];
	}

	for (int i = 0; i < ARR_SIZE; i++) {
		printf("%d\n", arr1[i]);
	}


}