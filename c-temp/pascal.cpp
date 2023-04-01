#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    const ll MOD = 1e9 + 7;
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> comb(n + 1, vector<ll>(n + 1));
    for (int i = 0; i <= n; ++i) comb[i][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            (comb[i][j] += comb[i - 1][j - 1] + comb[i - 1][j]) %= MOD;
    for (ll i = 1; i <= k; ++i)
        cout << (comb[k - 1][i - 1] * comb[n - k + 1][i]) % MOD << '\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1000000007;
ll prod(ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans *= b;
        ans %= MOD;
        e >>= 1;
        b *= b;
        b %= MOD;
    }
    return ans;
}
vector<ll> fact(2010), factinv(2010);
ll comb(int n, int k) {
    ll ans = fact[n];
    ans = ans * factinv[n-k] % MOD;
    ans = ans * factinv[k] % MOD;
    return ans;
}
void pp() {
    fact[0] = 1;
    for (int i=1;i<=2000;i++) fact[i] = fact[i-1]*i % MOD;
    factinv[0] = 1;
    factinv[1] = 1;
    for (int i=2;i<=2000;i++) factinv[i] = prod(fact[i],MOD-2);
}
int main(void) {
    int N, K;
    cin >> N >> K;
    pp();
    for (int i=1;i<=K;i++) {
        if (i > N-K+1) {
            cout << 0 << endl;
        } else {
            ll ans = comb(N-K+1,N-K-i+1);
            ans = ans * comb(K-1,K-i) % MOD;
            cout << ans << endl;
        }
    }
}
