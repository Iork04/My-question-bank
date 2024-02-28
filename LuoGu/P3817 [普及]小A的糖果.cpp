// https://www.luogu.com.cn/problem/P3817
// 贪心、模拟
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    long long ans = 0;
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        if (m < a[i - 1] + a[i])
        {
            ans += a[i - 1] + a[i] - m;
            a[i] = m - a[i - 1];
        }
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("../in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}