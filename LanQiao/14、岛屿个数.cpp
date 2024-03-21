#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
int n, m;
char group[N][N];
const int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
const int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};

bool fill(int x, int y)
{
	vector<vector<bool>> vis(N, vector<bool>(N, 0));
	queue<pair<int, int>> que;
	que.push({x, y});
	vis[x][y] = 1;
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nextx = cur.first + dx[i];
			int nexty = cur.second + dy[i];
			if (nextx < 1 || nextx > n || nexty < 1 || nexty > m)
				return true;
			if (!vis[nextx][nexty] && group[nextx][nexty] == '0')
			{
				vis[nextx][nexty] = 1;
				que.push({nextx, nexty});
			}
		}
	}
	return false;
}

void bfs(int x, int y)
{
	vector<vector<bool>> vis(N, vector<bool>(N, 0));
	queue<pair<int, int>> que;
	que.push({x, y});
	group[x][y] = '0';
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextx = cur.first + dx[i];
			int nexty = cur.second + dy[i];
			if (group[nextx][nexty] == '1')
			{
				group[nextx][nexty] = '0';
				que.push({nextx, nexty});
			}
		}
	}
}

void solve()
{
	int ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> group[i][j];

	// 只消去一部分,不用bfs的原因是如果两个圆相连的话从中间扫描可能会识别为环内岛
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (group[i][j] == '1' && !fill(i, j))
				group[i][j] = '0';

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (group[i][j] == '1')
			{
				ans++;
				bfs(i, j);
			}

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	int _ = 1;
	cin >> _;
	while (_--)
		solve();

	return 0;
}