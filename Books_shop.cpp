// Problem: Book Shop
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1158
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef map<int, int> mpi;
typedef set<int> seti;
typedef unordered_map<int,int> uom;
typedef unordered_map<char,int> uocm;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REV(i, a, b) for (int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()

// GCD
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// LCM
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// Modular Exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Factorial of a Number;
ll factorial(ll n) {
    ll result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Prime Check
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


// vector<vector<ll>> dp;

// int solve(const vector<int> &v1, const vector<int> &v2, int i, int x) {
    // if (x == 0 || i < 0) return 0;
    // if (x < 0) return -1e6;
// 
    // if (dp[i][x] != -1) return dp[i][x];
// 
    // ll tk = -1e6;
    // if (v1[i] <= x) {
        // tk = v2[i] + solve(v1, v2, i - 1, x - v1[i]);
    // }
    // ll ntk = solve(v1, v2, i - 1, x);
// 
    // dp[i][x] = max(ntk, tk);
    // return dp[i][x];
// }

void fun() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v1(n), v2(n);
    for (int i = 0; i < n; ++i) cin >> v1[i];
    for (int i = 0; i < n; ++i) cin >> v2[i];
    vector<ll> dp(x+1,0);
    
    for(int i=0;i<n;i++){
    	for(int j = x;j>0;j--){
    		if(v1[i]>j) continue;
    		dp[j] = max(dp[j],v2[i] + dp[j-v1[i]]);
    	}
    }
    
    cout<<dp[x];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin >> t;
    while (t--) {
        fun();
    }
    return 0;
}
