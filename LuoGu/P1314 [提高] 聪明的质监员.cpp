// https://www.luogu.com.cn/problem/P1314
// 二分、前缀和
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N = 2e5 + 10;
i64 m, n, s, ans = 1e18;
int ma = 0, mi = 1e9;
int ls[N], rs[N];
i64 pre_n[N], pre_v[N];
struct mineral
{
    int w, v;
} ml[N];

bool check(int W)
{
    i64 Y = 0, sum = 0;
    memset(pre_n, 0, sizeof(pre_n));
    memset(pre_v, 0, sizeof(pre_v));
    int i = 1;
    for (int i = 1; i <= n; i++)
    {
        if (ml[i].w >= W)
            pre_n[i] = pre_n[i - 1] + 1, pre_v[i] = pre_v[i - 1] + ml[i].v;
        else
            pre_n[i] = pre_n[i - 1], pre_v[i] = pre_v[i - 1];
    }

    for (int j = 1; j <= m; ++j)
        Y += (pre_n[rs[j]] - pre_n[ls[j] - 1]) * (pre_v[rs[j]] - pre_v[ls[j] - 1]);
    sum = llabs(Y - s);
    ans = min(ans, sum);
    if (Y > s)
        return true;
    else
        return false;
}

void solve()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ml[i].w >> ml[i].v;
        mi = min(mi, ml[i].w);
        ma = max(ma, ml[i].w);
    }
    for (int i = 1; i <= m; ++i)
        cin >> ls[i] >> rs[i];
    int l = mi, r = ma + 2;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << ans;
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