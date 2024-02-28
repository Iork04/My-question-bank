// https://www.luogu.com.cn/problem/P3397
// 前缀和
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N = 2e4 + 10;
int n;
i64 ans = 0;
vector<i64> a(N), b(N);

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];

    sort(a.begin() + 1, a.begin() + n + 1);
    sort(b.begin() + 1, b.begin() + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        ans += b[i] - a[i];
        if ((b[i - 1] > a[i]) && i != 1)
            ans -= b[i - 1] - a[i];
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