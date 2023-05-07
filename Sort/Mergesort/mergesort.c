#include "mergesort.h"

void merge(int A[], int p, int k, int q) {
	int ci = 0, ai = p, bi = k + 1;
	int* C = (int*)malloc((q - p + 1) * sizeof(int));

	while (ai <= k && bi <= q) {
		if (A[ai] < A[bi]) {
			C[ci++] = A[ai++];
		}
		else {
			C[ci++] = A[bi++];
		}
	}

	while (ai <= k) {
		C[ci++] = A[ai++];
	}

	while (bi <= q) {
		C[ci++] = A[bi++];
	}

	ci = 0;
	ai = p;

	while (ai <= q) {
		A[ai++] = C[ci++];
	}
	free(C);
}

void mergeSort(int A[], int p, int q) {
	if (p < q) {
		int k = (p + q) / 2;

		mergeSort(A, p, k);
		mergeSort(A, k + 1, q);

		merge(A, p, k, q);
	}
}
