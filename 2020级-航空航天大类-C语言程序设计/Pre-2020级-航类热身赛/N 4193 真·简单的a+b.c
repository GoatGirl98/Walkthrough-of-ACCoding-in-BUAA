#include <stdio.h>
int main(){
	long long int a,b;
	scanf("%lld %lld",&a,&b);
	if(a>=0&&b>=0){
		unsigned long long int sum=a+b;
		printf("%llu\n",sum);
	}
	else if(((a>0&&b<=0))||((a<=0)&&(b>0))){
		long long int sum=a+b;
		printf("%lld\n",sum);
	}
	else if(a==-9223372036854775808ll&&b==-9223372036854775808ll){
		printf("-18446744073709551616\n");
	}
	else if(a<=0&&b<=0){
		a=-a,b=-b;
		unsigned long long int sum=a+b;
		printf("-%llu\n",sum);
	}
	return 0;
}
