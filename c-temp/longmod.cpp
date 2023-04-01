#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll mod_pow(ll x, ll n){
  ll res = 1;
  while(n>0){
    if(n & 1)res=res*x%mod;
    x=x*x%mod;
    n >>= 1;
  }
  return res;
}

int main(){
    ll n;
    cin>>n;
    ll ans=powmod(10,n)-powmod(9,n)-powmod(9,n)+powmod(8,n);
    ans%=mod;
    ans=(ans+mod)%mod;
    cout<<ans<<"\n";
}