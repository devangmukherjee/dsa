#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
const int mod = 1e9 + 7;
const int mx = 100;
int dp[1000001];
int v[mx + 1];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    // vector<int>v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    // vector<int>dp(x + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i <= x ; i++)
        {
            if (i >=  v[j])
                dp[i] = (dp[i] + dp[i - v[j]]) % mod;

        }
    }

  
    
    cout << dp[x] % mod;
    return 0;

}
