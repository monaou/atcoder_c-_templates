#include <bits/stdc++.h>
using namespace std;

int N,M; //頂点と辺の数
vector<vector<int>> G; //グラフ
vector<int> h; //入次数
vector<int> l_depth; //最大経路長
vector<int> ans; //答えを格納

void input(){
  cin>>N>>M;
  G.resize(N);
  h.resize(N, 0); //入次数0初期化
  int f,t;
  for(int i=0; i<M; i++){
    cin>>f>>t;
    //f--; t--; //1始まりで辺の情報を入れるならデクリメントする
    G[f].push_back(t); //fからtに行ける
    h[t]++; //tの入次数を増やす
  }
}

void topoBFS(){   
  queue<int> unchecked;
  for(int i=0; i<N; i++){
    if(h[i]==0){
      unchecked.push(i); //入次数が0の頂点をキューに入れる
      l_depth[i] = 0; //そのような頂点は深さが0
    }
  }
  while(!unchecked.empty()){
    int current = unchecked.front();
    unchecked.pop();
    ans.push_back(current); //キューから取り出したらすぐソート後のリストに加える

    for(int next: G[current]){ //「行ける」頂点について
      h[next]--; //入次数を減らす
      l_depth[next] = max(l_depth[next], l_depth[current]+1); //最長経路
      if(h[next]==0){ //入次数0になったらキューに追加
        unchecked.push(next);
      }
    }
  }
}

int main(){
  input();

  l_depth.resize(N, -1);
  topoBFS();

  bool isDAG = ans.size()==N; //DAGであるかどうか
  if(isDAG){
    for(int x: ans){
      cout<<x<<endl; //1始まりで出力するときはx+1とする
    }
  }else{
    cout<<"DAGではない"<<endl;
  }
}