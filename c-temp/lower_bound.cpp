#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main() {
  long long N, D, A, cur, dif, ans;
  cin >> N >> D >> A;
  vector<pair<ll, ll>> event;
  long long x,h,cnt[N],xi[N];
  for(int i=0;i<N;i++){
    cnt[i]=0;
    cin>>x>>h;
    event.emplace_back(x,h);
    xi[i]=x;
  }
  sort(event.begin(), event.end());
  sort(xi, xi+N);
  ans=0;dif=0;
  for(long long i=0;i<N;i++){
    if(event[i].second-dif>0){
      cur = (event[i].second-dif)/A;
      if((event[i].second-dif)%A!=0){cur++;}
      ans+=cur;
      cnt[i]+=cur*A;
      auto iter = lower_bound(xi, xi + N, xi[i]+2*D+1) - xi;
      //cout<<iter<<endl;
      cnt[iter-1]-=cur*A;
    }
    //cout<<i<<" "<<cur<<" "<<dif<<" "<<ans<<endl;
    dif+=cnt[i];
  }
  cout<<ans<<endl;
}