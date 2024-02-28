#include <bits/stdc++.h>
using namespace std;

class Union
{
public:
    Union(int n)
    {
        rank.assign(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        // Path compression while searching.
        // Can achieve a time complexity close to O(1).
        // This operation will disrupt the tree structure.
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unionSets(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB)
        {
            // Merge by rank,merging smaller tress into larger ones.
            if (rank[rootA] > rank[rootB])
                swap(rootA, rootB);
            parent[rootA] = rootB;
            if (rank[rootA] == rank[rootB])
                ++rank[rootB];

            // Direct merging is also possible.
            // parent[rootA] = parent[rootB];
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

void solve()
{
    Union uf(100);

    uf.unionSets(1, 2);
    uf.unionSets(2, 3);
    uf.unionSets(3, 4);
    uf.unionSets(5, 6);
    uf.unionSets(6, 7);
    uf.unionSets(5, 7);
    uf.unionSets(5, 9);

    std::cout << "Find(1): " << uf.find(9) << std::endl;
    std::cout << "Find(3): " << uf.find(6) << std::endl;
    std::cout << "Find(6): " << uf.find(5) << std::endl;
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