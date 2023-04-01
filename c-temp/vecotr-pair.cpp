#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
    ll N, C;
    cin >> N >> C;
    vector<pair<ll, ll>> event;
    for(ll i = 0; i < N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        event.emplace_back(a - 1, c);
        event.emplace_back(b, -c);
    }
    sort(event.begin(), event.end());
    ll ans = 0, fee = 0, t = 0;
    for(auto [x, y] : event){
        if(x != t){
            ans += min(C, fee) * (x - t);
            t = x;
        }
        fee += y;
    }
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<vector<int>> G(N);
  vector<pair<int,int>> vp;
  for(int i=1;i<N;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    vp.emplace_back(a,b);
  }

  int K=0;
  map<pair<int,int>,int> I;
  vector<int> cs(N,0); // color of edge between its parent

  vector<int> used(N,0);
  queue<int> que;
  used[0]=1;
  que.emplace(0);
  while(!que.empty()){
    int v=que.front();que.pop();
    if(K<(int)G[v].size()) K=G[v].size();
    int cur=1;
    for(int u:G[v]){
      if(used[u]) continue;
      if(cur==cs[v]) cur++;
      cs[u]=I[make_pair(u,v)]=I[make_pair(v,u)]=cur++;
      used[u]=1;
      que.emplace(u);
    }
  }

  cout<<K<<endl;
  for(auto p:vp) cout<<I[p]<<endl;
  return 0;
}
