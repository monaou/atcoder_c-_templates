#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,p,ans;
  cin>>N;
  long long a[N];
  multiset<long long> v;ans=0;
  for(long long i=0;i<N;i++){
    cin>>a[i];
    auto iter = v.lower_bound(a[i]);
    if(iter == v.begin()){
      ans++;
    }else{
      v.erase(--iter);
    }
    v.insert(a[i]);
  }
  cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N,cur;
  cin>>N;
  ll a[N],b[N],sum[N][N];
  set<ll> v;
  for(int i=0;i<N;i++){cin>>a[i];}
  for(int i=0;i<N;i++){cin>>b[i];}
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      sum[i][j]=a[i]^b[j];
    }
    v.insert(sum[i][0]);
  }
  for(int i=0;i<N;i++){
    set<ll> k;
    for(int j=0;j<N;j++){
      auto it = v.find(sum[i][j]);
      if(it != v.end()){k.insert(sum[i][j]);}
    }
    v=k;
  }
  ll ans = v.size();cout<<ans<<endl;
  for(auto itr = v.begin(); itr != v.end(); ++itr) {
    std::cout << *itr << "\n";      // イテレータの指す先のデータを表示
  }
}