#include <stdio.h>
#include <math.h>
const double eps = 1e-9;
typedef long long ll;
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
// p / q
typedef struct rational
{
    ll p, q;
} rational;
rational plus(rational a, rational b)
{
    rational ret;
    ret.p = a.p * b.q + a.q * b.p;
    ret.q = a.q * b.q;
    ll g = gcd(ret.p, ret.q);
    ret.p /= g;
    ret.q /= g;
    return ret;
}
rational minus(rational a, rational b)
{
    rational ret;
    ret.p = a.p * b.q - a.q * b.p;
    ret.q = a.q * b.q;
    ll g = gcd(ret.p, ret.q);
    ret.p /= g;
    ret.q /= g;
    return ret;
}
rational mul(rational a, rational b)
{
    rational ret;
    ret.p = a.p * b.p;
    ret.q = a.q * b.q;
    ll g = gcd(ret.p, ret.q);
    ret.p /= g;
    ret.q /= g;
    return ret;
}
rational div(rational a, rational b)
{
    rational ret;
    ret.p = a.p * b.q;
    ret.q = a.q * b.p;
    ll g = gcd(ret.p, ret.q);
    ret.p /= g;
    ret.q /= g;
    return ret;
}
rational plus_ll(rational a, ll b)
{
    rational ret;
    ret.p = a.p + a.q * b;
    ret.q = a.q;
    ll g = gcd(ret.p, ret.q);
    ret.p /= g;
    ret.q /= g;
    return ret;
}
rational mul_ll(rational a, ll b)
{
    rational ret;
    ret.p = a.p * b;
    ret.q = a.q;
    ll g = gcd(ret.p, ret.q);
    ret.p /= g;
    ret.q /= g;
    return ret;
}
// a + b * sqrt(d)
typedef struct quaderic
{
    rational a;
    rational b;
    ll d;
} quaderic;
ll integer_part(quaderic a) { return (ll)((double)a.a.p / (double)a.a.q + (double)a.b.p / (double)a.b.q * (double)sqrt(a.d) + eps); }
quaderic trans(quaderic a)
{
    ll real = integer_part(a);
    printf("%lld ", real);
    quaderic nxt;
    // (a - real) + b sqrt(d) 
    nxt.d = a.d, nxt.b = a.b;
    nxt.a = plus_ll(a.a, -real);
    // denominator : b * b * d - (a - real)^2
    rational denominator = minus(mul_ll(mul(nxt.b, nxt.b), nxt.d), mul(nxt.a, nxt.a));
    // ((real - a) + b sqrt(d)) / denominator
    nxt.a = mul_ll(nxt.a, -1ll);
    // print_quaderic(nxt);
    nxt.a = div(nxt.a, denominator);
    nxt.b = div(nxt.b, denominator);
    return nxt;
}
ll d, n;
int main()
{
    scanf("%lld%lld", &d, &n);
    quaderic qua;
    // initial : 0 + 1 sqrt(d)
    qua.a.p = 0, qua.a.q = 1, qua.b.p = 1, qua.b.q = 1, qua.d = d;
    for (int i = 0; i <= n; ++i)
        qua = trans(qua);
}