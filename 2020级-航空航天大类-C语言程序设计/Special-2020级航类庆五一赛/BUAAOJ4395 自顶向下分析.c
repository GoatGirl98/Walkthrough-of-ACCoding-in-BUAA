#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 110
char input[maxn];
int len;

//语法树部分

typedef struct parse_tree_node {
	int dfs_time;
	char key_link;
	int child_index[maxn];
	int child_cnt;
}node, *node_ptr;

node memory_pool[maxn];
int node_cnt;//在内存池中开设的节点个数
int root;//语法树根节点的下标
int dfs_cnt;//dfs序的时间戳
int time_table[maxn];//dfs_time memory_pool_index
void clear(node_ptr x) {
	int i = 0;
	for (i = 0; i < x->child_cnt; ++i)
		x->child_index[i] = 0;
	x->dfs_time = 0;
	x->key_link = '\0';
	x->child_cnt = 0;
}
void add_child(node_ptr x, int a) {
	x->child_index[x->child_cnt] = a;
	x->child_cnt++;
}
int is_leaf(node_ptr x) {
	int i = 0;
	for (i = 0; i < x->child_cnt; ++i)
		if (x->child_index[i])
			return 0;
	return 1;
}
void print(node_ptr x) {
	putchar(x->key_link), putchar(' ');
	for (int i = 0; i < x->child_cnt; ++i) {
		int ch = x->child_index[i];
		if (memory_pool[ch].dfs_time) printf("%d ", memory_pool[ch].dfs_time);
		else putchar(memory_pool[ch].key_link), putchar(' ');
	}
	putchar('\n');
}
//后序遍历dfs序部分
void back_trace(int _index) {
	for (int i = 0; i < memory_pool[_index].child_cnt; ++i)
		back_trace(memory_pool[_index].child_index[i]);
	if (!is_leaf(&memory_pool[_index]))
		memory_pool[_index].dfs_time = ++dfs_cnt, time_table[dfs_cnt] = _index;
};

void init() {
	for (int i = 1; i <= node_cnt; ++i)
		clear(&memory_pool[i]);
	node_cnt = root = 0;
	dfs_cnt = 0;
}
int is_duplicate_bracket(int l, int r) {
	int s[maxn], cnt = 0;
	memset(s, 0, sizeof(s));
	int ret = 0;
	for (int i = l; i < r; ++i) {
		if (input[i] == '(') s[cnt] = i, cnt++;
		if (input[i] == ')') cnt--, s[cnt] = 0;
	}
	if (cnt == 1 && s[0] == l) ret = 1;
	return ret;
}
int get_plus_or_minus(int l, int r) {
	int in = 0;//在多少层括号内，无论正负，只有0才是真的需要的
	for (int i = r; i >= l; --i) {
		in += input[i] == '(';
		in -= input[i] == ')';
		if (in) continue;
		if (input[i] == '+' || input[i] == '-') return i;
	}
	return -1;
}
int get_multi_or_div(int l, int r) {
	int in = 0;//在多少层括号内，无论正负，只有0才是真的需要的
	for (int i = r; i >= l; --i) {
		in += input[i] == '(';
		in -= input[i] == ')';
		if (in) continue;
		if (input[i] == '*' || input[i] == '/') return i;
	}
	return -1;
}
int get_member_func(int l, int r) {
	int in = 0;//在多少层括号内，无论正负，只有0才是真的需要的
	for (int i = r; i >= l; --i) {
		in += input[i] == '(';
		in -= input[i] == ')';
		if (in) continue;
		if (input[i] == '.') return i;
	}
	return -1;
}
int is_stadard_func(int l, int r) {
	if (r - l + 1 <= 3) return 0;
	return islower(input[l]) && input[l + 1] == '(' && input[r] == ')';
}
int* get_all_comma(int l, int r) {
	int* ret;
	ret = (int*)malloc(sizeof(int) * maxn);
	memset(ret, -1, sizeof(int) * maxn);
	int cnt = 0;
	int in = 0;
	for (int i = l; i <= r; ++i) {
		in += input[i] == '(';
		in -= input[i] == ')';
		if (in) continue;
		if (input[i] == ',') ret[cnt] = i, cnt++;
	}
	return ret;
}
int build(int l, int r) {
	if (l > r) return 0;
	//pre-treat : 去掉所有括号
	while (is_duplicate_bracket(l, r)) l++, r--;

	int node = ++node_cnt, pos = -1;

	//特判 priority 5 : 常量
	if (l == r) {
		memory_pool[node].key_link = input[l];
		return node;
	}

	//priority 1 : 加减符

	pos = get_plus_or_minus(l, r);
	if (pos != -1) {
		memory_pool[node].key_link = input[pos];
		add_child(&memory_pool[node], build(l, pos - 1));
		add_child(&memory_pool[node], build(pos + 1, r));
		return node;
	}

	//priority 2 : 乘除符

	pos = get_multi_or_div(l, r);
	if (pos != -1) {
		memory_pool[node].key_link = input[pos];
		add_child(&memory_pool[node], build(l, pos - 1));
		add_child(&memory_pool[node], build(pos + 1, r));
		return node;
	}

	//priority 3 : 成员函数

	pos = get_member_func(l, r);
	if (pos != -1) {
		memory_pool[node].key_link = input[pos + 1];//注意字母在'.'后面
		add_child(&memory_pool[node], build(l, pos - 1));
		int* commas = get_all_comma(pos + 3, r - 1);
		int commas_size = 0;
		while (commas[commas_size] >= 0)++commas_size;
		commas[commas_size] = r;
		commas_size++;

		int start = pos + 3, i = 0;
		for (i = 0; i < commas_size; ++i) {
			add_child(&memory_pool[node], build(start, commas[i] - 1));
			start = commas[i] + 1;
		}
		free(commas);
		return node;
	}

	//priority 4 : 普通函数

	pos = is_stadard_func(l, r);
	if (pos) {
		memory_pool[node].key_link = input[l];
		int* commas = get_all_comma(l + 2, r - 1);
		int commas_size = 0;
		while (commas[commas_size] >= 0)++commas_size;
		commas[commas_size] = r;
		commas_size++;

		int start = l + 2, i = 0;
		for (i = 0; i < commas_size; ++i) {
			add_child(&memory_pool[node], build(start, commas[i] - 1));
			start = commas[i] + 1;
		}
		free(commas);
		return node;
	}
	return 0;
}



int main() {
	while (scanf("%s", input) != EOF) {
		init();
		len = strlen(input);
		root = build(0, len - 1);
		back_trace(root);
		int i = 0;
		for (i = 1; i <= dfs_cnt; ++i)
			print(&memory_pool[time_table[i]]);
	}
}