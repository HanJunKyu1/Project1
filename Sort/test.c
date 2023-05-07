void test1()
{
	int A[10] = { 10,30,80,60,90,70,50,20,40,100 };

	int k = 7;
	int n = sizeof(A) / sizeof(A[0]);

	int result = selection(A, 0, n - 1, k);

	printf("test 1: \n%d 번째 작은 원소: %d\n", k, result);
}