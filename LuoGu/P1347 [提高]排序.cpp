// https://www.luogu.com.cn/problem/P1347
// 图论、拓扑
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2500;
int m, n, flag, cas, ans[30], loca;
vector<int> edge[30], in(30), ok(30);

void bfs()
{
    flag = 1;
    cas = 0;
    queue<int> q;
    int t = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!ok[i])
        {
            ++t;
            q.push(i);
        }
    }
    if (t > 1)
        flag = 0;
    while (!q.empty())
    {
        t = 0;
        int cur = q.front();
        ans[++cas] = cur;
        q.pop();
        for (int &val : edge[cur])
        {
            if (!--ok[val])
            {
                ++t;
                q.push(val);
            }
        }
        if (t > 1)
            flag = 0;
    }
    for (int i = 0; i < n; ++i)
        if (ok[i])
        {
            flag = -1;
            break;
        }
    return;
}

string getStr()
{
    string res = "";
    for (int i = 1; i <= n; ++i)
        res += (char)(ans[i]+'A');
    return res + '.';
}

void solve()
{
    while (cin >> n >> m)
    {
        flag = 0;
        in.assign(30, 0);
        for (auto &e : edge)
            e.clear();
        for (int i = 1; i <= m; ++i)
        {
            char a, b, c;
            cin >> a >> b >> c;
            if (b == '<')
            {
                edge[a - 'A'].push_back(c - 'A');
                ++in[c - 'A'];
            }
            else
            {
                edge[c - 'A'].push_back(a - 'A');
                ++in[a - 'A'];
            }
            if (!flag)
            {
                for (int i = 0; i < n; ++i)
                    ok[i] = in[i];
                bfs();
                loca = i;
            }
        }
        if (flag == 0)
            cout << "Sorted sequence cannot be determined.";
        else if (flag == 1)
            cout << "Sorted sequence determined after " << loca << " relations: " << getStr() << "\n";
        else
            cout << "Inconsistency found after " << loca << " relations.\n ";
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("./in.in", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}