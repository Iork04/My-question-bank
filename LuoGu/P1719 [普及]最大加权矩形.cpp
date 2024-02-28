// https://www.luogu.com.cn/problem/P1719
// 前缀和、dp
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, ans = -1e9;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 0; i <= n; ++i)
        a[0][i] = 0, a[i][0] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            a[i][j] = a[i - 1][j] + a[i][j - 1] + a[i][j] - a[i - 1][j - 1];
        }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
        {
            for (int i1 = i; i1 <= n; ++i1)
                for (int j1 = j; j1 <= n; ++j1)
                {
                    int now = a[i1][j1] + a[i][j] - a[i1][j] - a[i][j1];
                    if (ans < now)
                        ans = now;
                }
        }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}