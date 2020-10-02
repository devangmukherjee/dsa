#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second

void dfs(int j, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[j] = true;
    for (auto k : adj[j])
    {
        if (!vis[k])
        {
            dfs(k, adj, vis);
        }
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int city, road;
    cin >> city >> road;
    vector<bool>vis(city, 0);
    vector<vector<int>>adj(city);
    for (int i = 0; i < road; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        temp1--; temp2--;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    int count = 0;
    vector<int>cities;


    for (int i = 0; i < vis.size(); i++)
    {
        if (!vis[i])
        {
            cities.push_back(i);
            dfs(i, adj, vis);
        }
    }

    cout << cities.size() - 1 << endl;
    for (int i = 1; i < cities.size() ; i++)
    {
        cout << cities[0] + 1 << " " << cities[i] + 1 << endl;
    }
}
