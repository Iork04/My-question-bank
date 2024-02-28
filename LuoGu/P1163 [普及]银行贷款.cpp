// https://www.luogu.com.cn/problem/P1163
// 数学、二分
#include <bits/stdc++.h>
using namespace std;
#define i64 long long

void solve()
{
    double n, m, k;
    cin >> n >> m >> k;
    double ans;
    double l = 0, r = 500;
    double mid;
    while (r > l)
    {
        mid = (l + r + 0.001) / 2;
        double ans = n;
        for (int i = 0; i < k; i++)
            ans = ans * (1 + mid / 100) - m;
        // cout << mid << " " << ans << "\n";
        if (ans > 0)
            r = mid - 0.001;
        else
            l = mid;
    }
    cout << fixed << setprecision(1) << l << endl;
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