#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
vector<int>ans;
map<int, int>parmap;


//detect cycle
void cycle(int j, int parent, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[j] = true;
    parmap[j] = parent;
    for (auto i : adj[j])
    {
        //if parent node continue to next
        if (i == parent)
            continue;
        //cycle detected -> backtrack
        if (vis[i] and i != parent)
        {
            int src=j;
            while (i ^ j)
            {
                ans.pb(j);
                j = parmap[j];
            }
            ans.pb(i);
            ans.pb(src);
            cout << ans.size() << endl;
            for (auto k : ans)
            {
                cout << k + 1 << ' ';
            }
            exit(0);
        }
        //dfs
        if (!vis[i])
        {
            cycle(i, j, adj, vis);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n);
    vector<bool>vis(n, false);
    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        t1--; t2--;
        adj[t1].pb(t2);
        adj[t2].pb(t1);
    }

    for (int i = 0; i < vis.size(); i++)
    {
        if (!vis[i])
            cycle(i, -1, adj, vis);

    }

    cout << "IMPOSSIBLE";

}

