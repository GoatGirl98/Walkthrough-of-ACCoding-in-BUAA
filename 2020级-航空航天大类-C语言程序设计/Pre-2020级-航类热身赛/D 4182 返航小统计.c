#include<stdio.h>

int main(){
    int n,id,day,hour,min,aimday,count=0;
    scanf("%d",&aimday);
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
    	scanf("%d%d%d:%d",&id,&day,&hour,&min);
    	if(day==aimday){
    		printf("%d %02d:%02d\n",id,hour,min);
    		count++;
		}
	}
	printf("%d",count);
}
