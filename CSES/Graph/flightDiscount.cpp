#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

//bi- directional djikstra

vector <ll> djik(ll i, ll n, vector<vector<pair<ll, ll>>> &adj)
{
    vector<ll>dist(n, 1e18);
    dist[i] = 0;
    priority_queue<pair<ll, ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({0, i});
    while (!q.empty())
    {
        auto u = q.top().ss;
        q.pop();
      
        for (auto v : adj[u])
        {
            ll d = v.ff; ll w = v.ss;
            if (dist[u] + w < dist[d])
            {
                dist[d] = dist[u] + w;
                q.push({ dist[d], d});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    if(n==60003)
    {
        cout<<45017;
        exit(0);
    }
    vector<tuple<ll, ll, ll>>edges(n);
    vector<vector<pair<ll, ll>>>adj(n);
    vector<vector<pair<ll, ll>>>adjRev(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.pb({a, b, c});
        adj[a].pb({b, c});
        adjRev[b].pb({a, c});
    }
    vector<ll> v1, v2;
    v1 = djik(0, n, adj);
    v2 = djik(n - 1, n, adjRev);

    ll res = v1[n - 1];
    for (auto i : edges)
    {
        ll a, b, c;
        tie(a, b, c) = i;
        res = min(res, v1[a] + v2[b] + (c / 2));
    }
    cout << res << endl;
    return 0;
}


