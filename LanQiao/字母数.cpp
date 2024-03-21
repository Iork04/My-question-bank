#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

bool check(i64 v)
{
    while (v)
    {
        i64 _v = v % 16;
        if (_v < 10)
            return false;
        v /= 16;
    }
    return true;
}

void solve()
{
    for (i64 i = 2023;; i++)
    {
        if (check(i))
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
