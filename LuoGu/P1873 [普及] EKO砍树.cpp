// https://www.luogu.com.cn/problem/P1873
// 二分
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
i64 n, target;
bool check(i64 val, i64 *a)
{
    i64 res = 0, i = upper_bound(a + 1, a + 1 + n, val) - a;
    while (i <= n)
        res += a[i++] - val;
    cout << res << " " << val << "\n";
    return res >= target;
}
void solve()
{
    cin >> n >> target;
    i64 a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    i64 l = 0, r = 1e10;
    while (r > l)
    {
        // 加1防止无限循环
        i64 mid = (l + r + 1) >> 1;
        if (check(mid, a))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
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