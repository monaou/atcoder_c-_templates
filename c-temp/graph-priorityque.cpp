#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,Q;
vector<priority_queue<int, vector<int>, greater<int>>> G;
void dfs(int n, int p, vector<long long> &res) {
  res[n]++;
  int s;s=0;
  while(G[n].size()){
    int e;e=G[n].top();G[n].pop();
    if (e == p ||res[e]>0) continue;
    cout<<n+1<<" ";dfs(e,n,res);s++;
  }
  cout<<n+1<<" ";
}
int main() {
  cin >> N;
  int a[N],b[N];
  vector<long long> px(N);
  G.assign(N, priority_queue<int, vector<int>, greater<int>>());
  for (int i=0;i<N-1;i++){
    cin >> a[i] >> b[i];a[i]--;b[i]--;
    G[a[i]].push(b[i]);G[b[i]].push(a[i]);
  }
  for (int i=0;i<N;i++){px[i]=0;}
  dfs(0,-1,px);
}