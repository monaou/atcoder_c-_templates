// not S-V
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, M, cur,ans;
  cin >> N >> M;
  long long dp[1<<N], a[M], b[M], c;
  for(int j=0;j<1<<N;j++){
    dp[j]=1<<30;
  }
  dp[0]=0;
  for(int i=0;i<M;i++){
    cin>>a[i]>>b[i];
    cur=0;
    for(int j=0;j<b[i];j++){
      cin>>c;c--;
      cur |= 1<<c;
    }
    for(int j=0;j<1<<N;j++){
      dp[j|cur]=min(dp[j|cur], dp[j]+a[i]);
      //cout<<dp[j|cur]<<endl;
    }
    //cout<<i<<" "<<cur<<" "<<dp[cur]<<endl;
  }
  ans=-1;
  if(dp[(1<<N)-1]!=1<<30){ans=dp[(1<<N)-1];}
  cout<<ans<<endl;
}