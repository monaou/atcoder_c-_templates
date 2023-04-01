#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
// 最長増加部分列の長さを求める
int LIS(const vector<long long> &a) {
    int N = (int)a.size();
    vector<long long> dp(N, INF);
    for (int i = 0; i < N; ++i) {
        // dp[k] >= a[i] となる最小のイテレータを見つける
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        // そこを a[i] で書き換える
        *it = a[i];
    }
    // dp[k] < INF となる最大の k に対して k+1 が答え
    // それは dp[k] >= INF となる最小の k に一致する
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
int main() {
    int N; cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    cout << LIS(a) << endl;
}
//LIS + Segtree
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid UNITY;
    int SIZE_R;
    vector<Monoid> dat;
    
    SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity) { init(n); }
    void init(int n) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, UNITY);
    }
    
    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[k*2], dat[k*2+1]);
    }
    
    /* update a, a is 0-indexed */
    void update(int a, const Monoid &v) {
        int k = a + SIZE_R;
        dat[k] = v;
        while (k >>= 1) dat[k] = F(dat[k*2], dat[k*2+1]);
    }
    
    /* get [a, b), a and b are 0-indexed */
    Monoid get(int a, int b) {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);
        }                                                                                                              
        return F(vleft, vright);
    }
    inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }
    
    /* debug */
    void print() {
        for (int i = 0; i < SIZE_R; ++i) {
            cout << (*this)[i];
            if (i != SIZE_R-1) cout << ",";
        }
        cout << endl;
    }
};

int solve(int N, int K) {
    const int MAX = 510000;
    auto func = [&](int a, int b) { return max(a, b); };
    SegTree<int> seg(MAX, func, 0);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        int left = max(0, a - K);
        int right = min(MAX, a + K + 1);
        int val = seg.get(left, right);
        seg.update(a, val + 1);
    }
    return seg.get(0, MAX);
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << solve(N, K) << endl;
}