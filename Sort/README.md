선택 문제 알고리즘

```c
//함수 전방선언 헤더파일
#pragma once

int dividePivot(int A[], int left, int right);
int selection(int A[], int left, int right, int k);
void fileInOut();

void test1();
```

```c
//알고리즘 코드
int dividePivot(int A[], int left, int right)
{

	// 피봇을 A[left]~A[right]에서 랜덤하게 선택
	int pivotNum = left + rand() % (right - left + 1);
	int pivot = A[pivotNum];

	// 피봇과 A[left]의 자리를 바꿈
	int temp = A[left];
	A[left] = A[pivotNum];
	A[pivotNum] = temp;

	// 피봇보다 작은 숫자는 A[left+1]~A[p-1]로 옮기고, 피봇보다 큰 숫자는 A[p+1]~A[right]로 옮김
	int p = left + 1; // 피봇의 새로운 위치
	for (int i = left + 1; i <= right; i++) {
		if (A[i] < pivot) {
			temp = A[i];
			A[i] = A[p];
			A[p] = temp;
			p++;
		}
	}

	// 피봇을 A[p]에 놓음
	temp = A[left];
	A[left] = A[p - 1];
	A[p - 1] = temp;

	return p - 1; // 피봇의 인덱스 반환
}

int selection(int A[], int left, int right, int k) {
	if (left == right) { // 배열에 하나의 원소만 남은 경우
		return A[left];
	}

	int p = dividePivot(A, left, right); // 피봇을 선택하고 분할

	int S = (p - 1) - left + 1; // Small group의 크기

	if (k <= S) {
		return selection(A, left, p - 1, k); // Small group에서 k 번째 작은 수를 찾음
	}
	else if (k == S + 1) {
		return A[p]; // 피봇이 k 번째 작은 수인 경우
	}
	else {
		return selection(A, p + 1, right, k - S - 1); // Large group에서 (k - S - 1) 번째 작은 수를 찾음
	}
}
```

```c
//
void fileInOut()
{
	int A[12];
	int count = 0;

	FILE* fp = NULL;

	if (fopen_s(&fp, "data.txt", "r") == 0) {
		while (fscanf_s(fp, "%d", &A[count]) == 1) {
			count++;
		}
		fclose(fp);
	}
	else {
		printf("파일작업 실패.\n");
		return;
	}

	int k = 7;
	int n = count;

	int result = selection(A, 0, n - 1, k);

	printf("%d 번째 작은 원소: %d\n", k, result);

	if (fopen_s(&fp, "Result.txt", "w") == 0) {
		fprintf(fp, "%d", result);
		fclose(fp);
		printf("파일작업 성공.\n");
	}
	else 
	{
		printf("파일작업 실패.\n");
	}
}
```

```c
//테스트 케이스1
void test1()
{
	int A[10] = { 10,30,80,60,90,70,50,20,40,100 };

	int k = 10;
	int n = sizeof(A) / sizeof(A[0]);

	int result = selection(A, 0, n - 1, k);

	printf("test 1: \n%d 번째 작은 원소: %d\n", k, result);
}
```

```c
//메인 함수
#include <stdio.h>
#include "selection.h"

int main() 
{
	test1();
	fileInOut();

	return 0;
}
```
