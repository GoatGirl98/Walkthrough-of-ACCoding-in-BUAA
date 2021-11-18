#pragma GCC optimize(2)
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define print 0
/*********************************************
关于栈的出入顺序可能问题同样是个板子
可以运用栈的思想模拟
如果当前值大于之前出现过的最大值
则把这个数字之前所有没进栈的数字和
该数字按从小到大顺序进栈，再pop栈顶元素
如果当前值小于之前出现的最大元素
则比较栈顶，如果一样则出栈，否则匹配失败
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
