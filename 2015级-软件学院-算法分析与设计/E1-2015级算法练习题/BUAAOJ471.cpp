#include <iostream>
#include <algorithm>
#include <queue>

#define INF 4010

using namespace std;

int a[INF*INF];
int b[INF];
int temp[INF];

int n, k;

//�鲢�����ģ�壬��������Ȼ�󼯺ϳ�һ����

//�Ժ�Ĭ��Ϊ����ҿ�

void merge_sort(int lo, int hi, int* N) {

	if (hi > lo + 1) {
		int mi = (hi + lo) >> 1;
		merge_sort(lo, mi, N);
		merge_sort(mi, hi, N);

		int tempmark = lo;
		int lomark = lo;
		int himark = mi;

		while (lomark < mi || himark < hi) {

			if ((N[lomark] <= N[himark] || himark >= hi) &&
				lomark < mi) {
				temp[tempmark++] = N[lomark++];
			}
			else {
				temp[tempmark++] = N[himark++];
			}

		}

		for (int i = lo; i < hi; i++) {
			N[i] = temp[i];
		}

	}

	return;

}

struct Sum {

	int sum, bmark;//sum = a[amark]+b[bmark] amark is not nessessary

	//Sum(sum',bmark+1) sum' = sum+b[bmark+1]-b[mark]
	Sum(int s = 0, int b = 0) {
		sum = s;
		bmark = b;
	}

	bool operator < (const Sum& b) const {
		return sum > b.sum;
	}

};

void merge_queue(int* A, int* B, int* C, int limit) {

	priority_queue<Sum> queue;
	int counter = 0;
	
	for (int i = 0; i < n; ++i) {
		queue.push(Sum(A[i] + B[0], 0));
	}
	
	for (int i = 0; i < limit; ++i) {
		Sum smallest = queue.top();//current minimum number
		queue.pop();//cause it's sorted, so the first top must be the smallest sum among all the number
		C[i] = smallest.sum;
		int b = smallest.bmark;
		if (b + 1 < n)queue.push(Sum(smallest.sum - B[b] + B[b + 1], b + 1));
		//ÿ��ֻȡ�����ŵģ�û�оͲ�ȡ��û��ϵ�����ﲢ����Ҫ�ǽ����ڶ��������ģ���Ӱ����ȷ��

	}

}

int main() {

	ios::sync_with_stdio(false);

	while (scanf("%d%d",&n,&k)!=EOF) {

		for (int i = 0; i < n; i++) {
			scanf("%d",&a[i]);
		}
		merge_sort(0, n, a);
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
		}
		merge_sort(0, n, b);

		merge_queue(a, b, a, k);
		printf("%d\n", a[k - 1]);
	}

	return 0;
}