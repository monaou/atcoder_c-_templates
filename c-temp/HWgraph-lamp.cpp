#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353; //10^9+7:合同式の法

int main(){
  ll H, W, p, ans, i, j,last;
  cin >> H >> W;
  vector<string> S(H);
  for(string &s : S) {cin >> s;}
  ans=1;i=0;j=0;last=0;
  while(true){
    p=-1;
    ll now=i;j=0;
    while(now>=0){
      //cout<<now<<" "<<j<<endl;
      if(now>=H||j>=W){j++;now--;continue;}
      if(now==H-1&&j==W-1){last=-1;}
      if(p==-1){
        if(S[now][j]=='R'){p=1;}
        else if(S[now][j]=='B'){p=2;}
      }else{
        if(S[now][j]=='R'&&p==2){p=0;}
        else if(S[now][j]=='B'&&p==1){p=0;}
      }
      if(last==-1){break;}
      j++;now--;
    }
    if(p==-1){
      ans*=2;
      ans=ans%MOD;
    }else if(p==0){
      ans=0;break;
    }
    if(last==-1){break;}
      //cout<<i<<" "<<ans<<endl;
    i++;
  }
  cout<<ans<<endl;
}