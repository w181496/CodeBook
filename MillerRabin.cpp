LL powmod (LL base, LL exp, LL mod)
{
    LL res = 1;
    base %= mod;
    while (exp) {
        if (exp % 2)
            res = res * (LL)base % mod;
        exp /= 2;
        base = base * (LL)base % mod;

    }
    return res;

}
bool isprime(LL n)
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    LL u = n - 1, t = 0;
    while (u % 2 == 0) {u >>= 1; t++;}
    LL sprp[3] = {2, 7, 61};
    for (LL k=0; k<3; ++k)
    {
        LL a = sprp[k] % n;
        if (a == 0 || a == 1 || a == n-1) continue;
        LL x = powmod(a, u,n);
        if (x == 1 || x == n-1) continue;
        for (LL i = 0; i < t-1; i++)
        {
            x = x*x%n;
            if (x == 1) return false;
            if (x == n-1) break;
        }
        if (x == n-1) continue;
        return false;
    }
    return true;
}
