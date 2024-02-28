// https://www.luogu.com.cn/problem/P4715
// 模拟、递归
#include <bits/stdc++.h>
using namespace std;
int a[2 << 7];
int b[2 << 7];
void func(int size)
{
    if (size == 2)
    {
        cout << (a[b[1]] > a[b[2]] ? b[2] : b[1]);
        return;
    }
    int _size = size >> 1;
    for (int i = 1; i <= size; i += 2)
        b[i + 1 >> 1] = a[b[i]] > a[b[i + 1]] ? b[i] : b[i + 1];

    for (int i = 1; i <= _size; ++i)
        cout << b[i] << " ";
    cout << "\n";
    func(_size);
}

void solve()
{
    int n;
    cin >> n;
    n = 2 << n - 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = i;
    }
    func(n);
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