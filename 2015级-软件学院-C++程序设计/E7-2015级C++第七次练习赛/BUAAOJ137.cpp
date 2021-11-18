#include <iostream>
#include <string>
using namespace std;
string str;
int main(){
    ios::sync_with_stdio(false);
    int len,cur,cur2,t;
    while(cin>>str){
        len=str.size();

        cur=len-2;
        while(cur>=0&&str[cur]>=str[cur+1])cur--;

        if(cur==-1)cout<<"What?"<<endl;
        else{
            cur2=len-1;
            while(cur2>cur&&str[cur2]<=str[cur])cur2--;
            t=str[cur];str[cur]=str[cur2];str[cur2]=t;

            for(int i=0;i<=cur;i++)cout<<str[i];
            for(int i=len-1;i>cur;i--)cout<<str[i];
            cout<<endl;
        }
    }
}
