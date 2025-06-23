// Problem: Restaurant Customers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1619
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

void fun() {
    ll n;
    cin >> n;
    vpl v(n);

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    vector<pair<ll, int>> events;

    // Generate events: +1 for start, -1 for end
    for (int i = 0; i < n; i++) {
        events.push_back({v[i].first, 1});  // start of interval
        events.push_back({v[i].second + 1, -1});  // end of interval
    }

    // Sort events by time, using second value to prioritize end over start at the same time
    sort(events.begin(), events.end());

    ll ans = 0;
    ll cnt = 0;

    // Sweep line to count overlapping intervals
    for (auto event : events) {
        cnt += event.second;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
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
