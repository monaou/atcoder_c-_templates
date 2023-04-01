#include <bits/stdc++.h>
using namespace std;
signed main(){
	lli n;
	cin>>n;
	map<string,lli> ans;
	for(lli i=0;i<n;i++){
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		ans[s]++;
	}
	lli sum = 0;
	for(auto e:ans){
		lli tmp = e.second*(e.second-1)/2;
		sum += tmp;
	}
	cout<<sum<<endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    for(ll i = 1; ; i++) if(stoll(to_string(i) + to_string(i)) > N){
        cout << i - 1 << endl;
        return 0;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    bool ok = true;
    map<char,char> ma, ima;
    for (int i = 0; i < S.size(); ++i) {
        char s = S[i], t = T[i];
        if (ma.count(s)) if (ma[s] != t) ok = false;
        if (ima.count(t)) if (ima[t] != s) ok = false;
        ma[s] = t; ima[t] = s;
    }
    if (ok) puts("Yes");
    else puts("No");
}