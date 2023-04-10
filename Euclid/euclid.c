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