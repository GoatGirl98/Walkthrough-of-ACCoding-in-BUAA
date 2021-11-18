#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,k;
    //s是原来字符串，k是重复的字符串
    int n;
    cin>>n;
    while(n--){
        cin>>s;
        k="";//别忘了初始化！
        for(int i=0;i<s.length();i++){
            k+=s[i];//在k的后面加上s中的下一项
            if(s.length()%k.length()==0){//如果能整除（就是重复可以正好凑齐）
                int t=s.length()/k.length();
                //t是循环几次
                string k2;//k2用来比较
                for(int j=0;j<t;j++){
                    k2+=k;//k2一直累加到长度与s相同
                }
                if(k2==s){//判断是否相同
                    cout<<k.length()<<endl;
                    //输出长度
                    i=s.length();
                    //跳出循环的搞笑方法
                    //自己看格式
                }
            }
        }
    }
    return 0;
}
