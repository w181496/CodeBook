int fastpow(int a, int b)
{
    int r = 1, base = a;
    while(b != 0)
    {
        if(b & 1)
            r *= base;
        base *= base;
        b >>= 1;  
    }
    return r;
}
