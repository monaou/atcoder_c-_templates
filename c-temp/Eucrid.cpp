#include <iostream>
#include <vector>
using namespace std;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    long long res = A[0];
    for (int i = 0; i < N; ++i) {
        res = GCD(res, A[i]);
    }
    cout << res << endl;
}
// modint使用
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
     
long long solve() {
    long long N, S, K;
    cin >> N >> S >> K;
    long long g = gcd(N, K);
    if (S % g) return -1;
    N /= g, S /= g, K /= g;
    modint::set_mod(N);
    modint res = -modint(S) / K;
    return res.val();
}

int main(){
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}