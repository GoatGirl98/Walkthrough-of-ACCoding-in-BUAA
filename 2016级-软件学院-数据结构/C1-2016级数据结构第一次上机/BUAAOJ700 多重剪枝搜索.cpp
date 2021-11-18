#include<iostream>
#include<string>
using namespace std;
/*
这道题肯定是要搜索的这个没有办法...
但是通过一定的约束条件，可以剪枝，将问题的规模大大的降低
这种题必须要多见多想，很重要！

(1)1+1=3这种明显不合法的问题
每次搜索的时候，从后向前判断是否有不合法的式子
(2)配合(1)接着做，按照字母的出现顺序搜索，提前减掉一些废枝
实际上还有第三个要点(以下*为已知，?为未知)
    A * * * ? * * *
+   B * ? * * ? * *
----------------------
    C * * * ? ? ? *
(不一定只是这一种特定的情况,只是想举一个特定位的例子而已)
只是说，这种情况并不能直接确定A+B=C是不是合法
但是比如说(A+B)%N与(A+B+1)%N都不等于C,那就可以直接剪了
类似的A+?=C的时候，看(C-A+N)%N与(C-A-1+N)%N这两个数是否用过
如果都用过，就直接剪了
*/
//基本的流程：初始都是ascii码的字母，都比具体数字要大，当知道一个值之后，就把具体字母换成数字
string a, b, c;
string words;
bool hashlist[256], used[27];//指这个有没有用上
bool finish;//一旦找出正确结果，不再接着找，直接断掉
int n;
int stack[27];
//利用类似栈结构来记录，该栈与最终的结果words一一对应
int ans[27];

inline void addChar(char ch) {
    if (!hashlist[ch]) { hashlist[ch] = true; words += ch; }
    //不重复添加字符
}
inline string change(string str, char x, char y){
    for (int i = 0; i < n; ++i) {
        if (str[i] == x)str[i] = y;
    }
    return str;
}
//第一种剪枝方式，出现非法返回true
inline bool bad() {
    //检查某一结果的值是否合法
    int p, g = 0;//g表示进位 p表示a+b当前位再加进位之后的位置
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] >= n || b[i] >= n || c[i] >= n)return false;//目前该组合是未知的
        p = a[i] + b[i] + g;
        if (p % n != c[i])return true;//明显的不合法结果
        g = p / n;
    }
    return false;
}
//第二种剪枝方式，出现非法返回true
inline bool checkMod() {
    int  p, p1, p2, g = 0;
    //A+B=C
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] >= n || b[i] >= n || c[i] >= n)continue;//目前是未知数，还无法判断是否合法
        p = (a[i] + b[i]) % n;
        if (!(p % n == c[i] || (p + 1) % n == c[i]))return true;//上面已经分析过了
    }
    //A+? = C
    for (int i = n - 1; i >= 0; --i) {
        if (!(a[i] < n && b[i] >= n && c[i] < n))continue;
        p1 = (c[i] - a[i] + n) % n;
        p2 = (c[i] - a[i] - 1 + n) % n;
        if (used[p1] && used[p2])return true;
    }
    //?+B = C
    for (int i = n - 1; i >= 0; --i) {
        if (!(a[i] >= n && b[i] < n && c[i] < n))continue;
        p1 = (c[i] - b[i] + n) % n;
        p2 = (c[i] - b[i] - 1 + n) % n;
        if (used[p1] && used[p2])return true;
    }
    //A+B = ?
    for (int i = n - 1; i >= 0; --i) {
        if (!(a[i] < n && b[i] < n && c[i] >= n))continue;
        p1 = (a[i] + b[i]) % n;
        p2 = (a[i] + b[i] + 1) % n;
        if (used[p1] && used[p2])return true;
    }
    return false;
}
inline void outputResult() {
    for (int i = 0; i < n; ++i) {
        ans[words[i] - 65] = stack[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    finish = true;
}
inline void dfs(int level) {
    int i;
    string tmpA, tmpB, tmpC;
    if (finish)return;
    if (bad())return;
    if (checkMod())return;
    if (level == n) {
        outputResult();
        return;
    }

    for (i = n - 1; i >= 0; --i) {
        if (!used[i]) {
            used[i] = true;//往下走一层，假设某个数就是i了
            tmpA = a; a = change(tmpA, words[level], i);
            tmpB = b; b = change(tmpB, words[level], i);
            tmpC = c; c = change(tmpC, words[level], i);
            stack[level] = i;
            dfs(level + 1);
            used[i] = false; a = tmpA, b = tmpB, c = tmpC;
            
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> c;
    words = "";//记录出现了哪些值
    for (int i = n - 1; i >= 0; --i) {
        addChar(a[i]); addChar(b[i]); addChar(c[i]);
    }
    dfs(0);
    return 0;

}
