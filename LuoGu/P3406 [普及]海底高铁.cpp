// https://www.luogu.com.cn/problem/P3406
// 前缀和
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, cur = 1, next, ans = 0;
    cin >> n >> m;
    long long d[n + 2];
    long long a[n], b[n], c[n];
    memset(d, 0, sizeof(d));
    if (m > 0)
        cin >> cur;
    for (int i = 2; i <= m; ++i)
    {
        cin >> next;
        if (cur < next)
            d[cur] += 1, d[next] -= 1;
        else
            d[next] += 1, d[cur] -= 1;
        cur = next;
    }
    for (int i = 1; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i < n; ++i)
        d[i] = d[i - 1] + d[i];
    for (int i = 1; i < n; ++i)
    {
        if (d[i] == 0)
            continue;
        ans += min(d[i] * a[i], d[i] * b[i] + c[i]);
    }
    if (m <= 1)
        ans = 0;
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}