#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define maxn 114514
char key[maxn], ori[maxn], ans[maxn];
char tmp[maxn], tmp2[maxn];
int len_key, len_ori, len_ans, len_tmp, len_tmp2;
char sheet[30][30];
int i, j;
int flag = 0;
bool occur[26];
void crlf(char* s, int* len) {
	*len = strlen(s);
	while (s[(*len) - 1] == '\n' || s[(*len) - 1] == '\r') s[--(*len)] = '\0';
}

void copy_without_space(char* dst, int* len_dst, char* src, int* len_src) {
	for (i = 0; i < *len_src; ++i)
		if (!isspace(src[i]))
			dst[(*len_dst)++] = tolower(src[i]);
	dst[*len_dst] = '\0';
}

bool judge_col(int y) {
	int x = 0;
	memset(occur, 0, sizeof(occur));
	for (; x < 26; ++x) {
		if (!sheet[x][y])continue;
		if (occur[sheet[x][y] - 'A']) return false;
		else occur[sheet[x][y] - 'A'] = true;
	}
	return true;
}

bool check() {
	int x = 0, y = 0;
	for (; y < 26; ++y)if (!judge_col(y)) return false; 
	return true;
}

int main() {
	while (fgets(key, maxn, stdin)) {
		flag = 1;
		memset(sheet, 0, sizeof(sheet));
		len_key = len_ori = len_ans = len_tmp = 0;
		crlf(key, &len_key);
		for (i = 0; i < len_key; ++i) key[i] = tolower(key[i]);
		fgets(tmp, maxn, stdin), crlf(tmp, &len_tmp);
		copy_without_space(ori, &len_ori, tmp, &len_tmp);
		fgets(tmp2, maxn, stdin), crlf(tmp2, &len_tmp2);
		copy_without_space(ans, &len_ans, tmp2, &len_tmp2);

		//corner case
		//notice : function is... does not necessarily return at 1
		if (len_tmp != len_tmp2) flag = 0;
		for (i = 0; i < len_tmp && flag; ++i) 
			if ((((isspace(tmp[i]) > 0) + (isspace(tmp2[i]) > 0)) == 1) || (((islower(tmp[i]) > 0) + (isupper(tmp2[i]) > 0) == 2)))
				flag = 0;
			
		
		if (!flag) { puts("ARE YOU GOOD MALAYS1A?\n"); continue; }

		for (i = 0, j = 0; i < len_ans && flag; ++i, j = (j + 1) % len_key) {
			int x = ori[i] - 'a', y = key[j] - 'a';
			if (!sheet[x][y]) sheet[x][y] = toupper(ans[i]); 
			else if (sheet[x][y] != toupper(ans[i])) flag = 0; 	
		}
		if (!flag || !check()) { puts("ARE YOU GOOD MALAYS1A?\n"); continue; }
		for (i = 0; i < 26; ++i, putchar('\n'))
			for (j = 0; j < 26; ++j)
				putchar(sheet[i][j] ? sheet[i][j] : '\'');
		putchar('\n');
	}
}