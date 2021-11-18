#include<cstdio>
#include<cstring>
struct Matrix {
	double value[6][6];
	inline void init() {
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (i != j && i + j != 5) {
					value[i][j] = 0.25;
				}
			}
		}
	}
	Matrix operator *(const Matrix& o) const {
		Matrix ret;
		memset(ret.value, 0, sizeof(ret.value));
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				for (int k = 0; k < 6; ++k) {
					ret.value[i][j] += value[i][k] * o.value[k][j];
				}
			}
		}
		return ret;
	}
	Matrix fastpower(int power) {
		Matrix tmp = *this;
		Matrix ret;
		memset(ret.value, 0, sizeof(ret.value));
		for (int i = 0; i < 6; ++i)ret.value[i][i] = 1.0;
		while (power) {
			if (power & 1)ret = ret * tmp;
			tmp = tmp * tmp;
			power >>= 1;
		}
		return ret;
	}
};
struct Vector {
	double value[6];
	Vector(double a0 = 0.0, double a1 = 0.0, double a2 = 0.0, double a3 = 0.0, double a4 = 0.0, double a5 = 0.0) {
		value[0] = a0, value[1] = a1, value[2] = a2, value[3] = a3, value[4] = a4, value[5] = a5;
	}
	Vector multi(const Matrix& matrix) {
		Vector ret;
		memset(ret.value, 0, sizeof(ret.value));
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				ret.value[i] += value[j] * matrix.value[j][i];
			}
		}
		return ret;
	}
};
Matrix trans;
Matrix mul;
Vector ans;
int n, k;
double start[6];
int main() {
	trans.init();
	while (scanf("%d%d", &n, &k) != EOF) {
		--n;
		for (int i = 0; i < 6; ++i) {
			if (n == i) start[i] = 100.0;
			else start[i] = 0.0;
		}
		mul = trans.fastpower(k);
		ans = Vector(start[0], start[1], start[2], start[3], start[4], start[5]);
		ans = ans.multi(mul);
		for (int i = 0; i < 6; ++i) 
			printf("%.2f%%%c", ans.value[i], i == 5 ? '\n' : ' ');
	}
}