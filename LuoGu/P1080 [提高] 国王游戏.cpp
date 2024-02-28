// https://www.luogu.com.cn/problem/P1080
// 贪心、排序、高精度
#include <bits/stdc++.h>
using namespace std;
char a[20000], b[20000], c[20000], ans[20000], now[20000];
int lenA, lenB, lenC, lenAns, lenNow;
struct st
{
    int x, y;
} d[10100];
bool cmp(st &a, st &b)
{
    return a.x * a.y < b.x * b.y;
}
void mult()
{

    memset(c, 0, sizeof(c));
    for (int i = 1; i <= lenA; ++i)
    {
        for (int j = 1; j <= lenB; ++j)
        {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
    }
    lenC = lenA + lenB;
    if (c[lenC] == 0)
        --lenC;
    lenA = lenC;
    for (int i = 1; i <= lenC; ++i)
        a[i] = c[i];
}
void div(int val)
{
    memset(now, 0, sizeof(now));
    int P = 0;
    lenNow = lenA;
    for (int i = lenA; i > 0; --i)
    {
        P = P * 10 + a[i];
        now[i] = P / val;
        P %= val;
    }

    while (lenNow > 1 && now[lenNow] == 0)
        --lenNow;
}
void getAns()
{

    bool flag = false;
    if (lenAns < lenNow)
        flag = true;
    else if (lenAns > lenNow)
        return;
    else
        for (int i = lenAns; i > 0; --i)
        {
            if (now[i] > ans[i])
            {
                flag = true;
                break;
            }
        }
    if (flag)
    {
        for (int i = 1; i <= lenNow; ++i)
            ans[i] = now[i];
        lenAns = lenNow;
    }
}
void readB(int val)
{
    lenB = 0;
    while (val)
    {
        b[++lenB] = val % 10;
        val /= 10;
    }
}
void solve()
{
    int n;
    string str;
    cin >> n >> str;
    for (int i = 1; i <= str.size(); ++i)
        a[i] = str[str.size() - i] - '0';
    lenA = str.size();
    cin >> str;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i].x >> d[i].y;
    }

    sort(d + 1, d + 1 + n, cmp);
    // for (int i = 1; i <= n; ++i)
    //     cout << d[i].x << " " << d[i].y << "\n";
    for (int i = 1; i <= n; ++i)
    {
        div(d[i].y);
        getAns();
        readB(d[i].x);
        mult();
    }
    for (int i = lenAns; i > 0; --i)
        printf("%d", ans[i]);
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