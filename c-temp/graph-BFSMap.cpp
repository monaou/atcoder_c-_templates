#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;cin >> N;
    vector<vector<int>> G(N);    // 隣接リスト表現によるグラフ
    vector<pair<int, int>> E_in; // 辺の入力の順番を保持する
    for (int i=1;i<N;i++) {
        int a, b;cin >> a >> b;a--;b--;
        G[a].emplace_back(b);G[b].emplace_back(a);
        pair<int, int> p = make_pair(a, b);
        E_in.emplace_back(p);
    }

    queue<int> que;
    vector<int> used(N, 0);
    vector<int> parent(N, 0); // 親との間にある辺の数値
    int max_color = 0;
    map<pair<int, int>, int> E_num; // 辺への割り振った番号を保持する
    que.emplace(0); // 最初のものは何でも良いので0からにする
    used[0] = 1;
    while (que.size() != 0) {
        int state = que.front(); // 現在の状態

        que.pop();
        int color_num = 0;
        for (auto next : G[state]) {
            if (used[next] != 1) {
                color_num++;
                used[next] = 1;
                if (color_num == parent[state]) {color_num++;}
                pair<int, int> p = make_pair(state, next);
                E_num[p] = color_num; //辺彩色
                parent[next] = color_num;
                que.push(next); //次の状態をqueueへ格納
            }
        }
        max_color = max(max_color, color_num);
    }
    cout << max_color << "\n";
    for (auto i : E_in) {cout << E_num[i] << "\n";}
}