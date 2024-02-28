// https://www.luogu.com.cn/problem/P1182
// 贪心、二分
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], n, m;

bool check(int target)
{
    // count需要初始化为1
    int now = 0, count = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (now + a[i] <= target)
        {
            now += a[i];
        }
        else
        {
            now = a[i], ++count;
            if (count > m || now > target)
                return false;
        }
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 1, r = 1e9 + 10;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r;
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