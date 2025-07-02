#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> v(n);
    ll S = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        S += v[i];
    }

    // dp[r] will hold D_{l,r} for the current l as we sweep l from n-1 down to 0
    vector<ll> dp(n);

    // base case: when l == r, D_{l,l} = v[l]
    for(int i = 0; i < n; i++){
        dp[i] = v[i];
    }

    // fill for l = n-2 down to 0:
    for(int l = n - 2; l >= 0; l--){
        // for each r = l+1 .. n-1
        // we need the old dp[r] = D_{l+1,r] and dp[r-1] = D_{l, r-1]
        for(int r = l + 1; r < n; r++){
            ll takeLeft  = v[l] - dp[r];     // v[l] - D_{l+1,r}
            ll takeRight = v[r] - dp[r-1];   // v[r] - D_{l, r-1]
            dp[r] = max(takeLeft, takeRight);
        }
    }

    ll delta = dp[n-1];                  // = D_{0,n-1}
    ll firstScore = (S + delta) / 2;     // integer division is safe because S+Δ is even
    cout << firstScore << "\n";
    return 0;
}
