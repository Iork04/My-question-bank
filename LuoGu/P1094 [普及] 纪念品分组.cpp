// https://www.luogu.com.cn/problem/P1094
// 贪心、排序
#include <bits/stdc++.h>
using namespace std;
int a[210], g, n, ans;
void solve()
{
    cin >> g >> n;
    for (int i = 1; i <= n; ++i)
    {
        int val;
        cin >> val;
        ++a[val];
    }
    int l, r = 200;
    while (r > 0)
    {
        while (r > 0 && !a[r])
            --r;
        if (r == 0)
            break;
        --a[r];
        l = g - r;
        while (l > 0 && !a[l])
            --l;
        --a[l], ++ans;
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