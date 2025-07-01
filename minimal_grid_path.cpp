// Problem: Minimal Grid Path
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3359
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

int n;
vector<vector<char>> v;
vector<vector<string>> memo;


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

string solve(int i, int j){
    if(i>=n || j>=n) return string(1, char('Z'+1));
    if(!memo[i][j].empty()) return memo[i][j];
    if(i==n-1 && j==n-1)
        return memo[i][j] = string(1, v[i][j]);
    string down = solve(i+1, j);
    string right = solve(i, j+1);
    string withDown = v[i][j] + down;
    string withRight = v[i][j] + right;
    return memo[i][j] = (withDown < withRight ? withDown : withRight);
}

void fun(){
    cin>>n;
    v.assign(n, vector<char>(n));
    REP(i,0,n) REP(j,0,n) cin>>v[i][j];
    memo.assign(n, vector<string>(n, ""));
    cout<<solve(0,0)<<"\n";
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
