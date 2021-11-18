#include<cstdio>
//这题就是小端存储(Little-Endian)的基础问题
int n, k, m;
int memory[10010];
int ptr[110];
char Instr[7];
int op, op2;
int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < k; ++i) {
		scanf("%X", memory + i);
	}
	while (scanf("%s", Instr) != EOF) {
		if (Instr[0] == 'r') {
			scanf("%d%s", &op, Instr);
			if (ptr[op]<0 || ptr[op]>k - 4)puts("Index out of bound.");
			else printf("%d\n", memory[ptr[op] + 3] * 16777216 + memory[ptr[op] + 2] * 65536 + memory[ptr[op] + 1] * 256 + memory[ptr[op]]), ptr[op] += 4;
		}
		else {
			scanf("%d%d", &op, &op2);
			ptr[op] += op2;
		}
	}
}