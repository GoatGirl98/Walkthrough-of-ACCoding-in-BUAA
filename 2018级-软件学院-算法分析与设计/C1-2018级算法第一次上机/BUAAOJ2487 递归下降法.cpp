#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int t;
int n;
string a[1010];
string pairing_result;//输出结果
//parse_int 和 parse_pair两者需要互相调用
int parsing_index;
bool parse_type();
bool parse_pair();
bool parse_pair() {
    //pair<type, type>为pair的合法标志 需要调用parse_type
    if(a[parsing_index] == "pair") {
        ++parsing_index;
        pairing_result += "pair<";
        
        if(parse_type()) {
            ++parsing_index;
            pairing_result += ",";
        }
        else return false;
        
        if(parse_type()) {
            //注意分析样例,最终pair分析完之后不能前进！
            pairing_result += ">";
            return true;
        }
        else return false;
    }
    else return false;
}
bool parse_type() {
    //int或者pair<type, type>为type的合法标志 需要调用parse_pair
    if(a[parsing_index] == "int") {
        pairing_result += "int";
        return true;
    }
    else if (a[parsing_index] == "pair") {
        return parse_pair();
    }
    else return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) {
        parsing_index = 0;
        cin >> n;
        pairing_result.clear();
        for(int i = 0; i < 1010; ++i)a[i].clear();
        for(int i = 0; i < n; ++i) cin >> a[i];
        if(parse_pair() && parsing_index == n - 1)
            puts(pairing_result.c_str());
        else
            puts("Error occurred");
    }
}

