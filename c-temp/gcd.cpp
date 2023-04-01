#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
   if(b==0) return a;
   if(a==0) return b;
   if(a>=b)  return gcd(a%b,b);
   return  gcd(a,b%a);
}
#define maxn 55
ll n;
ll a[maxn];
ll b[maxn];
void tc(){
    cin >> n;
    for(ll i = 1;i<=n;i++) cin >> a[i] >> b[i];
    vector<ll> va,vb;
    for(ll i = 1;i*i<=a[1];i++){
        if(a[1]%i==0){
            va.push_back(i);
            if(i*i!=a[1]) va.push_back(a[1]/i);
        }
    }
    for(ll i = 1;i*i<=b[1];i++){
        if(b[1]%i==0){
            vb.push_back(i);
            if(i*i!=b[1]) vb.push_back(b[1]/i);
        }
    }
    ll ans = 0;
    for(ll x : va){
        for(ll y : vb){
            for(ll i = 2;i<=n;i++){
                if((a[i]%x==0&&b[i]%y==0)||(a[i]%y==0&&b[i]%x==0)) continue;
                goto lol;
            }
            ans = max(x*y/(gcd(x,y)),ans);
            lol:;
        }
    }
    cout<<ans<<endl;
}
int main(){
	int t; t = 1;
	while(t--){
		tc();
	}
	return 0;
}
