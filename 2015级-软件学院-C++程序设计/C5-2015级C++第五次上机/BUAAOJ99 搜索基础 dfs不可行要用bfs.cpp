
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 10
/********************************************************************************************************************************************************
很明显此题深搜不可行了
这种最少步数应当用广搜

复习BFS与DFS的区别
深度优先搜索用栈（stack）来实现，整个过程可以想象成一个倒立的树形：
1、把根节点压入栈中。
2、每次从栈中弹出一个元素，搜索所有在它下一级的元素，把这些元素压入栈中。并把这个元素记为它下一级元素的前驱。
3、找到所要找的元素时结束程序。
4、如果遍历整个树还没有找到，结束程序。
广度优先搜索使用队列（queue）来实现，整个过程也可以看做一个倒立的树形：
1、把根节点放到队列的末尾。
2、每次从队列的头部取出一个元素，查看这个元素所有的下一级元素，把它们放到队列的末尾。并把这个元素记为它下一级元素的前驱。
3、找到所要找的元素时结束程序。
4、如果遍历整个树还没有找到，结束程序。
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


