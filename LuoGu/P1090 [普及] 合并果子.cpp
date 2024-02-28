// https://www.luogu.com.cn/problem/P1090
// 贪心、堆、优先队列
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> que(a.begin(), a.end());
    while (que.size() != 1)
    {
        int sum = 0;
        sum += que.top();
        que.pop();
        sum += que.top();
        que.pop();
        ans += sum;
        que.push(sum);
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("../in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}