#include<cstdio>
typedef unsigned long long ll;
const ll MOD = 100000;
struct Matrix {
	ll value[2][2];
	Matrix(ll a_00 = 0, ll a_01 = 0, ll a_10 = 0, ll a_11 = 0) {
		value[0][0] = a_00, value[0][1] = a_01;
		value[1][0] = a_10, value[1][1] = a_11;
	}
	Matrix operator *(const Matrix& o) const {
		Matrix ret;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					ret.value[i][j] = (ret.value[i][j] + value[i][k] * o.value[k][j]) % MOD;
				}
			}
		}
		return ret;
	}
	Matrix fastpower(ll power) {
		Matrix tmp = *this;
		Matrix ret = Matrix(1, 0, 0, 1);
		while (power) {
			if (power & 1)ret = ret * tmp;
			tmp = tmp * tmp;
			power >>= 1;
		}
		return ret;
	}
};
ll input;
int main() {
	Matrix standard = Matrix(3, 5, 1, 3);
	while (scanf("%llu", &input) != EOF) {
		printf("%05llu\n", ((standard.fastpower(input).value[0][0] << 1) - 1) % MOD);
	}
}