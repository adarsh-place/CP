#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
int depth[N];

void dfs(int v, int parent = -1)
{
    for (int child : g[v])
    {
        if (child == parent)
            continue;
        depth[child] = depth[v] + 1;
        dfs(child, v);
    }
}

int main()
{
    int v;
    cin >> v;

    for (int i = 0; i < v - 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);

    int mx_depth = -1;
    int mx_d_vertex;
    for (int i = 1; i <= v; i++)
    {
        if (mx_depth < depth[i])
        {
            mx_depth = depth[i];
            mx_d_vertex = i;
        }
        depth[i] = 0;
    }

    dfs(mx_d_vertex);

    mx_depth = -1;
    for (int i = 1; i <= v; i++)
    {
        if (mx_depth < depth[i])
        {
            mx_depth = depth[i];
        }
    }

    cout << mx_depth;

    return 0;
}