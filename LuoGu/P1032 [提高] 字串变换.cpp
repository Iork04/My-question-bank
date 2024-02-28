// https://www.luogu.com.cn/problem/P1032
// BFS、搜索
#include <bits/stdc++.h>
using namespace std;
vector<pair<string, string>> w;
string s, e, str1, str2;
set<string> m;
void bfs()
{
    queue<pair<string, int>> que;
    que.push({s, 0});
    m.insert(s);
    while (!que.empty())
    {
        auto now = que.front();
        que.pop();
        for (int i = 0; i < w.size(); ++i)
        {
            int found = -1;
            while (true)
            {
                found = now.first.find(w[i].first, found+1);
                if (found != -1)
                {
                    string tmp = now.first;
                    tmp.replace(found, w[i].first.size(), w[i].second);
                    // cout << tmp << "\n";
                    if (m.find(tmp) != m.end())
                        continue;
                    if (tmp == e)
                    {
                        cout << now.second + 1;
                        return;
                    }
                    m.insert(tmp);
                    que.push({tmp, now.second + 1});
                }
                else
                    break;
            }
        }
    }
    cout << "NO ANSWER!";
    return;
}

void solve()
{

    cin >> s >> e;
    while (cin >> str1)
    {
        cin >> str2;
        w.push_back({str1, str2});
    }
    bfs();
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