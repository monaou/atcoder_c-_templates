#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p;
#define MOD 1000000007
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> c(4e5);
	UnionFind uf(4e5);
	vector<int> A(N);
	vector<int> B(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
		uf.unite(A[i], B[i]);
	}
	int ans = 0;
	for(int i = 0; i < N; i++) {
		int l = uf.find(A[i]);
		c[l]++;
	}
	for(int i = 0; i < 4e5; i++) {
		if(uf.find(i) == i) {
			ans += uf.sizes[i] - 1;
			if(c[i] >= uf.sizes[i]) ans++;
		}
	}
	cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#include <atcoder/dsu>

int main(){
  ll N, M;
  cin >> N >> M;
  atcoder::dsu uf(N+1);
  vector<tuple<ll,ll,ll>> event;
  for(ll i = 0; i < M; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    event.emplace_back(c,a,b);
  }
  sort(event.begin(), event.end());
  ll ans = 0;
  for(auto [c,x,y] : event){
    if(c<=0){uf.merge(x,y);}
    else{
      if(uf.same(x,y)){ans+=c;}
      else{uf.merge(x,y);}
    }
  }
  cout << ans << endl;
}