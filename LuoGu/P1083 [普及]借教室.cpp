// https://www.luogu.com.cn/problem/P1083
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N = 1e6 + 10;
int n, m;
bool flag = 1;
int has[N];
struct pl
{
    int d, s, t;
} p[N];

bool chick(int x)
{
    vector<int> d(n + 2, 0);
    for (int i = 1; i <= x; ++i)
    {
        d[p[i].s] += p[i].d;
        d[p[i].t + 1] -= p[i].d;
    }
    for (int i = 1; i <= n; ++i)
    {
        d[i] += d[i - 1];
        if (has[i] < d[i])
        {
            flag = 0;
            return false;
        }
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> has[i];
    for (int i = 1; i <= m; ++i)
        cin >> p[i].d >> p[i].s >> p[i].t;

    int l = 0, r = m;
    while (r > l)
    {
        int mid = (r + l + 1) >> 1;
        if (chick(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (flag)
        cout << 0;
    else
        cout << -1 << "\n"
             << l+1;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}