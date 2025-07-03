// Problem: Line Segment Intersection
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2190
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

bool onSegment(ll x1, ll y1, ll x2, ll y2, ll x, ll y) {
    return x >= min(x1, x2) && x <= max(x1, x2) &&
           y >= min(y1, y2) && y <= max(y1, y2);
}

void fun() {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    ll a1 = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    ll a2 = (x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1);
    ll a3 = (x4 - x3) * (y1 - y3) - (x1 - x3) * (y4 - y3);
    ll a4 = (x4 - x3) * (y2 - y3) - (x2 - x3) * (y4 - y3);

    if ((a1 > 0 && a2 < 0 || a1 < 0 && a2 > 0) &&
        (a3 > 0 && a4 < 0 || a3 < 0 && a4 > 0)) {
        cout << "YES\n";
        return;
    }

    if (a1 == 0 && onSegment(x1, y1, x2, y2, x3, y3)) { cout << "YES\n"; return; }
    if (a2 == 0 && onSegment(x1, y1, x2, y2, x4, y4)) { cout << "YES\n"; return; }
    if (a3 == 0 && onSegment(x3, y3, x4, y4, x1, y1)) { cout << "YES\n"; return; }
    if (a4 == 0 && onSegment(x3, y3, x4, y4, x2, y2)) { cout << "YES\n"; return; }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        fun();
    }
    return 0;
}
