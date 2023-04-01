#include <bits/stdc++.h>
using namespace std;

using Edge = pair<int,int>;
using Graph = vector<vector<Edge>>;
int N, M;
Graph G;
void rec(int v, int c, vector<int> &res) {
    res[v] = c;
    for (auto e : G[v]) {
        if (res[e.first] != -1) continue;
        if (e.second == c) rec(e.first, (e.second+1)%N, res);
        else rec(e.first, e.second, res);
    }
}

int main() {
    cin >> N >> M;
    G.assign(N, vector<Edge>());
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;--u, --v, --c;
        G[u].emplace_back(v, c);G[v].emplace_back(u, c);
    }
    vector<int> res(N, -1);
    rec(0, 0, res);
    for (auto v : res) cout << v+1 << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,Q;
vector<vector<int>> G;
void dfs(int n, int p, vector<long long> &res) {
  if(p!=-1){res[n]+=res[p];}
  for(auto e : G[n]){
    if (e == p) continue;
    dfs(e,n,res);
  }
}
int main() {
  cin >> N >> Q;
  int a[N],b[N],p[Q],x[Q];
  vector<long long> px(N);
  G.assign(N, vector<int>());
  for (int i=0;i<N-1;i++){
    cin >> a[i] >> b[i];a[i]--;b[i]--;
    G[a[i]].push_back(b[i]);G[b[i]].push_back(a[i]);
  }
  for (int i=0;i<N;i++){px[i]=0;}
  for (int i=0;i<Q;i++){
    cin >> p[i] >> x[i];
    p[i]--;
    px[p[i]]+=x[i];
  }
  dfs(0,-1,px);
  for(int i=0;i<N;i++){cout<<px[i]<<" ";}
}