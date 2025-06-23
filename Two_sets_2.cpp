// Problem: Two Sets II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1093
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

ll dp[501][125251];

ll solve(ll n, ll sum, int i, ll cur) {
    if (cur == sum) return 1;
    if (i > n) return 0;
    if (dp[i][cur] != -1) return dp[i][cur];
    
    // Calculate number of ways including or excluding the current number
    ll include = solve(n, sum, i + 1, cur + i) % MOD;
    ll exclude = solve(n, sum, i + 1, cur) % MOD;
    
    return dp[i][cur] = (include + exclude) % MOD;
}

void fun() {
    ll n; cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "0\n";
        return;
    }
    sum /= 2;
    memset(dp, -1, sizeof(dp));
    // Each partition is counted twice, so divide by 2
    cout << (solve(n, sum, 1, 0) * 500000004) % MOD << "\n"; // 500000004 is the modular inverse of 2 under MOD
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases are used
    while (t--) {
        fun();
    }
    
    return 0;
}
