#include <stdio.h>

//다중리턴값을 위한 구조체
typedef struct calCoin{
	int n500;
	int n100;
	int n50;
	int n10;
}coins;


//구조체 리턴 값
coins result(int money) {
	coins n;
	int r;

	n.n500 = money / 500;
	r = money % 500;
	n.n100 = r / 100;
	r = r % 100;
	n.n50 = r / 50;
	r = r % 50;
	n.n10 = r / 10;
	r = r % 10;

	return n;
}

//메인
int main() {
	coins C;
	int money = 760;
	
	C = result(money);

	printf("%d  %d  %d  %d", C.n500, C.n100, C.n50, C.n10);
}