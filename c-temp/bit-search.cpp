#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,ans,cnt,f;
  cin>>N;
  int a[N],x[N][N],y[N][N];
  for(int i=0;i<N;i++){
    cin>>a[i];
    for(int j=0;j<a[i];j++){
      cin>>x[i][j]>>y[i][j];x[i][j]--;
  	}
  }
  ans=0;
  for(int bit=0;bit < 1<<N;bit++){
    cnt=0;f=0;
    for(int i=0;i < N;i++){
      if(bit>>i&1){
        cnt++;
        for(int j=0;j < a[i];j++){
          if(y[i][j]==1){
            if(!(bit>>x[i][j]&1)){f=-1;}
          }else{
            if(bit>>x[i][j]&1){f=-1;}
          }
        }
      }
    }
    if(f==0){ans=max(ans,cnt);}
  }
  cout<<ans<<endl;
}