// https://www.luogu.com.cn/problem/P1540
// 模拟、队列
#include <bits/stdc++.h>
using namespace std;

void solve1()
{
    int m, n, ans = 0;
    set<int> s;
    queue<int> q;
    cin >> m >> n;
    while (n--)
    {
        int word;
        cin >> word;
        if (s.find(word) != s.end())
            continue;
        ++ans;
        if (q.size() == m)
        {
            s.erase(q.front());
            q.pop();
        }
        s.insert(word);
        q.push(word);
    }
    cout << ans;
}

void solve2()
{
    int n, m, l = 0, r = 0, ans = 0;
    cin >> m >> n;
    int a[n + 10];
    memset(a, 0, sizeof(a));
    while (n--)
    {
        int word;
        cin >> word;
        if (find(a + l, a + r, word) != a + r)
            continue;
        if (r - l == m)
            ++l;
        a[r++] = word;
        ++ans;
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve2();
    return 0;
}