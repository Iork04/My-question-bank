// https://www.luogu.com.cn/problem/P5266
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

void solve()
{
    unordered_map<string, i64> m;
    int n, op;
    string name;
    i64 score;
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> name >> score;
            m[name] = score;
            cout << "OK\n";
        }
        else if (op == 2)
        {
            cin >> name;
            if (m.count(name))
                cout << m[name] << "\n";
            else
                cout << "Not found\n";
        }
        else if (op == 3)
        {
            cin >> name;
            if (m.count(name))
            {
                m.erase(name);
                cout << "Deleted successfully\n";
            }
            else
                cout << "Not found\n";
        }
        else
            cout << m.size() << "\n";
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