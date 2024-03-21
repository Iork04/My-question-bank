// https://www.lanqiao.cn/problems/3491/learning/?page=1&first_category_id=1&tags=2023
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int ans = 0;

bool check(int val)
{
    int _count = (int)(log10(val) + 1) / 2;
    int a = 0, b = 0;
    int _ = _count;

    while (_--)
    {
        a += val % 10;
        val /= 10;
    }
    _ = _count;
    while (_--)
    {
        b += val % 10;
        val /= 10;
    }
    return a == b;
}

// 暴力解法
void solve1()
{
    int ans = 0;
    for (int i = 1; i <= 1e8; ++i)
    {
        if ((int)(log10(i) + 1) % 2)
            continue;
        if (check(i))
            ans++;
    }
    cout << ans;
}

int a[5][50];

void check2(int val)
{
    int sum = 0;
    int t = 0;
    while (val)
    {
        t++;
        sum += val % 10;
        val /= 10;
    }
    a[t][sum]++;
}

void solve2()
{
    for (int i = 1; i <= 9999; ++i)
        check2(i);

    int ans = 0;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 36; ++j)
            for (int k = 1; k <= i; ++k)
                ans += a[i][j] * a[k][j];
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve2();
    return 0;
}