#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

//bellman ford and backtracking


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
    vector<tuple<ll, ll, ll>>edges(n);
    vector<ll>parent(n, -1);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.pb({a, b, c});
    }
    vector<ll>dist(n, 1e18);
    ll x;
    for (ll count = 0; count < n ; count++)
    {
        x = -1;
        for (auto i : edges)
        {
            ll a, b, c;
            tie(a, b, c) = i;
            if (dist[b] > dist[a] + c)
            {
                dist[b] = dist[a] + c;
                parent[b] = a;
                x = b;
            }
        }
    }

    ll last;
    if (x == -1)
    {
        cout << "NO";
    }
    else {
        //to enter back in the cycle
        for (int i = 0; i < n; i++)
            x = parent[x];

        vector<ll> ans;
        ll v = x;
        for (ll v = x; ; v = parent[v])
        {
            ans.pb(v);
            if (v == x and ans.size() > 1)
                break;
        }
        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        for (auto i : ans)
            cout << i+1 << ' ';
    }
    return 0;
}


