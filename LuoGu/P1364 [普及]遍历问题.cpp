// https://www.luogu.com.cn/problem/P1229
// 递归
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int ans = 0;
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); ++i)
    {
        for (int j = 1; j < str2.size(); ++j)
        {
            if (str1[i] == str2[j] && str1[i + 1] == str2[j - 1])
                ++ans;
        }
    }
    cout << (1 << ans);
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