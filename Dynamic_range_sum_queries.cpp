// Problem: Dynamic Range Sum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1648
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

void buildSeg(vl &v, vl &seg, ll l, ll r, int i){
	if(l==r){
		seg[i] = v[l];
	}
	else{
		ll mid = l+(r-l)/2;
		buildSeg(v,seg,l,mid,2*i+1);
		buildSeg(v,seg,mid+1,r,2*i+2);
		
		seg[i] = seg[2*i+1]+seg[2*i+2];
	}
}

void updateQ(vl &seg, ll l, ll r, ll k, ll u, ll i){
	if(l==r){
		seg[i] = u;
	}
	else{
		ll mid = l+(r-l)/2;
		if(k<=mid){
			updateQ(seg,l,mid,k,u,2*i+1);
		}
		else{
			updateQ(seg,mid+1,r,k,u,2*i+2);
		}
		
		seg[i] = seg[2*i+1] + seg[2*i+2];
	}
}

ll rangeQ(vl &seg, ll l, ll r, ll a, ll b, ll i){
	if(b<l ||a>r) return 0;
	if(a<=l && r<=b) return seg[i];
	
	ll mid = l+(r-l)/2;
	
	ll lf = rangeQ(seg,l,mid,a,b,2*i+1);
	ll rf = rangeQ(seg,mid+1,r,a,b,2*i+2);
	
	return lf+rf;
}

void fun(){
    // your code
    ll n,q;cin>>n>>q;
    vl v(n);
    FOR(i,0,n-1) cin>>v[i];
     vl seg(4*n,0);
     buildSeg(v,seg,0,n-1,0);
     
     while(q--){
     	int ty;cin>>ty;
     	if(ty==1){
     		ll k,u;
     		cin>>k>>u;
     		
     		k--;
     		updateQ(seg,0,n-1,k,u,0);
     	}
     	else{
     		ll a,b;cin>>a>>b;
     		a--;b--;
     		cout<<rangeQ(seg,0,n-1,a,b,0)<<endl;
     	}
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
