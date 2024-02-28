// https://www.luogu.com.cn/problem/P5019
// 贪心、树状数组
#include <bits/stdc++.h>
using namespace std;
// 模拟做法
void solve1()
{
    int n, ans = 0;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int now = 1;
    while (now <= n)
    {
        while (now <= n && !a[now])
            ++now;
        if (now > n)
            break;
        int cur = now;
        while (a[cur] != 0)
            --a[cur++];
        ++ans;
    }
    cout << ans;
}
// 贪心
void solve2()
{
    int n, ans = 0;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > a[i - 1])
            ans += a[i] - a[i - 1];
    }
    cout << ans;
}
// 树状数组
class FenwickTree
{
private:
    vector<int> BIT;
    int N;

public:
    FenwickTree(int size)
    {
        BIT.resize(size + 1, 0);
        N = size;
    }

    void update(int index, int val)
    {
        while (index <= N)
        {
            BIT[index] += val;
            index += (index & -index);
        }
    }

    int query(int index)
    {
        int sum = 0;
        while (index > 0)
        {
            sum += BIT[index];
            index -= (index & -index);
        }
        return sum;
    }
};
void solve3()
{
    int n, ans = 0;
    cin >> n;
    FenwickTree fenwick(n);
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int i = 1;
    while (i <= n)
    {
        while (i <= n && a[i] + fenwick.query(i) == 0)
            ++i;
        if (i > n)
            break;
        int r = i + 1;
        while (r <= n && a[r] + fenwick.query(r))
            ++r;
        fenwick.update(i, -1), fenwick.update(r, 1);
        ++ans;
    }
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