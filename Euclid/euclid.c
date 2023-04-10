//���
int euclideRecursion(int a, int b) {
	//���� ����
	if (b == 0)
		return a;

	else
		return euclideRecursion(b, a % b);
}

//�ݺ�
int euclideRepeat(int a, int b) {
	int i;

	while (b != 0){
		i = a % b;
		a = b;
		b = i;
	}
	return a;
}