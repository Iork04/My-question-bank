#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long i64;

i64 r[N], l[N], v[N];

void _del(int x)
{
    r[l[x]] = r[x], l[r[x]] = l[x];
    v[l[x]] += v[x], v[r[x]] += v[x];
}

void solve()
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    r[0] = 1;
    l[n + 1] = n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        l[i] = i - 1;
        r[i] = i + 1;
        pq.push({v[i], i});
    }

    pair<i64, int> cur;
    while (k--)
    {
        cur = pq.top();
        pq.pop();
        if (cur.first != v[cur.second])
        {
            pq.push({v[cur.second], cur.second});
            k++;
        }
        else
            _del(cur.second);
    }

    i64 head = r[0];
    while (head != n + 1)
    {
        cout << v[head] << " ";
        head = r[head];
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
}