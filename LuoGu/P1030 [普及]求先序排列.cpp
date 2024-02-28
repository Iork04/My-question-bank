// https://www.luogu.com.cn/problem/P1030
// 模拟、递归
#include <bits/stdc++.h>
using namespace std;

void func(string &inor, string &aft)
{
    if (aft.empty())
        return;
    // cout << inor << " " << aft << "\n";
    char root = aft[aft.size() - 1];
    cout << root;
    int index = inor.find(root);
    string leftInor = inor.substr(0, index);
    string leftAft = aft.substr(0, index);
    string rightInor = inor.substr(index + 1);
    string rightAft = aft.substr(index, aft.size() - index - 1);
    func(leftInor, leftAft);
    func(rightInor, rightAft);
}

void solve()
{
    string aft, inor;
    cin >> inor >> aft;
    func(inor, aft);
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