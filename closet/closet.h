#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _point {
	int x;
	int y;
} Point;

Point* closet(Point* a, int l, int r, int n);
double distance();
void TC1();