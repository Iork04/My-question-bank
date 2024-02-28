// https://www.luogu.com.cn/problem/P4995
// 贪心、排序
#include <bits/stdc++.h>
using namespace std;
int a[40100];
long long ans;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r = n, now = 0;
    while (r >= l)
    {
        if (now > r)
        {
            ans += (a[now] - a[l]) * (a[now] - a[l]);
            now = l,
            ++l;
        }
        else
        {
            ans += (a[now] - a[r]) * (a[now] - a[r]);
            now = r,
            --r;
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