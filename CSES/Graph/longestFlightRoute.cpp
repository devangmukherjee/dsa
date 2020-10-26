#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
vector<ll>dist;
vector<ll>parents;
void djik(vector<vector<pair<ll, ll>>> &adj)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;
    dist[0] = 0;
    q.push({0, 0});
    while (!q.empty())
    {
        int a = q.top().ss;
        int b = q.top().ff;
        q.pop();
        if (dist[a] < b)continue;
        for (auto u : adj[a])
        {
            int f, s;
            f = u.ff; s = u.ss;
            if (dist[f] > dist[a] + s)
            {
                dist[f] = dist[a] + s;
                q.push({dist[f], f});
                parents[f] = a;
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);
    dist.resize(n, 0);
    parents.resize(n, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back({b, -1});
    }
    djik(adj);
    if (dist[n-1] == 0)
        cout << "IMPOSSIBLE";
    else
    {

        cout << (1 + dist[n-1]*(-1)) << endl;
        vector<ll>ans;
        ll temp=n-1;
        while (temp != -1)
        {
            ans.pb(temp);
            temp=parents[temp];
        }
        reverse(ans.begin(),ans.end());
        for(auto i:ans)
            cout<<i+1<<' ';
    }
}
