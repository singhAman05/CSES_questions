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

void generateSequences(unordered_set<string> &allSequences) {
    string chars = "ACGT";

    // Generate sequences of length 1
    for (char c : chars) {
        string seq(1, c);
        allSequences.insert(seq);
    }

    // Generate sequences of length 2
    for (char c1 : chars) {
        for (char c2 : chars) {
            string seq = string(1, c1) + c2;
            allSequences.insert(seq);
        }
    }

    // Generate sequences of length 3
    for (char c1 : chars) {
        for (char c2 : chars) {
            for (char c3 : chars) {
                string seq = string(1, c1) + c2 + c3;
                allSequences.insert(seq);
            }
        }
    }
}

void fun() {
    string dna;
    cin >> dna;
    unordered_set<string> subsequences;

    // Generate all subsequences of length 1 to 3 from the given DNA string
    for (int i = 0; i < dna.size(); ++i) {
        for (int len = 1; len <= 3 && i + len <= dna.size(); ++len) {
            subsequences.insert(dna.substr(i, len));
        }
    }

    // Generate all possible DNA sequences of length 1 to 3
    unordered_set<string> allSequences;
    generateSequences(allSequences);

    // Find the shortest sequence that is not a subsequence of the given DNA
    for (const string &seq : allSequences) {
        if (subsequences.find(seq) == subsequences.end()) {
            cout << seq << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // Uncomment this if there are multiple test cases.
    // cin >> t;
    
    while (t--) {
        fun();
    }

    return 0;
}
