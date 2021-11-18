#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 100000;

namespace ModInt
{
    //for big mod only
    //using % and function-neg simply for small mod
    inline int modint(int a)
    {
        while (a < 0)
            a += mod;
        return a % mod;
    }
    inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
    inline int sub(int a, int b) { return a < b ? a - b + mod : a - b; }
    inline int mul(int a, int b) { return (1ll * a * b) % mod; }
    inline int neg(int a) { return (1ll * a * (mod - 1)) % mod; }
}
using namespace ModInt;
namespace ExtensionFields
{
    //template<int c>
    //a + b * sqrt(c)
    struct complex
    {
        static const int c = 5;
        int a, b;
        complex(int _a = 0, int _b = 0) : a(_a), b(_b) {}

        inline complex operator+(const complex &o) const { return complex(add(a, o.a), add(b, o.b)); }
        inline complex operator-(const complex &o) const { return complex(sub(a, o.a), sub(b, o.b)); }
        inline complex operator-(const int &o) const { return complex(sub(a, o), b); }
        inline complex operator*(const complex &o) const
        {
            return complex(add(mul(a, o.a), mul(mul(c, b), o.b)), add(mul(a, o.b), mul(o.a, b)));
        }
        inline complex operator*(const int &o) const { return complex(mul(a, o), mul(b, o)); }
        inline complex operator^(ll o) const
        {
            complex ret = complex(1, 0), tmp = complex(add(0, a), add(0, b));
            while (o)
            {
                if (o & 1)
                    ret = ret * tmp;
                tmp = tmp * tmp;
                o >>= 1;
            }
            return ret;
        }
    };
}
using namespace ExtensionFields;

ll T;
ll m, n; int x;

int main()
{
    
    while(scanf("%lld", &n) != EOF) 
    {
        complex ans = complex(3, 1) ^ n;
        printf("%05lld\n", ((ans.a << 1) - 1) % mod);
    }
}
