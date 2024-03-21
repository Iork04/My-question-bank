#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int _min = INT_MIN, _max = INT_MAX;
    int n, a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        _min = max(a / (b + 1) + 1, _min);
        _max = min(a / b, _max);
    }
    cout << _min << " " << _max;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}