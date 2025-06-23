// Problem: Money Sums
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1745
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

int dp[102][100001];

void solve(vl &v, int i, int sum, unordered_set<int> &st) {
    if (i == v.size()) {
        st.insert(sum);
        return;
    }
    if(dp[i][sum]!=-1) return;
    
    dp[i][sum] = 1;
    // Recursively call without including current element
    solve(v, i + 1, sum, st);
    
    // Recursively call including current element
    solve(v, i + 1, sum + v[i], st);
}

void fun() {
    ll n;
    cin >> n; // Input size of vector
    vl v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // Input elements of vector
    }
    
    memset(dp,-1,sizeof(dp));
    
    unordered_set<int> st; // To store unique sums
    solve(v, 0, 0, st);
    
    vl ans(st.begin(), st.end()); // Convert unordered_set to vector
    sort(ans.begin(), ans.end()); // Sort the sums
    cout<<ans.size()-1<<endl;
    // Output all sums except the first (which is zero)
    for (int i = 1; i < ans.size(); i++) { 
        cout << ans[i] << " ";
    }
    cout << endl; // Print a new line at the end
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;  // Uncomment if multiple test cases are needed
    while (t--) {
        fun();
    }
    
    return 0;
}