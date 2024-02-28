#include <bits/stdc++.h>
using namespace std;
// https : // www.lanqiao.cn/problems/5130/learning/?contest_id=144
#define i64 long long
int n, m, q, N;
void solve()
{
    cin >> n >> m >> q;
    N = n + 5;
    // 数据范围过大 用longlong
    i64 dp[N], s[N] = {0};
    vector<pair<int, int>> v(N);
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        s[x] = 1;
    }
    for (int i = 1; i < N; i++)
    {
        s[i] += s[i - 1];
        // cout << s[i] << "\n";
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].first >> v[i].second;
        v[i].first = 1 << v[i].first;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        // cout << dp[i];
        for (int j = 0; j < m; j++)
        {
            int r = i - v[j].first;
            if (r >= 0 && s[r] == s[i])
            {
                dp[i] = max(dp[i], dp[r] + v[j].second);
            }
        }
    }
    cout << dp[n];
    return;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}