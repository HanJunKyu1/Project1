#include <stdio.h>
#include "selection.h"

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
		printf("�����۾� ����.\n");
		return;
	}

	int k = 7;
	int n = count;

	int result = selection(A, 0, n - 1, k);

	printf("%d ��° ���� ����: %d\n", k, result);

	if (fopen_s(&fp, "Result.txt", "w") == 0) {
		fprintf(fp, "%d", result);
		fclose(fp);
		printf("�����۾� ����.\n");
	}
	else 
	{
		printf("�����۾� ����.\n");
	}
}