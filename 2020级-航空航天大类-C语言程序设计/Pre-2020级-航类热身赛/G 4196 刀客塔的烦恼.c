#include<stdio.h>

int main(){
    int current,record,money,needMoney,needRecord;
    scanf("%d %d %d",&current,&record,&money);
    needMoney=(80-current)*1000;
    needRecord=(80-current)*10;
    if(record>=needRecord&&money>=needMoney){
        printf("YES %d %d\n",needRecord,needMoney);
    }else{
        printf("NO ");
        printf("%d ",record>needRecord?0:needRecord-record);
        printf("%d",money>needMoney?0:needMoney-money);
    }
}