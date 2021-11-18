#pragma GCC optimize(2)
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define print 0
/*********************************************
����ջ�ĳ���˳���������ͬ���Ǹ�����
��������ջ��˼��ģ��
�����ǰֵ����֮ǰ���ֹ������ֵ
����������֮ǰ����û��ջ�����ֺ�
�����ְ���С����˳���ջ����popջ��Ԫ��
�����ǰֵС��֮ǰ���ֵ����Ԫ��
��Ƚ�ջ�������һ�����ջ������ƥ��ʧ��
*********************************************/
stack<int> simuStack;
int n, m;
bool flag;
int input;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	while (cin >> n >> m) {
		if (print)cout << n << " " << m << endl;
		for (int j = 1; j <= m; ++j) {
			while (!simuStack.empty())simuStack.pop();
			flag = true;
			int curMax = 0;
			if (print)cout << j << endl;
			for (int i = 1; i <= n; ++i) {

				cin >> input;
				if (print)cout << j << " " << i << " is " << input << endl;
				if (!flag)continue;
				if (input > curMax) {
					for (int i = curMax + 1; i < input; ++i) {
						simuStack.push(i);
					}
					curMax = input;
				}
				else {
					if (input == simuStack.top())simuStack.pop();
					else { flag = false; }
				}

			}
			if (flag)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		cout << endl;
	}


}
