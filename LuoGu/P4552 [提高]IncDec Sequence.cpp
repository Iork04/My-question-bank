// https://www.luogu.com.cn/problem/P4552
// 差分
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    long long a[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    long long q = 0, p = 0;
    for (int i = 2; i <= n; ++i)
    {
        int c = a[i] - a[i - 1];
        if (c > 0)
            q += c;
        else
            p -= c;
    }
    cout << max(p, q) << "\n"
         << abs(p - q) + 1;
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