// Problem: D. Counting Points
// Contest: Codeforces - Codeforces Round 1009 (Div. 3)
// URL: https://codeforces.com/contest/2074/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

#define FOR(i, num1, num2) for (int i = num1; i <= num2; i++)
#define REP(i, num1, num2) for (int i = num1; i < num2; i++)
#define REV(i, num1, num2) for (int i = num1; i >= num2; i--)
#define all(v) v.begin(), v.end()

// GCD
ll gcd(ll num1, ll num2) {
    return num2 == 0 ? num1 : gcd(num2, num1 % num2);
}

// LCM
ll lcm(ll num1, ll num2) {
    return (num1 / gcd(num1, num2)) * num2;
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

// Factorial of num1 Number;
ll factorial(ll n) {
    ll result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}


long long count_points(vector<int>& vec1, vector<int>& vec2, int n) {
    unordered_map<int, int> maxi_y;

    for (int i = 0; i < n; ++i) {
        int cx = vec1[i];
        int radius = vec2[i];
        int num1 = cx - radius;
        int num2 = cx + radius;
        for (int x_ind = num1; x_ind <= num2; ++x_ind) {
            int dx = x_ind - cx;
            int dx_sq = dx * dx;
            if (dx_sq > radius * radius) continue; // Shouldn't happen as x_ind is within [num1, num2]
            int y_max = static_cast<int>(sqrt(radius * radius - dx_sq));
            auto it = maxi_y.find(x_ind);
            if (it == maxi_y.end() || y_max > it->second) {
                maxi_y[x_ind] = y_max;
            }
        }
    }

    long long total = 0;
    for (const auto& entry : maxi_y) {
        total += 2 * entry.second + 1;
    }
    return total;
}

// Prime Check
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void fun(){
    // your code
    int n, m;
        cin >> n >> m;
        vector<int> vec1(n), vec2(n);
        for (int i = 0; i < n; ++i) cin >> vec1[i];
        for (int i = 0; i < n; ++i) cin >> vec2[i];

        cout << count_points(vec1, vec2, n) << "\n";
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

