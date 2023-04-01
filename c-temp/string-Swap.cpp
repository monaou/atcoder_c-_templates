#include <bits/stdc++.h>
using namespace std;
int N; string S; int Q;
void _main() {
    cin >> N >> S >> Q;
    string pre = S.substr(0, N);
    string post = S.substr(N);
    rep(_, 0, Q) {
        int T, A, B; cin >> T >> A >> B;
        if (T == 1) {
            A--; B--;
            if (B < N) swap(pre[A], pre[B]);
            else if (N <= A) swap(post[A - N], post[B - N]);
            else swap(pre[A], post[B - N]);
        }
        else {
            swap(pre, post);
        }
    }
    cout << pre << post << endl;
}