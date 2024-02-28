// https://www.luogu.com.cn/problem/P2249
// 二分、哈希、数学、排序
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
// 哈希做法
void solve1()
{
    i64 n, target, ans = 0;
    cin >> n >> target;
    int a[n + 1];
    map<int, int> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ++m[a[i]];
    }
    // 因为target>0，所以可以忽略a[i]==target的情况
    for (int i = 1; i <= n; ++i)
        ans += m[a[i] - target];
    cout << ans;
}
// 二分
void solve2()
{
    i64 n, target, ans = 0;
    cin >> n >> target;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
        ans += upper_bound(a + 1, a + 1 + n, a[i] - target) - lower_bound(a + 1, a + 1 + n, a[i] - target);
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("../in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve2();
    return 0;
}