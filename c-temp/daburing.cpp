#include <bits/stdc++.h>
using namespace std;
long long solve() {
    long long N, X, M;
    cin >> N >> X >> M;

    vector<int> ord(M, -1); // かつて来た地点を求める
    vector<long long> rireki, syu;
    long long res = 0;
    for (int n = 0; n < N; ++n) {
        // かつて来た地点に戻ったら
        if (ord[X] != -1) {
            int p = ord[X];
            for (long long i = p; i < n; ++i) syu.push_back(rireki[i]);
            break;
        }
        ord[X] = n;
        rireki.push_back(X);
        res += X;
        X = (X * X) % M;
    }
    N -= rireki.size();

    // 戻る前に N 項目に到達した場合
    if (N == 0) return res;

    // 周期の累積和をとる
    vector<long long> sum(syu.size() + 1, 0);
    for (int i = 0; i < syu.size(); ++i) sum[i+1] = sum[i] + syu[i];

    // 周期を q 週して r あまる
    long long q = N / syu.size();
    long long r = N % syu.size();
    res += sum[syu.size()] * q + sum[r];
    return res;
}
int main() {
    cout << solve() << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,K,p,ans;
  cin>>N>>K;
  long long a[N];
  for(int i=0;i<N;i++){cin>>p;a[i]=p-1;}
  
  queue<long long> q;
  q.push(0);
  long long ord[N];long long k=0;
  for(int i=0;i<N;i++){ord[i]=0;}
  while(q.size()){
    long long tq=q.front();q.pop();
    if(ord[tq]!=0){
      long long roop=k-ord[tq];
      long long rp=(K-ord[tq])%roop;//cout<<roop<<" "<<rp<<endl;
      queue<long long> q2;q2.push(tq);long long tr=q2.front();
      while(rp>0){
        //cout<<tr<<" "<<rp<<endl;
        q2.pop();
        q2.push(a[tr]);tr=q2.front();
        rp--;
      }
      ans=tr;break;
    }
    else{
      ord[tq]=k;
      q.push(a[tq]);
    }
    k++;if(k>K){ans=tq;break;}
  }
  cout<<ans+1<<endl;
}