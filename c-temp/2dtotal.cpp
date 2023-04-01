#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N,K,ans,MAX_N;MAX_N=5011;
  cin>>N>>K;
  ll a[N],b[N],s[MAX_N][MAX_N],t[MAX_N][MAX_N];
  for(int i=0;i<MAX_N;i++){for(int j=0;j<MAX_N;j++){s[i][j]=0;t[i][j]=0;}}
  for(int i=0;i<N;i++){cin>>a[i]>>b[i];s[a[i]][b[i]]++;}
  for(int i=0;i<MAX_N;i++){
    for(int j=0;j<MAX_N;j++){
      t[i+1][j+1]=t[i][j+1]+t[i+1][j]-t[i][j]+s[i][j];
    }
  }
  ans=0;K++;
  for(int i=0;i<MAX_N-K;i++){
    for(int j=0;j<MAX_N-K;j++){
      ans=max(ans,t[i+K][j+K]-t[i][j+K]-t[i+K][j]+t[i][j]);
      //if(i<=31&&j<=31&&i>=20&&j>=0){cout<<i<<" "<<j<<" "<<t[i][j]<<endl;}
    }
  }
  cout<<ans<<endl;
}