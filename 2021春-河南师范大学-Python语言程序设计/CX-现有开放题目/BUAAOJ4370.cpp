#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxv = 1010;
int V, N;
int cost;
int f[maxv + 10];
void buildDP_01Pack(int cost, int value) {
    for (int v = V; v >= cost; --v) 
        f[v] = max(f[v], f[v - cost] + value);
}
string in;
vector<int> inp;
int x;
int main() {
    getline(cin, in);
    for (int i = 0; i < in.length(); ++i)
        if (!isdigit(in[i]))
            in[i] = ' ';
    stringstream s1(in);
    while (s1 >> x)inp.push_back(x);
    V = inp.back(), inp.pop_back();
    for (int i = 0; i < inp.size(); ++i)
        buildDP_01Pack(inp[i], 1);
    cout << f[V] << endl;
    
}