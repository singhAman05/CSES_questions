#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int base = 31;
const int mod = 1e9 + 7;

void fun() {
    string s;
    cin >> s;
    int n = s.size();

    vector<ll> pow_base(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pow_base[i] = (pow_base[i - 1] * base) % mod;
    }

    ll hash_prefix = 0, hash_suffix = 0;
    for (int i = 0; i < n - 1; i++) {
        hash_prefix = (hash_prefix * base + (s[i] - 'a' + 1)) % mod;
        hash_suffix = (hash_suffix + (s[n - 1 - i] - 'a' + 1) * pow_base[i]) % mod;

        if (hash_prefix == hash_suffix) {
            cout << i + 1 << " ";
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
