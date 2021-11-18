#include <iostream>
#include <algorithm>
#include <queue>

#define INF 710

using namespace std;

int a[INF][INF];
int temp[INF];

int n, k;

//归并排序的模板，记下来，然后集合成一个书

//以后都默认为左闭右开

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
		//每次只取他挨着的，没有就不取，没关系，这里并不需要是仅次于队列中最大的，不影响正确性

	}

}

int main() {

	ios::sync_with_stdio(false);

	while (scanf("%d", &n) != EOF) {

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &a[i][j]);
			}
			merge_sort(0, n, a[i]);
		}
		//merge_sort(0, n, b);
		for (int i = 1; i < n; i++) {
			merge_queue(a[0], a[i], a[0], n);
		}
		for (int i = 0; i < n; ++i) {
			printf("%d ", a[0][i]);
		}
		printf("\n");
	}

	return 0;

}