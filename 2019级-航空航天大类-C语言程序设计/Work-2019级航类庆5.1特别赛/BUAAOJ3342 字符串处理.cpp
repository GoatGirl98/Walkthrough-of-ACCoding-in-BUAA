#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<vector>
using namespace std;
FILE* IN;
vector<string>line;
vector<int>target;
int main() {
	//IN = freopen("3342in.txt", "r", stdin);
	string in;
	char c;
	while ((c = getchar()) != EOF) {
		in.push_back(c);
	}
	int pos;
	string s = "";
	for (int i = 0; i < in.size(); ++i) {
		if (in[i] == '\n') { if (!s.empty())line.push_back(s); s = ""; }
		else if(in[i] != '\r') s.push_back(in[i]);
	}
	if (!s.empty())line.push_back(s), s = "";
	for (int i = 0; i < line.size(); ++i)
		if (line[i][0] == 'F' || line[i][0] == 'G' || line[i][0] == 'C')
			target.push_back(i);
	for (int i = 0; i < target.size(); ++i) {
		int num = target[i];
		int standard = num - 1;
		string text = "";
		if (line[num][0] == 'F') {
			if (line[standard][0] == 'P')text = "xjj!";
			else if (line[standard][0] == 'T') {
				if (line[standard][8] == line[num][0])
					text = "ShaGuangFuHuaRen";
				else text = line[standard].substr(11, line[standard].size() - 12);
			}
			else if (line[standard].size() > 2)text = line[standard].substr(2, line[standard].size() - 2);
			text = "(" + text + ")";
			line[num] = "F:" + text;
		}
		else if (line[num][0] == 'G') {
			if (line[standard][0] == 'P')text = "xjj!";
			else if (line[standard][0] == 'T') {
				if (line[standard][8] == line[num][0])
					text = "GaoTu";
				else text = line[standard].substr(11, line[standard].size() - 12);
			}
			else if (line[standard].size() > 2)text = line[standard].substr(2, line[standard].size() - 2);
			text = "BuZhun" + text;
			line[num] = "G:" + text;
		}
		else {
			if (line[standard][0] == 'P')text = "xjj!";
			else if (line[standard][0] == 'T') {
				if (line[standard][8] == line[num][0])
					text = "?";
				else text = line[standard].substr(11, line[standard].size() - 12);
			}
			else if (line[standard].size() > 2)text = line[standard].substr(2, line[standard].size() - 2);
			text = text + "Grass";
			line[num] = "C:" + text;
		}
		if (line[num][0] == 'F' || line[num][0] == 'G' || line[num][0] == 'C') { 
			if (line[num].back() != '\n') puts(line[num].c_str());
			else printf("%s", line[num].c_str());
		}
	}
}