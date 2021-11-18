#include<iostream>
#include<algorithm>
#include<ctime>

using namespace std;

/*
�����˼·���Ǳ�׼hanoi���ı���
���ĵ��������Ҫ������µ��������䵽B��C���У�ʣ�µľ��൱����n-1����������

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
	����������ֽ⣺
	n=2��ʱ���Ƚ�һ��Ų��B���ٽ�һ��Ų��C
	n>2ʱ����n���Ϊn-2�������⣬�Ƚ�����n-1��Ų��b������µ�һ��Ų��C
	����B�е���ײ��һ����ʣ�µ�n-2��Ų��ȥ
	Ȼ�����ִ������Ĺ���
	���Ǳ��㷨������ͬɫ��ͬһλ��
	*/

}


//��Ų��û����ɫ���Ƶ�ʱ�򣬿��Խ������������ͳһŲ����һ��
void SingleHanoi(int n, char A, char B, char C) {
	//�˴���nָ����˫ɫ��
	if (n == 0) return;
	if (n == 1) {
		printf("Move from %c to %c\n", A, C);
		printf("Move from %c to %c\n", A, C);
		//n>1�������⻮��Ϊ1ʱ���Ƚ�������Ų����һ��
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