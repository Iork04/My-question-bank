#include <iostream>
using namespace std;

int vis[500][500];
int W, H, n, R;
int ans = 0;

void check(int x, int y)
{
    for (int i = 0; i <= W; ++i)
    {
        for (int j = 0; j <= H; ++j)
        {
            if (((x - i) * (x - i) + (y - j) * (y - j)) <= R * R && !vis[i][j])
            {
                vis[i][j] = 1;
                ans++;
            }
            // cout << vis[i][j];
        }
        // cout << "\n";
    }
}

int main()
{

    cin >> W >> H >> n >> R;
    while (n--)
    {
        int w, h;
        cin >> w >> h;
        check(w, h);
    }

    cout << ans;
    return 0;
}