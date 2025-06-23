// Problem: D. Skibidi Table
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/contest/2093/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ull> p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) 
        p[i] = p[i - 1] << 1;

    while (m--) {
        string o;
        cin >> o;
        if (o == "->") {
            ull r, c;
            cin >> r >> c;
            --r; --c;
            ull d = 0;
            for (int i = n; i >= 1; --i) {
                ull l = p[i - 1];
                ull b = l * l;
                int t;
                if (r < l && c < l) {
                    t = 0;
                }
                else if (r >= l && c >= l) {
                    t = 1;
                    r -= l; c -= l;
                }
                else if (r >= l && c < l) {
                    t = 2;            // BL
                    r -= l;
                }
                else {
                    t = 3;
                    c -= l;
                }
                d += (ull)t * b;
            }
            cout << (d + 1) << "\n";
        }
        else {
            ull v;
            cin >> v;
            ull d = v - 1;
            ull r = 0, c = 0;
            for (int i = n; i >= 1; --i) {
                ull l = p[i - 1];
                ull b = l * l;
                int t = d / b;
                d %= b;
                if (t == 1) { r += l; c += l; }
                else if (t == 2) { r += l; }
                else if (t == 3) { c += l; }
            }
            cout << (r + 1) << " " << (c + 1) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) 
        solve();

    return 0;
}
