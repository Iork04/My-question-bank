#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/problem/P1223
// 贪心、排序
struct asd
{
    int num, val;
} a[1010];
bool cmp(struct asd &a, struct asd &b)
{
    return a.val < b.val;
};

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("../in.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i].num = i;
        cin >> a[i].val;
    }
    sort(a + 1, a + 1 + n, cmp);
    long long ans = 0, now = 0;

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i].num << " ";
        now += a[i - 1].val;
        ans += now;
    }
    cout << "\n"
         << fixed << setprecision(2) << (double)ans / n;
}
