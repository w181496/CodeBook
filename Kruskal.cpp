int u[MAXM], v[MAXM], w[MAXM], p[MAXN], r[MAXM], ans, chk, n, m;
bool cmp(int a, int b) { return w[a] < w[b]; } 
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
int kruskal()
{
    chk = n;
    for(int i = 0; i < n; ++i) r[i] = i;
    for(int i = 0; i < n; ++i) p[i] = i;
    sort(r, r + m, cmp);
    for(int i = 0; i < m; ++i)
    {
         int a, b, c;
         c = r[i];
         a = find(u[c]);
         b = find(v[c]);
         if(a != b)
         {
             ans += w[c];
             p[a] = b;
             chk--;
         }
    }
    //判斷連通
    if(chk == 1) return ans;
    else return -1;
}


