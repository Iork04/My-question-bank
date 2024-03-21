// https://www.lanqiao.cn/problems/2417/learning/?page=1&first_category_id=1&tags=2023
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

bool check(string str)
{
    if (str.size() != 7)
        return 0;
    if (str[0] != 'L' && str[0] != 'l')
        return 0;
    if (str[1] != 'A' && str[1] != 'a')
        return 0;
    if (str[2] != 'N' && str[2] != 'n')
        return 0;
    if (str[3] != 'Q' && str[3] != 'q')
        return 0;
    if (str[4] != 'I' && str[4] != 'i')
        return 0;
    if (str[5] != 'A' && str[5] != 'a')
        return 0;
    if (str[6] != 'O' && str[6] != 'o')
        return 0;
    return 1;
}

void solve()
{
    string str;
    cin >> str;
    if (check(str))
        cout << "yes";
    else
        cout << "no";
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}