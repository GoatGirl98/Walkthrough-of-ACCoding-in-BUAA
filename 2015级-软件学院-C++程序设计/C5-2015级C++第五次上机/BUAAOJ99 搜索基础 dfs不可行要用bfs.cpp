
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 10
/********************************************************************************************************************************************************
�����Դ������Ѳ�������
�������ٲ���Ӧ���ù���

��ϰBFS��DFS������
�������������ջ��stack����ʵ�֣��������̿��������һ�����������Σ�
1���Ѹ��ڵ�ѹ��ջ�С�
2��ÿ�δ�ջ�е���һ��Ԫ�أ���������������һ����Ԫ�أ�����ЩԪ��ѹ��ջ�С��������Ԫ�ؼ�Ϊ����һ��Ԫ�ص�ǰ����
3���ҵ���Ҫ�ҵ�Ԫ��ʱ��������
4�����������������û���ҵ�����������
�����������ʹ�ö��У�queue����ʵ�֣���������Ҳ���Կ���һ�����������Σ�
1���Ѹ��ڵ�ŵ����е�ĩβ��
2��ÿ�δӶ��е�ͷ��ȡ��һ��Ԫ�أ��鿴���Ԫ�����е���һ��Ԫ�أ������Ƿŵ����е�ĩβ���������Ԫ�ؼ�Ϊ����һ��Ԫ�ص�ǰ����
3���ҵ���Ҫ�ҵ�Ԫ��ʱ��������
4�����������������û���ҵ�����������
********************************************************************************************************************************************************/
bool occur[maxn][maxn];
typedef pair<int, int> p;
queue<p> que;
string a, b;
int startX, startY, endX, endY;
int nx[8] = { 1,1,2,2,-1,-1,-2,-2 };
int ny[8] = { 2,-2,1,-1,2,-2,1,-1 };
int BFS(int x, int y) {
	int cur = 0, last = 1;
	int nlast = 1, steps = 0;
	while (!que.empty())que.pop();
	que.push(p(x, y));
	while (!que.empty()) {
		p place = que.front();
		que.pop();
		cur++;

		if (place.first == endX && place.second == endY) return steps;
		occur[place.first][place.second] = true;

		for (int i = 0; i < 8; ++i) {
			int next_x = place.first + nx[i];
			int next_y = place.second + ny[i];
			if (next_x >= 1 && next_y <= 8 && next_y >= 1 && next_y <= 8 && !occur[next_x][next_y]) {
				que.push(p(next_x, next_y));
				nlast++;
			}
		}
		if (cur == last) { last = nlast; steps++; }

	}
	return -1;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> a >> b) {
		startX = a[0] - 'a' + 1, startY = a[1] - '0', endX = b[0] - 'a' + 1, endY = b[1] - '0';
		memset(occur, 0, sizeof(occur));
		cout << "It takes " << BFS(startX, startY) << " steps to get from " << a << " to " << b << endl;
	}
}


