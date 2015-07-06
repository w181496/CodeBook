#include <iostream>
#include <cstdlib>
using namespace std;
struct Treap
{
    Treap *l, *r;
    int size, pri, val, sum;
    Treap(){}
    Treap(int _val) :
        l(NULL), r(NULL), pri(rand()), size(1), val(_val), sum(_val){}
};

int sum(Treap *t) {
    return t ? t->sum : 0;
}

int size(Treap *t) {
    return t ? t->size : 0;
}

void pull(Treap *t) {
    t->sum = sum(t->l) + sum(t->r) + t->val;
    t->size = size(t->l) + size(t->r) + 1;
}

Treap* merge(Treap *a, Treap *b)
{
    if(!a || !b) return a ? a : b;
    if(a->pri > b->pri)
    {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    else
    {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

void split(Treap *t, int k, Treap *&a, Treap *&b)
{
    if(!t) a = b = NULL;
    else if(size(t->l) + 1 <= k)
    {
        a = t;
        split(t->r, k - size(t->l) - 1, a->r, b);
        pull(a);
    }
    else
    {
        b = t;
        split(t->l, k, a, b->l);
        pull(b);
    }
}

int main()
{
    int t, n, m, e, l, r, tmp;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        Treap *t = NULL, *tr, *tl;
        for(int i = 0; i < n; ++i)
        {
            cin >> tmp;
            Treap *add = new Treap(tmp);
            t = merge(t, add);
        }
        for(int i = 0; i < m; ++i)
        {
            cin >> e >> l >> r;
            if(e == 1)
            {
                split(t, l - 1, tl, t);
                split(t, r - l + 1, t, tr);
                t = merge(merge(t, tl), tr);
            }
            else
            {
                split(t, l - 1, tl, t);
                split(t, r - l + 1, t, tr);
                cout << sum(t) << endl;
                t = merge(merge(tl, t), tr);
            }
        }
    }
    return 0;
}

