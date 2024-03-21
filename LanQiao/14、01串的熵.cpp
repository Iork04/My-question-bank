#include <bits/stdc++.h>
using namespace std;

int total = 23333333;
double H = 11625907.5798;

void solve()
{
    for (int i = 0; i < total / 2; ++i)
    {
        double ans = 0;
        ans -= 1.0 * i * i / total * log2(1.0 * i / total);
        ans -= 1.0 * (total - i) * (total - i) / total * log2(1.0 * (total - i) / total);
        if (abs(H - ans) < 1e-4)
        {
            cout << i;
            return;
        }
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