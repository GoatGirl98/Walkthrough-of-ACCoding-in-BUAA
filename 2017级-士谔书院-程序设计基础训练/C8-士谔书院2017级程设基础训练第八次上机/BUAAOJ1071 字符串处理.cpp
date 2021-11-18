#include<cstdio>
#include<cstring>
#define MAXN 210

char input[MAXN];
int main(){
    scanf("%[^\n]",input);//or gets
    int n = strlen(input);
    while(true){
        int bIndex = -1,uIndex = -1, gIndex = -1;
        n = strlen(input);
        for(int i = n-1; i >=0; --i){
            if(gIndex<0&&input[i]=='g')gIndex=i;
            else if (gIndex>=0 && uIndex<0 && input[i]=='u')uIndex = i;
            else if(uIndex>=0 && input[i]=='b'){bIndex = i;break;}
        }
        if(bIndex<0)break;
        for(int mark = 0,i=0;i<=n;++i){
            input[i-mark]=input[i];
            mark+=(i==bIndex);
            mark+=(i==uIndex);
            mark+=(i==gIndex);
        }
        
    }
    printf("%s\n",input);
}
