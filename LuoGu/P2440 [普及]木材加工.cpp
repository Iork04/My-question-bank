// https://www.luogu.com.cn/problem/P2440
// 贪心、二分、递归
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 1e5 + 10;
int a[N], k, n;
bool check(int val)
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += a[i] / val;
    return res >= k;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 0, r = 1e8;
    while (r > l)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
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