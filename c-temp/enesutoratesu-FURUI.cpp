#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1100000;

int main() {
    long long N;cin>>N;
    long long prime[MAX_N];
    bool is_prime[MAX_N+1];
    long long p =0;
    for(int i=0;i<N;i++)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=N;i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=2*i;j<=N;j+=i)is_prime[j]=false;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

// 素因数分解
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}