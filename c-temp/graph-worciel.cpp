#include <iostream>
using namespace std;
int N, M;
int dist[401][401];
void _main() {
    cin >> N >> M;

    rep(i, 0, N) rep(j, 0, N) dist[i][j] = inf;
    rep(i, 0, N) dist[i][i] = 0;

    rep(i, 0, M) {
        int a, b, c;
        cin >> a >> b >> c;a--; b--;
        dist[a][b] = c;
    }

    ll ans = 0;
    rep(k, 0, N) {
        rep(i, 0, N) rep(j, 0, N) chmin(dist[i][j], dist[i][k] + dist[k][j]);
        rep(i, 0, N) rep(j, 0, N) if (dist[i][j] < inf) ans += dist[i][j];
    }
    cout << ans << endl;
}
