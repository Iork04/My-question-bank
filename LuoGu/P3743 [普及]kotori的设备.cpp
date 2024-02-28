// https://www.luogu.com.cn/problem/P3743
// 贪心、二分
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct st
{
    double a, b;
} s[N];
double n, p;

bool check(double target)
{
    double now = target * p;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i].b >= s[i].a * target)
            continue;
        else
        {
            now -= s[i].a * target - s[i].b;
            if (now < 0)
                return false;
        }
    }
    return true;
}

void solve()
{
    cin >> n >> p;
    double sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i].a >> s[i].b;
        sum += s[i].a;
    }
    if (sum <= p)
    {
        cout << "-1";
        return;
    }
    double l = 0, r = 1e10;
    while (r - l > 1e-6)
    {
        double mid = (r + l) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(10) << l;
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