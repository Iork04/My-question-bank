// https://www.luogu.com.cn/problem/P1208
// 贪心、模拟、排序
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
struct st
{
    int p, a;
} a[N];
bool cmp(st &l, st &r)
{
    return l.p < r.p;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i].p >> a[i].a;
    }
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; ++i)
    {
        if (a[i].a <= n)
        {
            n -= a[i].a;
            ans += a[i].p * a[i].a;
        }
        else
        {
            ans += a[i].p * n;
            break;
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