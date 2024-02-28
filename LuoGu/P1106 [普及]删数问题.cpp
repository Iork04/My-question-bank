// https://www.luogu.com.cn/problem/P1106
// 贪心、字符串
#include <bits/stdc++.h>
using namespace std;
string str;
string ans = "";
int l = 0;
char find(int r)
{
    char minChar = '9';
    for (int i = l; i <= r; ++i)
    {
        if (minChar > str[i])
        {
            minChar = str[i];
            str[i] = '9';
            l = i;
        }
    }
    return minChar;
}
void delZero()
{
    if (ans.size() == 1 || ans[0] != '0')
        return;
    if (ans[0] == '0')
        ans.erase(ans.begin());
    delZero();
}
void solve()
{
    cin >> str;
    int k, n;
    cin >> k;
    n = str.size() - k;
    if (k >= str.size())
        n = 0, ans = "0";
    while (n--)
    {
        ans += find(str.size() - n - 1);
    }
    delZero();
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("../in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}