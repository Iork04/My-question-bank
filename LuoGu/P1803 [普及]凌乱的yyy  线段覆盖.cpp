// https://www.luogu.com.cn/problem/P1803
// 搜索、贪心、排序
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct st
{
    int s, e;
} a[N];
bool cmp(st &l, st &r)
{
    if (l.e == r.e)
        return l.s > r.s;
    return l.e < r.e;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].s >> a[i].e;
    sort(a + 1, a + 1 + n, cmp);
    long long now = 0, cur = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (cur == a[i].e)
            continue;
        cur = a[i].e;
        if (now <= a[i].s)
        {
            ++ans;
            now = cur;
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