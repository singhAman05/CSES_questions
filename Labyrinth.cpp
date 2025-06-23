// Problem: Labyrinth
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1193
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

void solve(vector<vector<char>> &grid, vector<vector<int>> &vis, int n, int m, int startX, int startY, int endX, int endY) {
    queue<pii> q;
    q.push({startX, startY});
    vis[startX][startY] = 1;

    vector<int> dirX = {-1, 1, 0, 0}; // U, D, L, R
    vector<int> dirY = {0, 0, -1, 1};
    vector<char> moveDir = {'U', 'D', 'L', 'R'};

    vector<vector<pii>> parent(n, vector<pii>(m, {-1, -1}));
    vector<vector<char>> move(n, vector<char>(m, '.'));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == endX && y == endY) {
            // Found the end
            cout << "YES\n";
            string path = "";
            while (!(x == startX && y == startY)) {
                path += move[x][y];
                int px = parent[x][y].first;
                int py = parent[x][y].second;
                x = px;
                y = py;
            }
            reverse(path.begin(), path.end());
            cout << path.length() << '\n';
            cout << path << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY] && grid[newX][newY] != '#') {
                vis[newX][newY] = 1;
                q.push({newX, newY});
                parent[newX][newY] = {x, y};
                move[newX][newY] = moveDir[i];
            }
        }
    }

    // If no path is found
    cout << "NO\n";
}

void fun(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int startX, startY, endX, endY;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
            if (grid[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }

    solve(grid, vis, n, m, startX, startY, endX, endY);
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
