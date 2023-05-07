
int dividePivot(int A[], int left, int right)
{

	// 피봇을 A[left]~A[right]에서 랜덤하게 선택
	int pivotNum = left + rand() % (right - left + 1);
	int pivot = A[pivotNum];

	// 피봇과 A[left]의 자리를 바꿈
	int temp = A[left];
	A[left] = A[pivotNum];
	A[pivotNUm] = temp;

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
