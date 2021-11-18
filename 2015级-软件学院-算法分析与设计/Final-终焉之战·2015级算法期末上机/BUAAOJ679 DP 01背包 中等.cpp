#include<iostream>
#include<cstring>
#include<vector>
#define maxn 510
#define print 0
using namespace std;
//�ۺ�dp
int n, k;
int a[maxn];
bool dp[maxn][maxn];//����Ϊi��ʱ�����Ƿ����j�����

inline void erase() {
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
}

inline void initDP() {
	dp[0][0] = true;
}

inline void initialize(int i) {
	dp[a[i]][0] = true;
	dp[a[i]][a[i]] = true;
	if (print)cout << a[i] << " 0 is true" << endl;
	if (print)cout << a[i] << " " << a[i] << " is true" << endl;
}

inline void buildDP() {
	initialize(1);
	for (int i = 2; i <= n; ++i) {
		//initialize(i);
		for (int j = k; j >= 1; --j) {
			if (j >= a[i]) {
				if (dp[j - a[i]][j - a[i]]) {
					vector<int> temp;
					for (int lala = 0; lala <= j; lala++) {
						dp[j][lala] = dp[j][lala] || dp[j - a[i]][lala];
						if (dp[j][lala]) {
							if(dp[j - a[i]][lala])temp.push_back(lala);
							if (print)cout << "in loop " << i << " : " << j << " " << lala << "is true" << endl;
						}
					}
					
					for (int lala : temp) { 
						if (lala + a[i] <= j) {
							dp[j][lala + a[i]] = true;
							if (print)cout << "in loop " << i << " : " << j << " " << lala + a[i] << "is true" << endl;
						}
					}

					
					dp[j][j] = true;
					if (print)cout << "in loop " << i << " : " << j << " " << j << "is true" << endl;
				}	
			}
		}
	}
}

inline void printRes() {
	int result = 0;
	for (int i = 0; i <= k; ++i)if (dp[k][i])result++;
	if (result == 0)cout << "0" << endl << "None" << endl;
	else 
	{
		cout << result << endl;
		for (int i = 0; i <= k; ++i)if (dp[k][i])cout << i << " ";
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> k) {
		erase();
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		initDP();
		buildDP();
		printRes();
	}
}