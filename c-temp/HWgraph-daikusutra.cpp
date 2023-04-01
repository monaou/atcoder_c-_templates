#include<bits/stdc++.h>
using namespace std;
int N, M, X, Y;
int A[101010], B[101010], T[101010], K[101010];
vector<pair<int, pair<int,int>>> E[101010];
bool chmin(int& a, int b){ if(a > b){ a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
int vis[101010];
int D[101010];
int dijk() {
    for(int i=0;i<N;i++){D[i] = 1<<30;}
    for(int i=0;i<N;i++){vis[i] = 0;}
    min_priority_queue<pair<int, int>> que;
    D[X] = 0;
    que.push({ 0, X });
    while (!que.empty()) {
        auto q = que.top(); que.pop();
        int cst = q.first;
        int cu = q.second;

        if (cu == Y) return D[Y];
        if (vis[cu]) continue;
        vis[cu] = 1;

        for(auto p:E[cu]) {
            int to = p.first;
            int T = p.second.first;
            int K = p.second.second;

            ll cst2 = (cst + K - 1) / K * K + T;
            if (chmin(D[to], cst2)) que.push({ D[to], to });
        }
    }
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N >> M >> X >> Y;
    X--; Y--;
    for(int i=0;i<M;i++){
        cin >> A[i] >> B[i] >> T[i] >> K[i];
        A[i]--; B[i]--;
        E[A[i]].push_back({ B[i], {T[i], K[i]} });
        E[B[i]].push_back({ A[i], {T[i], K[i]} });
    }
    int ans = dijk();
    cout << ans << endl;
}