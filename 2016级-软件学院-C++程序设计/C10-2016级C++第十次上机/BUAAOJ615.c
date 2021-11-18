#include<stdio.h>
#include<string.h>
#include<ctype.h>
char in[114514];
char out[114514];
char sentence[114514];
int in_len, out_len, sen_len;
int i;
char c;
int main() {
	in_len = fread(in, 1, 114514, stdin);
	out_len = sen_len = 0;
	for (i = 0; i < in_len; ++i) {
		sentence[sen_len++] = in[i];
		if (in[i] == '.' || in[i] == '?' || in[i] == '!') {
			int sen_index = 0;//从0开始往后找
			while (isspace(sentence[sen_index]))sen_index++;
			if (islower(sentence[sen_index])) sentence[sen_index] = toupper(sentence[sen_index]);
			strcat(out, sentence);
			memset(sentence, 0, sizeof(sentence)), sen_len = 0;
		}
	}
	puts(out);
}
