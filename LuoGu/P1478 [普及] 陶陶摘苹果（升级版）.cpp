// https://www.luogu.com.cn/problem/P1478
// 贪心、模拟、排序
#include <bits/stdc++.h>
using namespace std;
struct st
{
    int x, y;
} a[5010];
bool cmp(st &l, st &r)
{
    return l.y < r.y;
}
void solve()
{
    int n, s, h1, h2;
    cin >> n >> s >> h1 >> h2;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
    {
        if (s >= a[i].y && a[i].x <= h1 + h2)
        {
            s -= a[i].y;
            ++ans;
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