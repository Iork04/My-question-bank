// https://www.luogu.com.cn/problem/P3879
// Trie、hash
#include <bits/stdc++.h>
using namespace std;

int n, o, k;
string str;
void solve()
{
    cin >> n;
    vector<unordered_set<string>> m(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        while (k--)
        {
            cin >> str;
            m[i].insert(str);
        }
    };

    cin >> o;
    while (o--)
    {
        cin >> str;
        for (int i = 0; i < n; ++i)
        {
            if (m[i].find(str) != m[i].end())
                cout << i+1 << " ";
        }
        cout << "\n";
    }
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