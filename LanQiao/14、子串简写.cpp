#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int sum[N];
void solve()
{
    int k;
    string str;
    char a, b;
    cin >> k >> str >> a >> b;
    for (int i = 1; i <= str.size(); ++i)
    {
        if (str[i - 1] == b)
            sum[i] = 1;
        sum[i] += sum[i - 1];
    }

    long long ans = 0;
    for (int i = 1; i + k - 1 <= str.size(); ++i)
    {
        if (str[i - 1] == a)
            ans += sum[str.size()] - sum[i + k - 2];
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