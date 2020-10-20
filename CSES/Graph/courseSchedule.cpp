#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

//topological sort

vector<vector<ll>>adj;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m ;
    adj.resize(n);
    vector<ll>indeg(n, 0);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        indeg[b]++;
    }
    queue<ll>process;
    vector<ll>ans;
    for (ll i = 0; i < indeg.size(); i++)
    {
        if (indeg[i] == 0)
        {
            process.push(i);
        }
    }

    while (!process.empty())
    {
        ll curr = process.front();
        ans.pb(curr);
        process.pop();
        for (auto k : adj[curr])
        {
            indeg[k]--;
            if (indeg[k] == 0)
                process.push(k);
        }

    }
    if (ans.size() != n)
        cout << "IMPOSSIBLE";
    else
    {
        for (auto i : ans)
            cout << i + 1 << ' ';
    }
}
