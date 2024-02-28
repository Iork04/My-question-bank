// https://www.luogu.com.cn/problem/P1678
// 模拟、贪心、二分
#include <bits/stdc++.h>
using namespace std;
#define i64 long long

void solve()
{
    i64 m, n, ans = 0;
    cin >> m >> n;
    int a[m + 1];
    a[0] = INT_MAX;
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + m);
    while (n--)
    {
        int val;
        cin >> val;
        int index = upper_bound(a + 1, a + 1 + m, val) - a;
        ans += min(abs(a[index] - val), abs(a[index - 1] - val));
    }
    cout << ans;
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