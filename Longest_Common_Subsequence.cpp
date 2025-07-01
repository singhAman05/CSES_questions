// Problem: Longest Common Subsequence
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3403
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
int dp[1001][1001];

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

int solve(const vi &v1, const vi &v2, int i, int j){
	if(i >= v1.size() || j >= v2.size()) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	if(v1[i] == v2[j])
		return dp[i][j] = 1 + solve(v1, v2, i+1, j+1);
	else
		return dp[i][j] = max(solve(v1, v2, i+1, j), solve(v1, v2, i, j+1));
}

vi buildLCS(const vi &v1, const vi &v2) {
    int i = 0, j = 0;
    vi res;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] == v2[j]) {
            res.push_back(v1[i]);
            i++;
            j++;
        } else if (dp[i + 1][j] >= dp[i][j + 1]) {
            i++;
        } else {
            j++;
        }
    }

    return res;
}

void fun() {
    int n, m;
    cin >> n >> m;
    vi v1(n), v2(m);
    REP(i, 0, n) cin >> v1[i];
    REP(i, 0, m) cin >> v2[i];
    
    memset(dp, -1, sizeof(dp));
    solve(v1, v2, 0, 0);

    vi y = buildLCS(v1, v2);

    cout << y.size() << endl;
    for (int val : y)
        cout << val << " ";
    cout << endl;
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
