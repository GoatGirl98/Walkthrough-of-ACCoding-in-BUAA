#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
string output;
char c;
bool sentenceFlag, quoteFlag;
int main() {
    sentenceFlag = true, quoteFlag = false;
    while ((c = getchar()) != EOF) {
        output.push_back(c);
    }
    string real = "";
    string tmp = "";
    for (int i = 0; i < output.size(); ++i) {
        tmp.push_back(output[i]);
        if (tmp.back() == '.' || tmp.back() == '?' || tmp.back() == '!') {
            int start = 0;
            while (isspace(tmp[start]))start++;
            if (islower(tmp[start]))tmp[start] = toupper(tmp[start]);
            real += tmp;
            tmp = "";
        }
    }
    puts(real.c_str());
}
