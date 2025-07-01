// Problem: Edit Distance
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1639
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
int dp[5001][5001];

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

int solve(string &s1, string &s2, int i, int j) {
    if (i == s1.size() && j == s2.size()) return 0;
    if (i == s1.size()) return s2.size() - j;
    if (j == s2.size()) return s1.size() - i;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < s1.size(); ++k) {
        if (s1[k] == s2[j]) {
            ans = min(ans, (k - i) + solve(s1, s2, k + 1, j + 1));
            break;
        } else {
            ans = min(ans, 1 + solve(s1, s2, i + 1, j));
            ans = min(ans, 1 + solve(s1, s2, i, j + 1));
            ans = min(ans, 1 + solve(s1, s2, i + 1, j + 1));
            break;
        }
    }
    return dp[i][j] = ans;
}


void fun(){
    // your code
    string s1,s2;cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    cout<<solve(s1,s2,0,0);
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
