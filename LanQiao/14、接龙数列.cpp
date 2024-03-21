
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int> dp(10, 0);
    string str;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> str;
        dp[str[str.size() - 1] - '0'] = max(dp[str[str.size() - 1] - '0'], dp[str[0] - '0'] + 1);
    }
    int ans = INT_MAX;
    for (int i = 0; i <= 9; ++i)
    {
        // cout << dp[i] << " ";
        ans = min(ans, n - dp[i]);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}