#include <bits/stdc++.h>
using namespace std;
int n, k;
// https : // www.lanqiao.cn/problems/5129/learning/?contest_id=144
// 检查是否可以分成k组
bool check(int *arr, int mid, int _k)
{
    int pre = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pre > mid)
        {
            _k--;
            pre = arr[i];
        }
    }
    return _k > 0;
}
void solve()
{
    cin >> n >> k;
    if (n <= k)
    {
        cout << 0;
        return;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    //二分查找最大极差
    int l = 0, r = arr[n - 1];
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(arr, mid, k))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}