// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
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
typedef unordered_map<int, int> uom;
typedef unordered_map<char, int> uocm;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REV(i, a, b) for (int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()

// GCD
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// LCM
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

// Modular Exponentiation
ll mod_exp(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Factorial of a Number;
ll factorial(ll n)
{
    ll result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// Prime Check
bool is_prime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve(vector<string> &v, vector<vector<int>> &vis, int i, int j)
{
    int n = v.size();
    int m = v[0].size();
    vis[i][j] = 1;
    vector<int> dir = {-1, 0, 1, 0, -1};
    for (int k = 0; k < 4; k++)
    {
        int nr = i + dir[k];
        int nc = j + dir[k + 1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && v[nr][nc] == '.')
        {
            solve(v, vis, nr, nc);
        }
    }
    return;
}

void fun()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;

    // for(int i = 0; i < n; i++){
    // if(v[i][0] == '.') solve(v, vis, i, 0);
    // if(v[i][m - 1] == '.') solve(v, vis, i, m - 1);
    // }
    //
    // for(int j = 0; j < m; j++){
    // if(v[0][j] == '.') solve(v, vis, 0, j);
    // if(v[n - 1][j] == '.') solve(v, vis, n - 1, j);
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.' && !vis[i][j])
            {
                ans++;
                solve(v, vis, i, j);
            }
        }
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        fun();
    }
    return 0;
}
