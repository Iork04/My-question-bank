// https://www.luogu.com.cn/problem/P1083
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, p;
    bool operator<(const node &other) const
    {
        return this->x < other.x;
    }
} a[50010];

void solve()
{
    int n, m, ans = 1e9;
    cin >> n;
    set<int> ty;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].p;
        ty.insert(a[i].p);
    }
    m = ty.size();
    sort(a + 1, a + 1 + n);

    // for (int i = 1; i <= n; ++i)
    //     cout << a[i].x << " " << a[i].p << "\n";

    map<int, int> t;
    int e = 1, z = 1;
    t[a[e].p]++;
    for (int i = 1; i <= n; ++i)
    {
        while (z != m && e < n)
        {
            ++e;
            ++t[a[e].p];
            if (t[a[e].p] == 1)
                ++z;
        }
        if (m == z)
            ans = min(ans, a[e].x - a[i].x);

        --t[a[i].p];
        if (t[a[i].p] == 0)
            --z;
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