#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

//FLOYD WARSHALL ALGORITHM

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>>dist(n, vector<ll>(n, 1e18));
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[a][b],c);
    }
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--)
    {
        ll i,j;
        cin>>i>>j;
        i--;j--;
        ll ans=dist[i][j];
        if(ans==1e18)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }

    return 0;
}
