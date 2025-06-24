// Problem: Array Description
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1746
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
#define nl "\n"

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


int n, m;
vi ar;
vector<vector<int>> dp;

int solve(int i, int prev) {
    if (i == n) return 1;

    if (dp[i][prev] != -1) return dp[i][prev];

    int res = 0;

    if (ar[i] != 0) {
        if (abs(ar[i] - prev) > 1) return 0;
        res = solve(i + 1, ar[i]);
    } else {
        for (int val = max(1, prev - 1); val <= min(m, prev + 1); val++) {
            res = (res + solve(i + 1, val)) % MOD;
        }
    }

    return dp[i][prev] = res;
}

void fun() {
    cin >> n >> m;
    ar.resize(n);
    for (int i = 0; i < n; i++) cin >> ar[i];

    dp.assign(n, vector<int>(m + 2, -1));

    int ans = 0;

    if (ar[0] != 0) {
        ans = solve(1, ar[0]);
    } else {
        for (int val = 1; val <= m; val++) {
            ans = (ans + solve(1, val)) % MOD;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fun();
    return 0;
}
