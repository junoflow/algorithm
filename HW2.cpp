#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int low, int mid, int high);

int* A; // 수를 저장할 배열
int* B; // Merge에 필요한 배열

int main(void) {
	int n;// 수의 개수

	FILE* data; // Input.txt
	FILE* merged; // Output.txt

	int i; // 인덱스

	// Input.txt 파일 열기
	data = fopen("Input.txt", "r");
	if (data == NULL) {
		printf("error");
		return 0;
	}

	// Output.txt 파일 열기
	merged = fopen("Output.txt", "wt");
	if (merged == NULL) {
		printf("error");
		return 0;
	}

	while (1) { // test case들을 실행하는 loop

		i = 0; // index initialization

		// n 읽어오기
		fscanf(data, "%d", &n);
		printf("Numbers : %d\n", n);

		// 0이 입력되면 종료
		if (n == 0) {
			break;
		}

		// 배열 A, B 동적 할당
		A = (int*)malloc(sizeof(int) * n);
		B = (int*)malloc(sizeof(int) * n);

		// n개의 수를 A에 저장
		for (i = 0; i < n; i++) {
			fscanf(data, "%d", &A[i]);
		}

		printf("original array : [");
		printf("%d", A[0]);
		for (i = 1; i < n; i++) {
			printf(" %d", A[i]);
		}
		printf("]\n");

		// ㅣ = 1
		// ㅣ < n 이면 다음의 작업을 반복한다
		// 배열 A에서 길이가 l인 이웃한 리스트를 두 개씩 모두 merge한다
		// l = 2l
		for (int l = 1; l < n; l = 2 * l) {
			// for l - 1, i = 0, 2, 4, 6...
			// for l = 2, i = 0, 4, 8...
			for (int i = 0; i < n - 1; i += 2 * l) {
				int low = i;
				int mid = i + l - 1;
				int high;

				// 리스트가 짝수가 아니거나
				// 맨 끝의 리스트가 l보다 짧을 경우 처리

				if (i + 2 * l - 1 < n - 1) {
					high = i + 2 * l - 1;
				}
				else {
					high = n - 1;
				}

				merge(low, mid, high);
			}
		}
		
		printf("sorted array : [");
		printf("%d", A[0]);
		for (int i = 1; i < n; i++) {
			printf(" %d", A[i]);
		}
		printf("]\n");

		fprintf(merged, "%d", A[0]);
		for (i = 1; i < n; i++) {
			fprintf(merged, " %d", A[i]);
		}
		fprintf(merged, "\n");

		free(A);
		free(B);
	}

	fclose(data);
	fclose(merged);
}


void merge(int low, int mid, int high) {

	int i = low, j = mid + 1, k = low;

	// 기존 mergesort와 동일
	while (i <= mid && j <= high) {
		if (A[i] < A[j]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}

	if (i > mid) {
		while (j <= high) {
			B[k++] = A[j++];
		}
	 }
	else {
		while (i <= mid) {
			B[k++] = A[i++];
		}
	}

	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}
