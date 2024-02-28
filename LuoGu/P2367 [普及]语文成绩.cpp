// https://www.luogu.com.cn/problem/P2367
// 差分、前缀和
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, p, ans = 1e9;
    cin >> n >> p;
    int a[n + 2], b[n + 2];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= p; ++i)
    {
        int x, y, v;
        cin >> x >> y >> v;
        b[x] += v;
        b[y + 1] -= v;
    }
    for (int i = 1; i <= n; ++i)
        b[i] = b[i - 1] + b[i];
    for (int i = 1; i <= n; ++i)
        ans = min(ans, a[i] + b[i]);
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