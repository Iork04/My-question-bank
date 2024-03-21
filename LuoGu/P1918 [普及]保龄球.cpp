// https://www.luogu.com.cn/problem/P1918
// 二分、模拟
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q, target;
vector<i64<int, int>> p(N);

int find(int v)
{
    int l = 1, r = n;
    while (r > l)
    {
        int mid = (l + r) >> 1;
        if (p[mid].first >= v)
            r = mid;
        else
            l = mid + 1;
    }
    return p[r].first == v ? p[r].second : 0;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    cin >> q;
    sort(p.begin() + 1, p.begin() + n + 1);
    // for (int i = 1; i <= n; ++i)
    //     cout << p[i].first << " " << p[i].second << "\n";
    while (q--)
    {
        cin >> target;
        cout << find(target) << "\n";
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