#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll dx[4] = {1, 0}, dy[4] = {0, 1};
int main(){
  ll H, W, ans, cnt;
  cin >> H >> W;
  vector<string> S(H);
  for(string &s : S){cin >> s;}
  queue<P> q;
  ll cnts[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cnts[i][j]=10000;
    }
  }
  cnts[0][0]=0;
  if (S[0][0]=='#'){cnts[0][0]++;}
  q.push(P(0,0));
  while(q.size()){
    ll nowX = q.front().first;ll nowY = q.front().second;
    q.pop();
    for(int i=0;i<2;i++){
      ll nextX=nowX+dx[i];ll nextY=nowY+dy[i];
      if (0<=nextX && nextX<H && 0<=nextY && nextY<W) {
        //cout<<nowX<<" "<<nowY<<" "<<nextX<<" "<<nextY<<" "<<cnts[nextX][nextY]<<" "<<cnts[nowX][nowY]<<endl;
        if (cnts[nowX][nowY] < cnts[nextX][nextY]) {
          cnts[nextX][nextY] = cnts[nowX][nowY];
          if (S[nowX][nowY]!='#'&&S[nextX][nextY]=='#'){cnts[nextX][nextY]++;}
          q.push(P(nextX, nextY));
        }
      }
    }
  }
  ans=cnts[H-1][W-1];
  cout<<ans<<endl;
}