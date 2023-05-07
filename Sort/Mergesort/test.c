#include "mergesort.h"

void T1()
{
	int A[] = { 3,2,4,1,10,5,9,8 };
	int n = sizeof(A) / sizeof(A[0]);

	mergeSort(A, 0, n - 1);

	printf("정렬된 숫자: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return;
}

void T2()
{
	int A[] = { 78,45,87,4,98,14,2,4,6,64,46,71,1,15,35,98,83 };
	int n = sizeof(A) / sizeof(A[0]);

	mergeSort(A, 0, n - 1);

	printf("정렬된 숫자: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return;
}