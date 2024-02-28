#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 1e5 + 10;
int n, m, q;
int w[N];
int h[N << 1];
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
            pos = 0, now = a[i].p;
        if (a[i].k >= pos)
        {
            ++h[a[i].k];
            pos = a[i].k + w[now];
            --h[pos];
        }
        else if (a[i].k + w[now] > pos)
        {
            ++h[pos];
            pos = a[i].k + w[now];
            --h[pos];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        h[i] = h[i - 1] + h[i];
        cout << h[i] << " ";
    }
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