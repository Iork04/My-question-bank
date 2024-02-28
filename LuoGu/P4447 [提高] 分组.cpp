// https://www.luogu.com.cn/problem/P4447
// 贪心、二分、队列
#include <bits/stdc++.h>
using namespace std;

// map做法
void solve1()
{
    map<int, int> m;
    int n, ans = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        ++m[val];
    }
    while (!m.empty())
    {
        auto l = m.begin(), r = m.begin();
        int t = 1;
        ++r;
        --(*l).second;
        while (r != m.end() && (*r).second > (*l).second && (*l).first + 1 == (*r).first)
        {
            ++t;
            --(*r).second;
            ++l, ++r;
        }
        l = m.begin();
        while (l != m.end() && (*l).second == 0)
            m.erase((*l++).first);
        ans = min(t, ans);
    }
    cout << ans;
}

// 二分
void solve2()
{
    int n;
    cin >> n;
    int a[n + 1], q[n + 1], ans = INT_MAX, _size[n + 1], top = 0;
    q[0] = INT_MAX;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; ++i)
    {
        // 如果没找到则返回在排序保持情况下val插入位置
        int pos = lower_bound(q + 1, q + 1 + top, a[i]) - q;
        // cout << pos << " ";
        while (pos < top && q[pos + 1] == a[i])
            ++pos;
        if (pos > top || q[pos] != a[i])
            _size[++top] = 1, q[top] = a[i] + 1;
        else
            ++_size[pos], ++q[pos];
    }
    for (int i = 1; i <= top; ++i)
        ans = min(ans, _size[i]);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("../in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve2();
    return 0;
}