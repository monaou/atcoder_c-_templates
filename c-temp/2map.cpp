#include <bits/stdc++.h>
using namespace std;

int main() {
  long long H,W,D,cur,next,total,cost;
  cin>>H>>W>>D;
  long long a[H][W],da[100001];
  map<int, map<int, int>> ans;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>a[i][j];da[a[i][j]]=i*400+j;
    }
  }
  
  long long px=0;
  for(int p=1;p<=D;p++){
    cur=da[p];total=0;
    for(int pp=p;pp<=H*W;pp+=D){
      next=da[pp];
      cost=abs(next%400-cur%400)+abs(next/400-cur/400);
      total+=cost;
      ans[p][pp]=total;
      cur=next;
     // cout<<p<<" "<<pp<<" "<<ans[p][pp]<<endl;
    }
  }
  long long Q;
  cin>>Q;
  long long l[Q],r[Q];
  for(int i=0;i<Q;i++){
    cin>>l[i]>>r[i];
    px=r[i]%D;if(px==0){px=D;}
    cout<<ans[px][r[i]]-ans[px][l[i]]<<endl;
  }
}