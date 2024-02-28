// https://www.lanqiao.cn/problems/8733/learning/?contest_id=147
#include <bits/stdc++.h>
using namespace std;
void solve1()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    while (q--)
    {
        int op, i, j, k;
        cin >> op;
        if (op == 1)
        {
            cin >> i >> j >> k;
            while (a[i].size() < j)
                a[i].push_back(0);
            a[i][j - 1] = k;
        }
        else
        {
            cin >> i >> j;
            if (a[i].size() < j - 1)
                cout << 0 << "\n";
            else
                cout << a[i][j - 1] << "\n";
        }
    }
}
void solve2()
{
    int n, q;
    cin >> n >> q;
    map<long long, int> m;
    while (q--)
    {
        int op, i, j, k;
        cin >> op;
        if (op == 1)
        {
            cin >> i >> j >> k;
            m[i * 1e5 + j] = k;
        }
        else
        {
            cin >> i >> j;
            cout << m[i * 1e5 + j] << "\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve1();
    return 0;
}