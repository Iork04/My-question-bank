#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 1e5 + 10;
int n, m, q;
int w[N];
int h[N];
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

void update(int i, int v)
{
    while (i <= n)
    {
        h[i] += v;
        i += i & -i;
    }
}

int query(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += h[i];
        i -= i & -i;
    }
    return res;
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
        {
            pos = a[i].k, now = a[i].p;
        }
        if (a[i].k + w[now] > pos)
        {
            update((pos > a[i].k ? pos : a[i].k), 1);
            pos = a[i].k + w[now];
            update(pos, -1);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << query(i) << " ";
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}