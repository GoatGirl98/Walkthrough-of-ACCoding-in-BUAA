#include<iostream>
#include<algorithm>
#include<ctime>

using namespace std;

/*
本题的思路就是标准hanoi塔的变种
核心的问题就是要把最底下的两个分配到B和C当中，剩下的就相当于是n-1的子问题了

*/

void DoubleHanoi_Odd(int n, char A, char B, char C) {
	if (n < 1)return;
	else if (n == 1) {
		printf("Move from %c to %c\n", A, C);
	}
	else {
		DoubleHanoi_Odd(n - 1, A, C, B);
		printf("Move from %c to %c\n", A, C);
		DoubleHanoi_Odd(n - 2, B, C, A);
	}
	/*
	基本的问题分解：
	n=2的时候，先将一个挪到B，再将一个挪到C
	n>2时，将n拆解为n-2的子问题，先将下面n-1个挪到b，最底下的一个挪到C
	保留B中的最底层的一个，剩下的n-2个挪回去
	然后接着执行下面的过程
	但是本算法不允许同色在同一位置
	*/

}


//当挪动没有颜色限制的时候，可以将最上面的两个统一挪到另一端
void SingleHanoi(int n, char A, char B, char C) {
	//此处的n指的是双色的
	if (n == 0) return;
	if (n == 1) {
		printf("Move from %c to %c\n", A, C);
		printf("Move from %c to %c\n", A, C);
		//n>1，子问题划分为1时，先将这两个挪到另一端
	}
	else {
		SingleHanoi(n - 1, A, C, B);
		printf("Move from %c to %c\n", A, C);
		printf("Move from %c to %c\n", A, C);
		SingleHanoi(n - 1, B, A, C);
	}


}

void DoubleHanoi_No_Color_Limit(int n, char A, char B, char C) {
	for (int i = n / 2; i > 1; i--) {
		SingleHanoi(i - 1, A, B, C);
		printf("Move from %c to %c\n", A, B);
		printf("Move from %c to %c\n", A, B);
		SingleHanoi(i - 1, C, B, A);
		printf("Move from %c to %c\n", B, C);
	}
	printf("Move from %c to %c\n", A, B);
	printf("Move from %c to %c\n", A, C);
}

int Case;
int n;
int T;
int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("Case #%d:\n", ++Case);
		DoubleHanoi_No_Color_Limit(n, 'A', 'B', 'C');
	}
}