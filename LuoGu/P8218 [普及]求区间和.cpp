// https://www.luogu.com.cn/problem/P8218
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << "\n";
    }
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