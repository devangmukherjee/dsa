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

int fd(int i) {
    int index=0;
    while (i)
    {
        index=max(index,(i%10));
        i /= 10;
    }

    return index;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int index;
        index = fd(i);
        dp[i]=1+dp[i-index];
    }
    cout<<dp[n];
    return 0;

}
