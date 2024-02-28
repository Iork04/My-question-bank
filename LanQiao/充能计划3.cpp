#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 1e5 + 10;
int n, m, q;
int w[N];
int lazy[N << 2], val[N << 2];

inline void pushUp(int p)
{
    val[p] = val[p << 1] + val[p << 1 | 1];
}

inline void pushDown(int p, int l, int r)
{
    if (lazy[p])
    {
        int mid = l + r >> 1;
        lazy[p << 1] += lazy[p], lazy[p << 1 | 1] += lazy[p];
        val[p << 1] += lazy[p] * (mid - l + 1), val[p << 1 | 1] += lazy[p] * (r - mid);
        lazy[p] = 0;
    }
}

void update(int p, int l, int r, int _l, int _r, int v)
{
    if (_l > r)
        return;
    if (_l <= l && r <= _r)
    {
        val[p] += v * (r - l + 1);
        lazy[p] += v;
        return;
    }
    pushDown(p, l, r);
    int mid = l + r >> 1;
    if (mid >= _l)
        update(p << 1, l, mid, _l, _r, v);
    if (mid < _r)
        update(p << 1 | 1, mid + 1, r, _l, _r, v);
    pushUp(p);
}

void printTree(int p, int l, int r)
{
    if (l == r)
    {
        cout << val[p] << " ";
        return;
    }
    pushDown(p, l, r);
    int mid = l + r >> 1;
    printTree(p << 1, l, mid);
    printTree(p << 1 | 1, mid + 1, r);
}

struct st
{
    int p, k;
} a[N];

bool cmp(st &a, st &b)
{
    if (a.p == b.p)
        return a.k < b.k;
    return a.p < b.p;
}

void solve()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i)
        cin >> w[i];
    for (int i = 1; i <= q; ++i)
        cin >> a[i].p >> a[i].k;
    sort(a + 1, a + 1 + q, cmp);
    int pos = 0, now = 0;

    for (int i = 1; i <= q; ++i)
    {
        if (a[i].p > now)
            pos = a[i].k, now = a[i].p;

        if (a[i].k + w[now] > pos)
        {
            update(1, 1, n, (pos > a[i].k ? pos : a[i].k), a[i].k + w[now] - 1, 1);
            pos = a[i].k + w[now];
        }
    }
    printTree(1, 1, n);
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}