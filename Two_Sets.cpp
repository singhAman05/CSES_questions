// Problem: Two Sets
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1092
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

// Prime Check
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void fun() {
    int n;
    cin >> n;
    
    ll sum = n * (n + 1) / 2;
    
    // If the sum is odd, it's not possible to divide into two sets with equal sums
    if (sum & 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vi v1,v2;
        if(n%2){
        	v1.push_back(n--);
        	for(int i=1;i<=n/2;i+=2){
        		v2.push_back(i);
        		v2.push_back(n-i+1);
        	}
        	for(int i=2;i<n/2;i+=2){
        		v1.push_back(i);
        		v1.push_back(n-i+1);
        	}
        }
        else{
        	for(int i=1;i<n/2;i+=2){
        		v1.push_back(i);
        		v1.push_back(n-i+1);
        	}
        	for(int i=2;i<=n/2;i+=2){
        		v2.push_back(i);
        		v2.push_back(n-i+1);
        	}
        }
        
        cout<<v1.size()<<endl;
        for(auto it : v1) cout<<it<<" ";
        cout<<"\n"<<v2.size()<<"\n";
        for(auto it : v2) cout<<it<<" ";
    }
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
