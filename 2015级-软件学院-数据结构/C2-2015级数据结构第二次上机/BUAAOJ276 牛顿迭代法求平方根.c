#include<stdio.h>
int int_sqrt(int x) {
	if(x<=1)
		return x;
	int ret=x;
	int rett=(ret+(x/ret))>>1;
	while(rett<ret) {
		ret=rett;
		rett=(ret+(x/ret))>>1;
	}
	return ret;
}
int n;
int main() {
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",int_sqrt(n));
	return 0;
}
