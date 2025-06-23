// Problem: String Matching
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1753
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
bool solve(string &s, string &p, int i){
	int j = 0;
	int n = s.size();
	int m = p.size();
	while(i<n && j<m){
		if(s[i]!=p[j]) return 0;
		i++;j++;
	}
	return j==p.size();
}
// Function to calculate Z-array
vector<int> calculateZ(string s) {
    int n = s.size();
    vector<int> Z(n);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

void fun() {
    string s, p;
    cin >> s >> p;
    
    // Concatenate pattern, special character, and the string
    string combined = p + '#' + s;
    vector<int> Z = calculateZ(combined);
    
    int patternLength = p.size();
    int count = 0;
    
    // Traverse the Z array to count occurrences of pattern in the string
    for (int i = patternLength + 1; i < Z.size(); i++) {
        if (Z[i] == patternLength) {
            count++;
        }
    }
    
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fun();
    return 0;
}
