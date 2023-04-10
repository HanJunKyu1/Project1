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

