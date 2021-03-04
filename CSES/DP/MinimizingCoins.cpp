#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
ll mod = pow(10, 9) + 7;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int>v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    vector<int>dp(x + 1, 1e9);
    dp[0] = 0;


    for (int i = 1; i <=x ;i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i-v[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[i - v[j]]);

        }
    }
    cout <<(dp[x]==1e9?-1:dp[x]);

}
