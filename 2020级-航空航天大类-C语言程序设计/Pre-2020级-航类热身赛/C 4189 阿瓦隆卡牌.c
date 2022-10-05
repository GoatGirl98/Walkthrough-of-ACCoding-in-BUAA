#include<stdio.h>

int main(){
    char c;
    int i,W=0;
    for(i=0;i<10;++i){
        scanf("%c",&c);
        if(c=='W'){
            W++;
        }
    }
    scanf("%c",&c);
    if(W>=3 && c=='H'){
        printf("%d\nKing Arthur Win",W);
    }else{
        printf("%d\nMedrawt Win",W);
    }
}