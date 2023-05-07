#include "closet.h"

//�� �Լ�
Point* closet(Point* a, int l, int r, int n) {
	if (n <= 3) {
		// ���� 3�� ������ ��� ��� ���� �Ÿ��� ���Ͽ� �ִ� �Ÿ��� �� �� ��ȯ
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
		// �迭�� ���� �����ϰ� ������ ���� ��������� closet �Լ� ȣ��
		Point* leftRes = closet(a, l, m, m - l + 1);
		Point* rightRes = closet(a, m + 1, r, r - m);
		double leftDist = distance(leftRes[0], leftRes[1]);
		double rightDist = distance(rightRes[0], rightRes[1]);
		double minDist = (leftDist < rightDist) ? leftDist : rightDist;
		Point* middleRes = (Point*)malloc(sizeof(Point) * n);
		int count = 0;

		// �߰� ���� ������ �ִ� �Ÿ��� �� ���� ����
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

//�Ÿ� �Լ�
double distance(Point a, Point b) {
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}