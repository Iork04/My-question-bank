// https://www.luogu.com.cn/problem/P3853
// 贪心、二分
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], l, n, k;

bool check(int target)
{
    int now = 0, t = 0;
    for (int i = 1; i <= n; ++i)
    {
        int val = a[i] - now;
        if (val > target)
        {
            ++t, --i;
            now+=target;
            if (t > k)
                return false;
        }
        else
            now = a[i];
    }
    return true;
}

void solve()
{
    cin >> l >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 1, r = 1e8 + 10;
    check(25);
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
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