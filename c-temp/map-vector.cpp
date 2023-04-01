#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, vector<int>> M;
    int n; cin >> n;int q; cin >> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        M[x].push_back(i + 1);
    }
    while (q--) {
        int x, k; cin >> x >> k;
        if (M.count(x) && M[x].size() >= k) {
            cout << M[x][k - 1] << '\n';
        } else {cout << "-1\n";}
    }
}
