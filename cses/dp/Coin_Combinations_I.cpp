#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define N 105
#define X 1000005
 
ll coin[N];
ll dp[X];
 
set<ll> coin_s;
 
int main(){
    ll n;
    ll sum;
    scanf("%lld %lld",&n,&sum);
    int i,j;
    for(i = 0; i < n; i++){
        scanf("%lld",&coin[i]);
        coin_s.insert(coin[i]);
    }
    for(i = 1; i <= sum; i++){
        if(coin_s.count(i)) dp[i] = 1;
        for(j = 0; j < n; j++){
            if(i - coin[j] < 0) continue;
            if(dp[i - coin[j]]){
                dp[i] += dp[i - coin[j]] % MOD;
                dp[i] %= MOD;
            }   
        }
        dp[i] % MOD;
    }
    printf("%lld\n",dp[sum]);
    return 0;
}