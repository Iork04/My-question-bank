// https://www.luogu.com.cn/problem/P1827
// 模拟、递归
#include <bits/stdc++.h>
using namespace std;

void func(string &pre, string &inor)
{
    // cout << pre << " " << inor << "\n";
    if (pre.empty())
        return;
    char root = pre[0];
    int index = inor.find(root);
    string leftPre = pre.substr(1, index);
    string leftInor = inor.substr(0, index);
    string rightPre = pre.substr(index + 1);
    string rightInor = inor.substr(index + 1);
    func(leftPre, leftInor);
    func(rightPre, rightInor);
    cout << root;
}

void solve()
{
    string pre, inor;
    cin >> inor >> pre;
    func(pre, inor);
}
int main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}