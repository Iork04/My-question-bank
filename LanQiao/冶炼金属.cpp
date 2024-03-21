#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, v, x;
	int _min = INT_MIN, _max = INT_MAX;
	cin >> n;

	while (n--)
	{
		cin >> v >> x;
		_min = max(v / (x + 1) + 1, _min);
		_max = min(v / x, _max);
	}
	cout << _min << " " << _max;
}

int main()
{
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	int _ = 1;
	while (_--)
		solve();

	return 0;
}