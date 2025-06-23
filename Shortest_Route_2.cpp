// Problem: Shortest Routes II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1672
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

void floydWarshall(vector<vector<ll>> &dis, int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dis[i][k] < INF && dis[k][j] < INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

void fun() {
    int n, m, q;
    cin >> n >> m >> q;
    
    // Initialize distance matrix
    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, INF));
    
    // Distance from a node to itself is 0
    for (int i = 1; i <= n; ++i) {
        dis[i][i] = 0;
    }
    
    // Input the edges
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);  // In case of multiple edges, take the smallest
        dis[b][a] = min(dis[b][a], c);  // Since roads are two-way, do the same for the reverse direction
    }
    
    // Apply Floyd-Warshall to compute all pairs shortest paths
    floydWarshall(dis, n);
    
    // Answer the queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dis[a][b] == INF)
            cout << -1 << endl;
        else
            cout << dis[a][b] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fun();
    return 0;
}