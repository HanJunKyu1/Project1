#include "closet.h"

void TC1()
{
	// Test case
	Point points[] = { {0, 0}, {1, 1}, {2, 3}, {4, 4}, {5, 2}, {6, 5} };
	int numPoints = sizeof(points) / sizeof(points[0]);

	Point* closestPair = closet(points, 0, numPoints - 1, numPoints);

	printf("Closest pair: (%d, %d) and (%d, %d)\n",
		closestPair[0].x, closestPair[0].y,
		closestPair[1].x, closestPair[1].y);

	free(closestPair);

	return ;
}