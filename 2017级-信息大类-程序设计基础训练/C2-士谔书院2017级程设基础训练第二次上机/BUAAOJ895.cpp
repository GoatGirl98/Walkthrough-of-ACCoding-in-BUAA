#include<iostream>
using namespace std;
bool ThreeGreat;
double GPA;
int a[2][3];
double av1,av2;
bool isOK;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>ThreeGreat>>GPA>>a[0][0]>>a[0][1]>>a[0][2]>>a[1][0]>>a[1][1]>>a[1][2]) {
        isOK=false;
        av1=(a[0][0]+a[0][1]+a[0][2])/3.0;av2=(a[1][0]+a[1][1]+a[1][2])/3.0;
        if(ThreeGreat){
            if(GPA>=3.5||(av1>=80.0&&av2>=80.0))isOK=true;
        }else{
            if(GPA>=3.6||(av1>85.0&&av2>85.0))isOK=true;
        }
        if(isOK)cout<<"APPROVED"<<endl;
        else cout<<"REJECTED"<<endl;
    }
}
