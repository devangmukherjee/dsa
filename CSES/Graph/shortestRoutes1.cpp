#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    vector < vector<pair<ll, ll>>>graph(n);
    for (ll i = 0; i < m; i++)
    {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        t1--; t2--;
        graph[t1].pb({t2,t3});
    }

    vector<bool>final(n, false);
    vector<ll>dist(n, 9e18);
    dist[0] = 0;
    priority_queue<pair<ll,ll>>q;
    q.push({0,0});
    while(!q.empty())
    {
        ll a=q.top().ss;
        q.pop();
        if(final[a])continue;
        final[a]=true;
        for(auto u:graph[a])
        {
            ll e=u.ff; ll d=u.ss;
            if(dist[a]+d<dist[e])
            {
                dist[e]=dist[a]+d;
                q.push({-dist[e],e});   
            }
 
        }
    }
    for(auto i:dist)
        cout<<i<<" ";
 
}
