// https://www.luogu.com.cn/problem/P1241
// 模拟、队列
#include <bits/stdc++.h>
using namespace std;
string s;
bool a[105];
void find(int size, char c)
{
    for (int i = size - 1; i >= 0; --i)
    {
        if (!a[i] && (s[i] == '(' || s[i] == '['))
        {
            if (a[i] || s[i] != c)
                return;
            a[i] = a[size] = 1;
            return;
        }
    }
}
void solve()
{
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ')')
            find(i, '(');
        else if (s[i] == ']')
            find(i, '[');
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (a[i])
            cout << s[i];
        else
        {
            if (s[i] == ')' || s[i] == '(')
                cout << "()";
            else if (s[i] == ']' || s[i] == '[')
                cout << "[]";
        }
    }
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