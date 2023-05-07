
int dividePivot(int A[], int left, int right)
{

	// �Ǻ��� A[left]~A[right]���� �����ϰ� ����
	int pivotIndex = left + rand() % (right - left + 1);
	int pivot = A[pivotIndex];

	// �Ǻ��� A[left]�� �ڸ��� �ٲ�
	int temp = A[left];
	A[left] = A[pivotIndex];
	A[pivotIndex] = temp;

	// �Ǻ����� ���� ���ڴ� A[left+1]~A[p-1]�� �ű��, �Ǻ����� ū ���ڴ� A[p+1]~A[right]�� �ű�
	int p = left + 1; // �Ǻ��� ���ο� ��ġ
	for (int i = left + 1; i <= right; i++) {
		if (A[i] < pivot) {
			temp = A[i];
			A[i] = A[p];
			A[p] = temp;
			p++;
		}
	}

	// �Ǻ��� A[p]�� ����
	temp = A[left];
	A[left] = A[p - 1];
	A[p - 1] = temp;

	return p - 1; // �Ǻ��� �ε��� ��ȯ
}

int selection(int A[], int left, int right, int k) {
	if (left == right) { // �迭�� �ϳ��� ���Ҹ� ���� ���
		return A[left];
	}

	int p = dividePivot(A, left, right); // �Ǻ��� �����ϰ� ����

	int S = (p - 1) - left + 1; // Small group�� ũ��

	if (k <= S) {
		return selection(A, left, p - 1, k); // Small group���� k ��° ���� ���� ã��
	}
	else if (k == S + 1) {
		return A[p]; // �Ǻ��� k ��° ���� ���� ���
	}
	else {
		return selection(A, p + 1, right, k - S - 1); // Large group���� (k - S - 1) ��° ���� ���� ã��
	}
}