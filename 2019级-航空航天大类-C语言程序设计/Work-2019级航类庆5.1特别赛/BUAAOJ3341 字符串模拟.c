#include<stdio.h>
typedef long long ll;
ll n;
ll splitPart[4];
int printPart[4];
int printsize;
inline void printSingleNum(ll num) {
	//2位数
	ll ten = num / 10;
	ll one = num % 10;
	if (ten == 0) {
		if (one == 1)printf("one");
		if (one == 2)printf("two");
		if (one == 3)printf("three");
		if (one == 4)printf("four");
		if (one == 5)printf("five");
		if (one == 6)printf("six");
		if (one == 7)printf("seven");
		if (one == 8)printf("eight");
		if (one == 9)printf("nine");
	}
	else if (ten == 1) {
		if (one == 0)printf("ten");
		if (one == 1)printf("eleven");
		if (one == 2)printf("twelve");
		if (one == 3)printf("thirteen");
		if (one == 4)printf("fourteen");
		if (one == 5)printf("fifteen");
		if (one == 6)printf("sixteen");
		if (one == 7)printf("seventeen");
		if (one == 8)printf("eighteen");
		if (one == 9)printf("nineteen");
	}
	else {
		if (ten == 2)printf("twenty");
		if (ten == 3)printf("thirty");
		if (ten == 4)printf("forty");
		if (ten == 5)printf("fifty");
		if (ten == 6)printf("sixty");
		if (ten == 7)printf("seventy");
		if (ten == 8)printf("eighty");
		if (ten == 9)printf("ninety");
		if (one == 1)printf("-one");
		if (one == 2)printf("-two");
		if (one == 3)printf("-three");
		if (one == 4)printf("-four");
		if (one == 5)printf("-five");
		if (one == 6)printf("-six");
		if (one == 7)printf("-seven");
		if (one == 8)printf("-eight");
		if (one == 9)printf("-nine");
	}
}
inline void print(ll num, int part) {
	ll hundred = num / 100;
	ll tenandone = num % 100;
	if (hundred > 0) {
		printSingleNum(hundred); printf(" hundred");
		if (tenandone > 0)
			printf(" and "), printSingleNum(tenandone);
	}
	else printSingleNum(tenandone);
	if (part == 3)printf(" billion");
	else if (part == 2)printf(" million");
	else if (part == 1)printf(" thousand");
}
int main() {
	while (scanf("%lld", &n) != EOF) {
		splitPart[0] = splitPart[1] = splitPart[2] = splitPart[3] = 0;
		printPart[0] = printPart[1] = printPart[2] = printPart[3] = 0;
		printsize = 0;
		splitPart[0] = n % 1000ll;
		splitPart[1] = (n % 1000000ll) / 1000ll;
		splitPart[2] = (n % 1000000000ll) / 1000000ll;
		splitPart[3] = n / 1000000000ll;
		for (int i = 3; i >= 0; --i)
			if (splitPart[i])printPart[printsize++] = i;
		if (printsize == 0) { puts("zero"); continue; }
		else {
			for (int i = 0; i < printsize; ++i) {
				print(splitPart[printPart[i]], printPart[i]);
				if (i + 1 != printsize)printf(", ");
			}
			puts("");
		}
	}
}