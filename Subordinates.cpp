#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;  // adjacency list for the tree
vector<int> subordinates;  // to store the number of subordinates for each employee

// Function to perform DFS and count subordinates
int dfs(int node) {
    int count = 0;  // start with 0 subordinates
    for (int child : tree[node]) {
        count += 1 + dfs(child);  // add the subordinates of the child
    }
    subordinates[node] = count;
    return count;
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    subordinates.resize(n + 1, 0);

    // Input the direct boss of each employee 2 to n
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);  // boss points to the subordinate
    }

    // Start DFS from employee 1 (general director)
    dfs(1);

    // Output the number of subordinates for each employee
    for (int i = 1; i <= n; i++) {
        cout << subordinates[i] << " ";
    }
    cout << endl;

    return 0;
}
