#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#include <atcoder/dsu>

int main(){
  ll N, M;
  cin >> N >> M;
  atcoder::dsu uf(N+1);
  vector<tuple<ll,ll,ll>> event;
  for(ll i = 0; i < M; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    event.emplace_back(c,a,b);
  }
  sort(event.begin(), event.end());
  ll ans = 0;
  for(auto [c,x,y] : event){
    if(c<=0){uf.merge(x,y);}
    else{
      if(uf.same(x,y)){ans+=c;}
      else{uf.merge(x,y);}
    }
  }
  cout << ans << endl;
}