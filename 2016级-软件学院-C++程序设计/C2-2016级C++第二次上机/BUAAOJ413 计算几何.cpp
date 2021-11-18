#include<cstdio>
#define Abs(x) (((x)>0)?(x):(-(x)))
typedef long long ll;
typedef unsigned long long ull;
/*******************************************
���㼸�λ�����Ŀ
�ж������������Ƿ��ڵ�������

����һ����������3���߿��ܶ��������������
(Trick�Զ��׼�,�Ͼ��ߵĴ�С�����Ǹ���)

����˼·���ڽ�ϵ,�������֮���ж�
Ȼ����㼸�ξ����ܲ��ø���Ͳ���,����̫��
������΢ת��һ��˼·
���ĵ�Ч��ʾΪc^2-b^2 �߶ε�ЧΪ[-3a^2,3a^2]
*******************************************/
inline void judge(ll a, ll b, ll c) {
	if (a > 0 && b > 0 && c > 0 && c < a + b && c > Abs(a - b)) {
		ll g = Abs(c * c - b * b);
		ull right = 3 * a * a;
		if (g < right)puts("stable");
		else if (g == right)puts("almost stable");
		else puts("no way");
	}
	else puts("no way");
}
int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	printf("%d:", a); judge(a, b, c);
	printf("%d:", b); judge(b, a, c);
	printf("%d:", c); judge(c, a, b);
}