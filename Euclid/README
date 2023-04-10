코드 및 테스트 케이스

test함수헤더파일
```c
#pragma once
//함수 전방 선언
int testEuclideRecursion();
int testEuclideRepeat();
int randTestEuclideRecursion();
int randTestEuclideRepeat();
```


eucild함수헤더파일
```euclid.h
#pragma once
//함수 전방선언
int euclideRecursion(int a, int b);
int euclideRepeat(int a, int b);
```


최대공약수 계산 함수
```c
//재귀
int euclideRecursion(int a, int b) {
	//종료 조건
	if (b == 0)
		return a;

	else
		return euclideRecursion(b, a % b);
}

//반복
int euclideRepeat(int a, int b) {
	int i;

	while (b != 0){
		i = a % b;
		a = b;
		b = i;
	}
	return a;
}
```


테스트 케이스
```test.c
#include <stdio.h>
#include "euclid.h"

int testEuclideRecursion() {
	int result = 0;

	result = euclideRecursion(24, 14);

	printf("재귀함수 최대 공약수: %d\n", result);
	printf("--------------------------------------------------------------------------------\n\n");
}


int randTestEuclideRecursion() {
	int result = 0; int a = 0; int b = 0;

	srand((unsigned int)time(NULL));

	a = rand() % 32767 + 1000;
	b = rand() % 32766 + 1000;

	printf("a값: %d\n", &a);
	printf("b값: %d\n\n", &b);
	result = euclideRecursion(a, b);

	printf("랜덤 재귀함수 최대 공약수: %d\n", result);
	printf("--------------------------------------------------------------------------------\n\n");
}


int testEuclideRepeat() {
	int result = 0;

	result = euclideRepeat(24, 14);

	printf("반복함수 최대 공약수: %d\n", result);
	printf("--------------------------------------------------------------------------------\n\n");
}


int randTestEuclideRepeat() {
	int result = 0; int a = 0; int b = 0;

	srand((unsigned int)time(NULL));

	a = rand() % 32767 + 1000;
	b = rand() % 32766 + 1000;

	printf("a값: %d\n", &a);
	printf("b값: %d\n\n", &b);

	result = euclideRepeat(a, b);

	printf("랜덤 반복함수 최대 공약수: %d\n", result);
}
```


메인함수
```main.c
#include <stdio.h>
#include "euclid.h"
#include "test.h"

int main() {
	testEuclideRecursion();
	randTestEuclideRecursion();
	testEuclideRepeat();
	randTestEuclideRepeat();
}
```
