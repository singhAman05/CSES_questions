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

void fun() {
    int n, l;
    cin >> n >> l;
    vi a(n);
    REP(i, 0, n) cin >> a[i];

    sort(all(a));

    // Find the maximum gap to determine the minimum radius `d`
    int max_gap = 2 * max(a[0], l - a[n - 1]);
    REP(i, 0, n - 1) {
        max_gap = max(max_gap, a[i + 1] - a[i]);
    }

    // Print result with 10 decimal precision
    cout << fixed << setprecision(10) << max_gap / 2.0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        fun();
    }
    return 0;
}
