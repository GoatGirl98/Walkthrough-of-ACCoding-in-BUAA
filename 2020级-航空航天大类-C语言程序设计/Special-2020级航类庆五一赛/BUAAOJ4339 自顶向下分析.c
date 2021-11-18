#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 114514
char alpha_ori[15];
int alpha_sheet[26];
int status[15];
int n, max_status;
char num[maxn], s[maxn];
int len_num, len_s;

void get_status(int cur) {
	memset(status, 0, sizeof(status));
	int i = 0;
	while (i < n) {
		if (cur & (1 << i)) status[i] = 1;
		++i;
	}
}

//LEAF + op_num (op_num)-th constant 
//NOT_LEAF + op_num op_num 1 : AND op_num 2 : OR op_num 3 : REV
struct node {
	int is_leaf;
	int op_num;
	int lc, rc;
}nodes[maxn];
int node_cnt, root;

int bracket_level[maxn];
int level_cnt[maxn];

void get_bracket_status(int l, int r) {
	memset(&bracket_level[l], 0, (r - l + 1) * sizeof(int));
	memset(level_cnt, 0, sizeof(level_cnt));
	int i = 0, in = 0;
	for (i = l; i <= r; ++i) {
		if (s[i] == '(') ++in, bracket_level[i] = in, ++level_cnt[in];
		if (s[i] == ')')bracket_level[i] = in, ++level_cnt[in], --in;
	}
}

int get_binary_op(int l, int r) {
	int in = 0;
	for (int i = r; i >= l; --i) {
		in += s[i] == '(';
		in -= s[i] == ')';
		if (in) continue;
		if (s[i] == '&' || s[i] == '|') return i;
	}
	return -1;
}

int build(int l, int r) {
	//step 0 : get rid of duplicate bracket
	if (l > r) return 0;
	get_bracket_status(l, r);
	int in = 1;
	while (level_cnt[in] == 2 && bracket_level[l] == in && bracket_level[r] == in)
		l++, r--, ++in;

	int node = ++node_cnt, pos = -1;
	
	//step 1 : get constant
	if (l == r) {
		nodes[node].is_leaf = 1;
		nodes[node].op_num = alpha_sheet[s[l] - 'a'];
		nodes[node].lc = nodes[node].rc = 0;
		return node;
	}

	//step 2 : get binary operator
	pos = get_binary_op(l, r);
	if (pos != -1) {
		nodes[node].is_leaf = 0;
		nodes[node].op_num = (s[pos] == '&' ? 1 : 2);
		nodes[node].lc = build(l, pos - 1);
		nodes[node].rc = build(pos + 1, r);
		return node;
	}

	//step 3 : get unary operator
	if (s[l] == '~') {
		nodes[node].is_leaf = 0;
		nodes[node].op_num = 3;
		nodes[node].lc = build(l + 1, r);
		nodes[node].rc = 0;
		return node;
	}

	return 0;
}

int dfs(int u) {
	if (nodes[u].is_leaf) 
		return status[nodes[u].op_num];
	else if (nodes[u].op_num == 1)
		return dfs(nodes[u].lc) & dfs(nodes[u].rc);
	else if (nodes[u].op_num == 2)
		return dfs(nodes[u].lc) | dfs(nodes[u].rc);
	else return 1 - dfs(nodes[u].lc);
}

int main() {
	fgets(num, maxn, stdin);
	len_num = strlen(num);
	while (num[len_num - 1] == '\r' || isspace(num[len_num - 1])) num[--len_num] = '\0';
	int i = len_num - 1, j = 0;
	while (i >= 0) {
		while (i >= 0 && isspace(num[i]))--i;
		if (i < 0) break;
		alpha_ori[n] = num[i];
		alpha_sheet[num[i] - 'a'] = n++;
		--i;
	}
	int lo = 0, hi = n - 1;
	while (lo < hi) {
		alpha_ori[lo] ^= alpha_ori[hi];
		alpha_ori[hi] ^= alpha_ori[lo];
		alpha_ori[lo] ^= alpha_ori[hi];
		lo++, hi--;
	}
	fgets(s, maxn, stdin);
	len_s = strlen(s);
	while (s[len_s - 1] == '\r' || s[len_s - 1] == '\n' || isspace(s[len_s - 1])) s[--len_s] = '\0';

	root = build(0, len_s - 1);

	max_status = (1 << n) - 1;

	for (i = 0; i < n; ++i) 
		putchar('|'), putchar(' '), putchar(alpha_ori[i]), putchar(' ');
	putchar('|'), putchar(' '), putchar('R'), putchar(' '), putchar('|');
	putchar('\n');

	for (i = 0; i <= max_status; ++i) {
		get_status(i);
		for (j = n - 1; j >= 0; --j) 
			putchar('|'), putchar(' '), putchar(status[j] ? 'T' : 'F'), putchar(' ');
		putchar('|'), putchar(' '), putchar(dfs(root) ? 'T' : 'F'), putchar(' '), putchar('|');
		putchar('\n');
	}

}