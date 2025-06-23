#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MX = 200005; // Ensure this is large enough for the problem constraints
const ll INF = 1e18;  // Infinity constant for comparison

// Adjacency list
vector<ll> Adj[MX];
// Dynamic programming array
ll dp[2][MX];

// Depth-first search to compute the maximum number of pairs
// u: current node
// p: parent node
void DFS(ll u, ll p) {
    // Initialize dp values
    // dp[0][u] is the maximum number of pairs without including the current node
    dp[0][u] = 0;
    // dp[1][u] is the maximum number of pairs including the current node
    dp[1][u] = -INF;

    // Traverse through each adjacent node
    for (ll v : Adj[u]) {
        if (v == p)
            continue;  // Skip if it's the parent node

        // Recursively call DFS for child node
        DFS(v, u);

        // Update dp[0] for the current node by taking the max of dp[1][v] and dp[0][v]
        dp[0][u] += max(dp[1][v], dp[0][v]);

        // Calculate the difference between including and excluding the child
        ll opt = min(dp[0][v] - dp[1][v], 0LL);
        
        // Update dp[1][u] for maximum pairs including the current node
        dp[1][u] = max(dp[1][u], opt);
    }

    // Update dp[1][u] value, adding the result from dp[0][u] and including the current node
    dp[1][u] += dp[0][u];
    dp[1][u]++;
}

void fun() {
    ll n;
    cin >> n;

    // Reset adjacency list and dp arrays
    for (ll i = 0; i < n; i++) {
        Adj[i].clear();
    }

    // Read edges for the tree
    for (ll i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;  // Assuming 1-based input, convert to 0-based
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    // Perform DFS from node 0 (assuming 0-based indexing)
    DFS(0, -1);

    // Calculate the result
    ll ans = max(dp[0][0], dp[1][0]);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t; // Uncomment for multiple test cases
    while (t--) {
        fun();
    }

    return 0;
}
