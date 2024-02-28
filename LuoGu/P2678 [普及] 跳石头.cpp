// https://www.luogu.com.cn/problem/P2678
// 贪心、二分
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int a[N], l, n, m;

bool check(int target)
{
    int now = 0, _count = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        int val = a[i] - now;
        if (val < target)
        {
            ++_count;
            if (_count > m)
                return false;
        }
        else
            now = a[i];
    }
    return _count <= m ? true : false;
}
void solve()
{
    cin >> l >> n >> m;
    a[0] = 0, a[n + 1] = l;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 1, r = 1e9 + 10;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}