// https://www.lanqiao.cn/problems/2415/learning/?page=1&first_category_id=1&tags=2023
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N = 2e6 + 10;
vector<int> arr(N, 0x3f3f3f3f);

void solve()
{
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    cin >> k;
    deque<int> que;
    for (int i = 1; i <= n + k; ++i)
    {
        while (!que.empty() && arr[que.back()] >= arr[i])
            que.pop_back();
        while (!que.empty() && que.front() < i - 2 * k)
        {
            // cout << i << " " << que.front() << "\n";
            que.pop_front();
        }
        que.push_back(i);
        if (i > k)
            cout << arr[que.front()] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}