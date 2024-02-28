// https://www.luogu.com.cn/problem/P5250
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

void solve()
{
    int n, op, len;
    set<int> m;
    cin >> n;
    while (n--)
    {
        cin >> op >> len;
        if (op == 1)
        {
            if (m.find(len) != m.end())
                cout << "Already Exist\n";
            else
                m.insert(len);
        }
        else
        {
            if (m.empty())
            {
                cout << "Empty\n";
                continue;
            }
            auto it = m.lower_bound(len);
            // cout << *(--it) << "\n";
            if (it == m.end() || it == m.begin())
                cout << (it == m.end() ? *(--it) : *it) << "\n";
            else if (*it == len)
                cout << *it << "\n";
            else
                cout << (*it - len >= len - *next(it, -1) ? *(--it) : *it) << "\n";
            m.erase(it);
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