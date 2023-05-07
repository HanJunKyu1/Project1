#include "closet.h"

//점 함수
Point* closet(Point* a, int l, int r, int n) {
	if (n <= 3) {
		// 점이 3개 이하인 경우 모든 점의 거리를 비교하여 최단 거리의 점 쌍 반환
		Point* res = (Point*)malloc(sizeof(Point) * 2);
		double shortest = distance(a[r], a[l]);
		res[0] = a[l];
		res[1] = a[r];

		for (int i = l; i < r; i++) {
			for (int j = i + 1; j <= r; j++) {
				double dist = distance(a[i], a[j]);
				if (dist < shortest) {
					shortest = dist;
					res[0] = a[i];
					res[1] = a[j];
				}
			}
		}
		return res;
	}
	else {
		int m = (l + r) / 2;
		// 배열을 이진 분할하고 각각에 대해 재귀적으로 closet 함수 호출
		Point* leftRes = closet(a, l, m, m - l + 1);
		Point* rightRes = closet(a, m + 1, r, r - m);
		double leftDist = distance(leftRes[0], leftRes[1]);
		double rightDist = distance(rightRes[0], rightRes[1]);
		double minDist = (leftDist < rightDist) ? leftDist : rightDist;
		Point* middleRes = (Point*)malloc(sizeof(Point) * n);
		int count = 0;

		// 중간 영역 내에서 최단 거리의 점 쌍을 구함
		for (int i = l; i <= r; i++) {
			if (abs(a[i].x - a[m].x) <= minDist) {
				middleRes[count] = a[i];
				count++;
			}
		}

		Point* minRes = (leftDist < rightDist) ? leftRes : rightRes;
		Point* minPair = (leftDist < rightDist) ? leftRes : rightRes;
		int middleCount = 0;

		for (int i = 0; i < count - 1; i++) {
			for (int j = i + 1; j < count; j++) {
				double dist = distance(middleRes[i], middleRes[j]);
				if (dist < minDist) {
					minDist = dist;
					minPair[0] = middleRes[i];
					minPair[1] = middleRes[j];
					middleCount = 2;
				}
			}
		}

		if (middleCount == 2) {
			return minPair;
		}
		else {
			return minRes;
		}
	}
}

//거리 함수
double distance(Point a, Point b) {
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}